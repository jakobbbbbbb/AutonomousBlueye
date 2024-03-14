#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from robot_interfaces.msg import YoloChainPose  # Adjust this import based on your actual package and message structure
from bboxes_ex_msgs.msg import BoundingBoxes, BoundingBox
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
        self.latest_image = None

        # Make the "Processed Image" window resizable
        cv2.namedWindow("Yolo_canny_chain", cv2.WINDOW_NORMAL)
        cv2.createTrackbar("Min Threshold", "Yolo_canny_chain", 42, 255, lambda x: None)
        cv2.createTrackbar("Max Threshold", "Yolo_canny_chain", 78, 255, lambda x: None)

    # Declare the publisher for YoloChainPose
        self.YoloChainPose_publisher = self.create_publisher(YoloChainPose, 'YoloChainPose', 10)

    def bbox_callback(self, msg):
        self.bounding_boxes = msg.bounding_boxes

    def image_callback(self, msg):
        image = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
        image_center_x, image_center_y = image.shape[1] // 2, image.shape[0] // 2

        highest_confidence_box = None
        highest_confidence = 0.0

        # Check if self.bounding_boxes is not None before iterating
        if self.bounding_boxes:
            for box in self.bounding_boxes:
                if box.class_id in ["Chain", "Wire", "Rope"] and box.probability > highest_confidence:
                    highest_confidence = box.probability
                    highest_confidence_box = box

        if highest_confidence_box:
            # Draw the bounding box and label
            cv2.rectangle(image, (highest_confidence_box.xmin, highest_confidence_box.ymin),
                        (highest_confidence_box.xmax, highest_confidence_box.ymax), (0, 255, 0), 2)
            label = f"{highest_confidence_box.class_id}: {highest_confidence_box.probability:.2f}"
            cv2.putText(image, label, (highest_confidence_box.xmin, highest_confidence_box.ymin - 10),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)

            # Apply Gaussian blur and Canny edge detection on the ROI
            roi = image[highest_confidence_box.ymin+1:highest_confidence_box.ymax-1, highest_confidence_box.xmin+1:highest_confidence_box.xmax-1]
            blurred_roi = cv2.GaussianBlur(roi, (5, 5), 0)
            min_val = cv2.getTrackbarPos("Min Threshold", "Yolo_canny_chain")
            max_val = cv2.getTrackbarPos("Max Threshold", "Yolo_canny_chain")
            canny_roi = cv2.Canny(blurred_roi, min_val, max_val)

            # Overlay the Canny edge detection result back onto the original image
            image[highest_confidence_box.ymin+1:highest_confidence_box.ymax-1, highest_confidence_box.xmin+1:highest_confidence_box.xmax-1] = \
                cv2.cvtColor(canny_roi, cv2.COLOR_GRAY2BGR)

            # Find white pixels in the Canny ROI for line fitting
            y_coords, x_coords = np.where(canny_roi == 255)

            if len(x_coords) > 0 and len(y_coords) > 0:
                # Fit a line to these points
                z = np.polyfit(x_coords, y_coords, 1)
                p = np.poly1d(z)

                # Calculate the start and end points of the line
                x_line_start = np.min(x_coords)
                x_line_end = np.max(x_coords)
                y_line_start = int(p(x_line_start))
                y_line_end = int(p(x_line_end))

                # Draw the interpolated line
                cv2.line(image, (x_line_start + highest_confidence_box.xmin, y_line_start + highest_confidence_box.ymin),
                        (x_line_end + highest_confidence_box.xmin, y_line_end + highest_confidence_box.ymin), (255, 0, 0), 2)

                # Calculate the midpoint of the line
                mid_x = (x_line_start + x_line_end) / 2 + highest_confidence_box.xmin
                mid_y = (y_line_start + y_line_end) / 2 + highest_confidence_box.ymin
                cv2.circle(image, (int(mid_x), int(mid_y)), 5, (0, 0, 255), -1)

                # Calculate the angle of the line
                dx = x_line_end - x_line_start
                dy = y_line_end - y_line_start
                angle_radians = math.atan2(dy, dx)
                angle_degrees = math.degrees(angle_radians)

                # Calculate the bounding box's midpoint adjusted to the image center
                bbox_mid_x = (highest_confidence_box.xmin + highest_confidence_box.xmax) / 2
                bbox_mid_y = (highest_confidence_box.ymin + highest_confidence_box.ymax) / 2
                adjusted_bbox_mid_x = bbox_mid_x - image_center_x
                adjusted_bbox_mid_y = image_center_y - bbox_mid_y  # Invert Y axis to match the specified coordinate system

                # Prepare the YoloChainPose message and publish it
                pose_msg = YoloChainPose()
                pose_msg.mid_x = mid_x - image_center_x  # Adjusting the line's midpoint to the image center
                pose_msg.mid_y = image_center_y - mid_y  # Adjusting the line's midpoint to the image center
                pose_msg.angle_degrees = angle_degrees
                pose_msg.adjusted_bbox_mid_x = adjusted_bbox_mid_x
                pose_msg.adjusted_bbox_mid_y = adjusted_bbox_mid_y
                self.YoloChainPose_publisher.publish(pose_msg)

            # Adjust the bounding box midpoint relative to the image center
            adjusted_bbox_mid_x = bbox_mid_x - image_center_x
            adjusted_bbox_mid_y = image_center_y - bbox_mid_y  # Invert Y axis to match the specified coordinate system

            # Display the adjusted bounding box midpoint
            bbox_mid_text = f"BBox Mid: ({adjusted_bbox_mid_x:.2f}, {adjusted_bbox_mid_y:.2f})"
            cv2.putText(image, bbox_mid_text, (10, 90), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 2)


            # Display the midpoint coordinates and angle
            midpoint_text = f"Mid: ({mid_x}, {mid_y})"
            angle_text = f"Angle: {angle_degrees:.2f}°"
            cv2.putText(image, midpoint_text, (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 2)
            cv2.putText(image, angle_text, (10, 60), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 2)

        self.latest_image = image
        cv2.imshow("Yolo_canny_chain", image)
        cv2.waitKey(1)


def main():
    rclpy.init()
    blueye_img = BlueyeImage()
    rclpy.spin(blueye_img)
    blueye_img.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
