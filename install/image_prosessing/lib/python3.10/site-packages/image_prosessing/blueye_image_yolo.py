#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from bboxes_ex_msgs.msg import BoundingBoxes
from robot_interfaces.msg import YoloChainPose  # Adjust this import based on your actual package and message structure
from cv_bridge import CvBridge
import cv2

class BlueyeImage(Node):
    def __init__(self):
        super().__init__("blueye_image")
        self.image_subscriber = self.create_subscription(Image, "/camera", self.image_callback, 1)
        self.bridge = CvBridge()

        self.bounding_boxes = None
        self.bbox_subscriber = self.create_subscription(BoundingBoxes, 'yolov5/bounding_boxes', self.bbox_callback, 10)
        self.YoloChainPose_publisher = self.create_publisher(YoloChainPose, 'YoloChainPose', 10)
        cv2.namedWindow('Yolov5 Image', cv2.WINDOW_NORMAL)

    def bbox_callback(self, msg):
        self.bounding_boxes = msg.bounding_boxes

    def image_callback(self, msg):
        image = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
        image_center_x, image_center_y = image.shape[1] // 2, image.shape[0] // 2
        highest_confidence_box = None
        highest_confidence = 0.0

        # Iterate over bounding boxes to find the one with the highest confidence
        if self.bounding_boxes:
            for box in self.bounding_boxes:
                if box.class_id in ["Chain", "Wire", "Rope"] and box.probability > highest_confidence:
                    highest_confidence = box.probability
                    highest_confidence_box = box

        # Draw only the box with the highest confidence
        if highest_confidence_box:
            cv2.rectangle(image, (highest_confidence_box.xmin, highest_confidence_box.ymin),
                          (highest_confidence_box.xmax, highest_confidence_box.ymax), (0, 255, 0), 2)

            # Calculate the bounding box's midpoint adjusted to the image center
            bbox_mid_x = (highest_confidence_box.xmin + highest_confidence_box.xmax) / 2
            bbox_mid_y = (highest_confidence_box.ymin + highest_confidence_box.ymax) / 2
            bbox_width = (highest_confidence_box.xmax - highest_confidence_box.xmin) / 8

            adjusted_bbox_mid_x = bbox_mid_x - image_center_x
            adjusted_bbox_mid_y = image_center_y - bbox_mid_y  # Invert Y axis to match the specified coordinate system

            pose_msg = YoloChainPose()
            pose_msg.data = [float(adjusted_bbox_mid_x), float(adjusted_bbox_mid_y), float(bbox_width), float(bbox_width)]
            self.YoloChainPose_publisher.publish(pose_msg)

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
