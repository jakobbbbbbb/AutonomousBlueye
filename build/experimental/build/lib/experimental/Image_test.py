#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np

class BlueyeImageWithCannySlider(Node):
    def __init__(self):
        super().__init__("blueye_image_with_canny_slider")
        self.image_subscriber = self.create_subscription(
            Image,
            "/camera",
            self.image_callback,
            1)
        self.bridge = CvBridge()

        # Create an OpenCV window and add two sliders for Canny edge detection parameters
        cv2.namedWindow("Canny Edge Detection")
        cv2.createTrackbar("Min Threshold", "Canny Edge Detection", 100, 255, self.nothing)
        cv2.createTrackbar("Max Threshold", "Canny Edge Detection", 200, 255, self.nothing)

    def nothing(self, x):
        # Callback function for trackbar, does nothing but required for trackbar
        pass

    def image_callback(self, msg):
        image = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
        
        # Convert the image to grayscale
        grayscale_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

        # Apply Gaussian blur to reduce details
        blurred_image = cv2.GaussianBlur(grayscale_image, (5, 5), 0)

        # Retrieve the current positions of the trackbars
        min_threshold = cv2.getTrackbarPos("Min Threshold", "Canny Edge Detection")
        max_threshold = cv2.getTrackbarPos("Max Threshold", "Canny Edge Detection")

        # Apply Canny edge detection using trackbar values
        canny_image = cv2.Canny(blurred_image, min_threshold, max_threshold)

        # Display the Canny edge detection result
        cv2.imshow("Canny Edge Detection", canny_image)
        cv2.waitKey(1)

def main(args=None):
    rclpy.init(args=args)
    blueye_image_with_canny_slider = BlueyeImageWithCannySlider()
    rclpy.spin(blueye_image_with_canny_slider)
    blueye_image_with_canny_slider.destroy_node()
    cv2.destroyAllWindows()  # Make sure to destroy the OpenCV window when shutting down
    rclpy.shutdown()

if __name__ == '__main__':
    main()
