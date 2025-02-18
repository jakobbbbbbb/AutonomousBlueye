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
        self.bbox_subscriber = self.create_subscription(BoundingBoxes, 'yolov5/bounding_boxes', self.bbox_callback, 10)
        self.YoloChainPose_publisher = self.create_publisher(YoloChainPose, 'YoloChainPose', 10)
        self.bridge = CvBridge()

        cv2.namedWindow('Yolo_canny_chain', cv2.WINDOW_NORMAL)
        cv2.createTrackbar("Min Threshold", 'Yolo_canny_chain', 42, 255, nothing)
        cv2.createTrackbar("Max Threshold", 'Yolo_canny_chain', 78, 255, nothing)

        self.bounding_boxes = None

    def bbox_callback(self, msg):
        self.bounding_boxes = msg.bounding_boxes

    def image_callback(self, msg):
        image = self.bridge.imgmsg_to_cv2(msg, 'bgr8')

        if self.bounding_boxes:
            for box in self.bounding_boxes:
                if box.class_id in ["Chain", "Wire", "Rope"]:
                    roi = image[box.ymin:box.ymax, box.xmin:box.xmax]
                    blurred_roi = cv2.GaussianBlur(roi, (5, 5), 0)
                    min_val = cv2.getTrackbarPos("Min Threshold", "Yolo_canny_chain")
                    max_val = cv2.getTrackbarPos("Max Threshold", "Yolo_canny_chain")
                    canny_roi = cv2.Canny(blurred_roi, min_val, max_val)

                    y_coords, x_coords = np.where(canny_roi == 255)
                    if len(x_coords) > 0 and len(y_coords) > 0:
                        points = np.vstack((x_coords, y_coords)).astype(np.float32).T
                        [vx, vy, x0, y0] = cv2.fitLine(points, cv2.DIST_L2, 0, 0.01, 0.01)

                        # Calculate line points for the entire width of the bounding box
                        slope = vy / vx
                        intercept = y0 - (slope * x0)
                        y1 = int(slope * 0 + intercept)
                        y2 = int(slope * (canny_roi.shape[1] - 1) + intercept)

                        # Draw the interpolated line on the original image
                        cv2.line(image, (box.xmin, box.ymin + y1), (box.xmax, box.ymin + y2), (255, 0, 0), 2)

                        # Prepare and publish the YoloChainPose message
                        pose_msg = YoloChainPose()
                        pose_msg.header = msg.header  # Use the header from the incoming image message
                        pose_msg.xmin = box.xmin
                        pose_msg.ymin = box.ymin + y1
                        pose_msg.xmax = box.xmax
                        pose_msg.ymax = box.ymin + y2
                        self.YoloChainPose_publisher.publish(pose_msg)

        cv2.imshow("Yolo_canny_chain", image)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            rclpy.shutdown()

def nothing(x):
    pass

def main(args=None):
    rclpy.init(args=args)
    blueye_image = BlueyeImage()
    rclpy.spin(blueye_image)
    blueye_image.destroy_node()
    rclpy.shutdown()
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()
