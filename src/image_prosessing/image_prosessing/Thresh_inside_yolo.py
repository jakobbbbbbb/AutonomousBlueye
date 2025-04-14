#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from bboxes_ex_msgs.msg import BoundingBoxes
from robot_interfaces.msg import YoloThreshChainPose
from cv_bridge import CvBridge
import cv2
import numpy as np
import math

class BlueyeImage(Node):
    def __init__(self):
        super().__init__("blueye_image")
        self.image_subscriber = self.create_subscription(Image, "/camera", self.image_callback, 1)
        self.bridge = CvBridge()
        self.bounding_boxes = None
        self.bbox_subscriber = self.create_subscription(BoundingBoxes, 'yolov5/bounding_boxes', self.bbox_callback, 10)
        self.YoloChainPose_publisher = self.create_publisher(YoloThreshChainPose, 'YoloThreshChainPose', 10)
        cv2.namedWindow('Threshold Detection', cv2.WINDOW_NORMAL)
        cv2.resizeWindow('Threshold Detection', 960, 600)
        cv2.namedWindow('Threshold inside Yolo', cv2.WINDOW_NORMAL)
        cv2.resizeWindow('Threshold inside Yolo', 960, 600)
        cv2.createTrackbar("Threshold", "Threshold inside Yolo", 190, 255, lambda x: None)  # Simple binary threshold

    def bbox_callback(self, msg):
        self.bounding_boxes = msg.bounding_boxes

    def image_callback(self, msg):
        image = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
        image_center_x, image_center_y = image.shape[1] // 2, image.shape[0] // 2

        if self.bounding_boxes:
             for box in self.bounding_boxes:
                print(f"Detected object: {box.class_id}")  # Debugging
             for box in self.bounding_boxes:
                if box.class_id in ["Chain", "Wire", "Rope"]:
                    roi = image[box.ymin:box.ymax, box.xmin:box.xmax]
                    gray_roi = cv2.cvtColor(roi, cv2.COLOR_BGR2GRAY)
                    threshold_value = cv2.getTrackbarPos("Threshold", "Threshold inside Yolo")
                    _, binary_roi = cv2.threshold(gray_roi, threshold_value, 255, cv2.THRESH_BINARY)

                    print(f"Threshold value: {threshold_value}")
                    print(f"White pixels in ROI: {np.sum(binary_roi == 255)}")


                    # Calculate the average width of the white pixels in the ROI
                    row_white_pixel_counts = np.sum(binary_roi == 255, axis=1)
                    average_width = np.mean(row_white_pixel_counts) if row_white_pixel_counts.size > 0 else 0
                    image[box.ymin:box.ymax, box.xmin:box.xmax] = cv2.cvtColor(binary_roi, cv2.COLOR_GRAY2BGR)

                    # Identify white pixels for fitLine
                    y_coords, x_coords = np.where(binary_roi == 255)
                    if len(x_coords) > 0 and len(y_coords) > 0:
                        points = np.column_stack((x_coords, y_coords))
                        [vx, vy, x0, y0] = cv2.fitLine(points, cv2.DIST_L2, 0, 0.01, 0.01)
                        angle_deg = math.degrees(math.atan2(vy, vx)) - 90

                        # Calculate line points for drawing
                        length = max(1000, int(math.sqrt(image.shape[0]**2 + image.shape[1]**2)))
                        point1 = (int(x0 - vx * length), int(y0 - vy * length))
                        point2 = (int(x0 + vx * length), int(y0 + vy * length))
                        global_point1 = (point1[0] + box.xmin, point1[1] + box.ymin)
                        global_point2 = (point2[0] + box.xmin, point2[1] + box.ymin)

                        # Draw the line over the thresholded ROI
                        cv2.line(image, global_point1, global_point2, (0, 255, 0), 2)
                        cv2.rectangle(image, (box.xmin, box.ymin), (box.xmax, box.ymax), (0, 255, 0), 2)

                        # Prepare and publish the pose message
                        mid_x_circle = int(x0 + box.xmin)
                        mid_y_circle = int(y0 + box.ymin)

                        mid_x = int(x0 + box.xmin - 960)
                        mid_y = int(540 - (y0 + box.ymin))
                        pose_msg = YoloThreshChainPose()
                        pose_msg.mid_x = float(mid_x)
                        pose_msg.mid_y = float(mid_y)
                        pose_msg.angle_degrees = float(angle_deg)
                        self.YoloChainPose_publisher.publish(pose_msg)

                        # Draw the midpoint and print values
                        cv2.circle(image, (mid_x_circle, mid_y_circle), 5, (255, 0, 0), -1)
                        cv2.putText(image, f'Midpoint: ({mid_x}, {mid_y})', (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
                        cv2.putText(image, f'Angle: {angle_deg:.2f} degrees', (10, 70), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
                        cv2.putText(image, f'Width: {average_width:.2f} pixels', (10, 110), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)

        cv2.imshow("Threshold Detection", image)
        cv2.waitKey(1)

def main():
    rclpy.init()
    blueye_img = BlueyeImage()
    rclpy.spin(blueye_img)
    blueye_img.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
