#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from bboxes_ex_msgs.msg import BoundingBoxes
from robot_interfaces.msg import YoloCannyChainPose
from experimental.Guided_Filter import guided_filter
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
        self.YoloChainPose_publisher = self.create_publisher(YoloCannyChainPose, 'YoloCannyChainPose', 10)
        cv2.namedWindow('Yolov5 Image', cv2.WINDOW_NORMAL)
        cv2.createTrackbar("Min Threshold", "Yolov5 Image", 42, 255, lambda x: None)
        cv2.createTrackbar("Max Threshold", "Yolov5 Image", 78, 255, lambda x: None)

    def bbox_callback(self, msg):
        self.bounding_boxes = msg.bounding_boxes

    def image_callback(self, msg):
        image = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
        image_center_x, image_center_y = image.shape[1] // 2, image.shape[0] // 2

        # Collecting thresholds and box size from GUI
        lower_thresh = cv2.getTrackbarPos("Lower Threshold", 'Canny Edge Detection')
        upper_thresh = cv2.getTrackbarPos("Upper Threshold", 'Canny Edge Detection')

        if self.bounding_boxes:
            for box in self.bounding_boxes:
                if box.class_id in ["MooringLine"]:
                    frame = image[box.ymin:box.ymax, box.xmin:box.xmax]
                    # Converting to YCbCr
                    YCrCb = cv2.cvtColor(frame, cv2.COLOR_BGR2YCrCb)
                    # Splitting YCrCb image components
                    Y, Cr, Cb = cv2.split(YCrCb)

                    # Applying CLAHE
                    clahe = cv2.createCLAHE(clipLimit = 1.5, tileGridSize = (8, 8))
                    Y_clahe = clahe.apply(Y)

                    # Applying guided filtering to luminance (Y) component
                    Y_guided = guided_filter(Y_clahe, radius = 32, eps = 0.6)

                    # Remove small spots (marine snow) using kernel
                    kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (10, 10))
                    Y_eroded = cv2.erode(Y_guided, kernel, iterations = 1)

                    # Merging filtered component with unfiltered components
                    Y_cleaned = cv2.morphologyEx(Y_eroded, cv2.MORPH_OPEN, kernel)

                    # Applying Canny Edge Detection
                    edges = cv2.Canny(Y_cleaned, lower_thresh, upper_thresh)
                    # Converting to bgr format
                    edges_bgr = cv2.cvtColor(edges, cv2.COLOR_GRAY2BGR)
                    
                    row_white_pixel_counts = np.sum(edges == 255, axis=1)
                    average_width = np.mean(row_white_pixel_counts) if row_white_pixel_counts.size > 0 else 0

                    # Check for sufficient points to fit line
                    y_coords, x_coords = np.where(edges == 255)
                    if len(x_coords) > 0 and len(y_coords) > 0:
                        points = np.column_stack((x_coords, y_coords))
                        [vx, vy, x0, y0] = cv2.fitLine(points, cv2.DIST_L2, 0, 0.01, 0.01)
                        angle_deg = math.degrees(math.atan2(vy, vx)) - 90

                        # Calculate points for line drawing
                        length = max(1000, int(math.sqrt(image.shape[0]**2 + image.shape[1]**2)))
                        point1 = (int(x0 - vx * length), int(y0 - vy * length))
                        point2 = (int(x0 + vx * length), int(y0 + vy * length))

                        # Convert points to global image coordinates
                        global_point1 = (point1[0]+box.xmin, point1[1]+box.ymin)
                        global_point2 = (point2[0]+box.xmin, point2[1]+box.ymin)

                        # Draw the line over the Canny edges
                        cv2.line(image, global_point1, global_point2, (0, 255, 0), 2)

                        # Optionally redraw the bounding box for visibility
                        cv2.rectangle(image, (box.xmin, box.ymin), (box.xmax, box.ymax), (0, 255, 0), 2)

                        # Prepare and publish the pose message
                        mid_x = int(x0 + box.xmin)
                        mid_y = int(y0 + box.ymin)
                        pose_msg = YoloCannyChainPose()
                        pose_msg.mid_x = float(mid_x - image_center_x)
                        pose_msg.mid_y = float(image_center_y - mid_y)
                        pose_msg.angle_degrees = float(angle_deg)
                        self.YoloChainPose_publisher.publish(pose_msg)

                        cv2.circle(image, (mid_x, mid_y), 5, (255, 0, 0), -1)  # Draw the midpoint circle
                        cv2.putText(image, f'Midpoint: ({mid_x}, {mid_y})', (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
                        cv2.putText(image, f'Angle: {angle_deg:.2f} degrees', (10, 50), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
                        cv2.putText(image, f'Width: {average_width:.2f} pixels', (10, 110), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 2)

        cv2.imshow("Yolov5 Image", image)
        cv2.waitKey(1)

def main():
    rclpy.init()
    blueye_img = BlueyeImage()
    rclpy.spin(blueye_img)
    blueye_img.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
