import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from robot_interfaces.msg import CannyChainPos
import cv2
import argparse

# Function that forces OpenCV to update trackbars
def nothing(x):
    pass

class BlueyeImage(Node):
    def __init__(self):
        super().__init__("blueye_image")
        self.subscription = self.create_subscription(Image, "/camera", self.image_callback, 10)
        self.publisher = self.create_publisher(CannyChainPos, "/CannyChainPos", 10)
        self.bridge = CvBridge()

        # Setup OpenCV Window
        cv2.namedWindow('Filtered', cv2.WINDOW_NORMAL)
        cv2.resizeWindow('Filtered', 960, 600)
        cv2.createTrackbar("Lower Threshold", 'Filtered', 30, 255, nothing)
        cv2.createTrackbar("Upper Threshold", 'Filtered', 70, 255, nothing)
        #cv2.createTrackbar("Box Size", 'Filtered', 800, 1000, lambda x: None)

    def image_callback(self, msg):
        frame = self.bridge.imgmsg_to_cv2(msg, "bgr8")

        # Check if window is closed
        if cv2.getWindowProperty('Filtered', cv2.WND_PROP_VISIBLE) < 1:
            rclpy.shutdown()
            return
        
        # Collecting upper and lower threshold from GUI
        lower_thresh = cv2.getTrackbarPos("Lower Threshold", 'Filtered')
        upper_thresh = cv2.getTrackbarPos("Upper Threshold", 'Filtered')
        
        # Convert to grayscale
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        # Apply strong bilateral filtering (better edge preservation)
        denoised = cv2.bilateralFilter(gray, 15, 100, 100)

        # Canny Edge Detection (tuned for more detail)
        edges = cv2.Canny(denoised, lower_thresh, upper_thresh)


        # Applying morphological closing
        kernel_close = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (5, 10))
        edges = cv2.morphologyEx(edges, cv2.MORPH_CLOSE, kernel_close)

        # Removing contours/marine snow
        contours, _ = cv2.findContours(edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        for cnt in contours:
            area = cv2.contourArea(cnt)
            if area < 100:
                cv2.drawContours(edges, [cnt], -1, 0, 1)

        # Convert edges to BGR
        edges_bgr = cv2.cvtColor(edges, cv2.COLOR_GRAY2BGR)

        # Showing the frame
        cv2.imshow('Filtered', edges_bgr)

        # Capture keyboard input
        key = cv2.waitKey(1) & 0xFF

        if key == 32: # To avoid error when video is paused
            while True:
                key = cv2.waitKey(10) & 0xFF
                if key == 32:
                    break

def main(args=None):
    rclpy.init(args=args)
    blueye_image = BlueyeImage()
    rclpy.spin(blueye_image)
    blueye_image.destroy_node()
    rclpy.shutdown()
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()