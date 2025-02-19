import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from robot_interfaces.msg import CannyChainPos
import cv2 as cv
import argparse


def nothing(x):
    pass

class BlueyeImage(Node):
    def __init__(self):
        super().__init__("blueye_image")
        self.subscription = self.create_subscription(Image, "/camera", self.image_callback, 10)
        self.publisher = self.create_publisher(CannyChainPos, "/CannyChainPos", 10)
        self.bridge = CvBridge()

        # Setup OpenCV Window
        cv.namedWindow('Filtered', cv.WINDOW_NORMAL)
        cv.resizeWindow('Filtered', 800, 500)
        cv.createTrackbar("Lower Threshold", 'Filtered', 30, 255, lambda x: None)
        cv.createTrackbar("Upper Threshold", 'Filtered', 70, 255, lambda x: None)
        cv.createTrackbar("Box Size", 'Filtered', 800, 1000, lambda x: None)

    def image_callback(self, msg):
        Canny = self.bridge.imgmsg_to_cv(msg, "bgr8")

        # Check if window is closed (Proper shutdown)
        if cv.getWindowProperty('Filtered', cv.WND_PROP_VISIBLE) < 1:
            rclpy.shutdown()
            return
        
        lower_thresh = cv.getTrackbarPos("Lower Threshold", "Canny")
        
        # Applying grayscale
        gray = cv.cvtColor(Canny, cv.COLOR_BGR2GRAY)
        
        # Showing the frame
        cv.imshow('Canny', gray)

def main(args=None):
    rclpy.init(args=args)
    blueye_image = BlueyeImage()
    rclpy.spin(blueye_image)
    blueye_image.destroy_node()
    rclpy.shutdown()
    cv.destroyAllWindows()

if __name__ == '__main__':
    main()