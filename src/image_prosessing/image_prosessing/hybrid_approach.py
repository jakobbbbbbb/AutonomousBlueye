import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from robot_interfaces.msg import CannyChainPos
import cv2
import numpy as np
import math

class BlueyeImage(Node):
    def __init__(self):
        super().__init__("blueye_image")
        self.subscription = self.create_subscription(Image, "/camera", self.image_callback, 10)
        self.publisher = self.create_publisher(CannyChainPos, "/CannyChainPos", 10)
        self.bridge = CvBridge()

        # Optical Flow Initialization
        self.prev_gray = None
        self.prev_features = None

    def image_callback(self, msg):
        frame = self.bridge.imgmsg_to_cv2(msg, "bgr8")

        # ** 1. Adaptive Contrast Enhancement (CLAHE) **
        lab = cv2.cvtColor(frame, cv2.COLOR_BGR2LAB)
        l, a, b = cv2.split(lab)
        clahe = cv2.createCLAHE(clipLimit=3.0, tileGridSize=(8,8))
        l = clahe.apply(l)
        lab = cv2.merge((l, a, b))
        enhanced = cv2.cvtColor(lab, cv2.COLOR_LAB2BGR)

        # ** 2. Convert to Grayscale **
        gray = cv2.cvtColor(enhanced, cv2.COLOR_BGR2GRAY)

        # ** 3. Optical Flow-based Marine Snow Removal **
        static_mask = np.ones_like(gray, dtype=np.uint8) * 255  # Ensure 8-bit mask

        if self.prev_gray is not None:
            # Detect features in the current frame
            features = cv2.goodFeaturesToTrack(gray, maxCorners=200, qualityLevel=0.01, minDistance=10)

            if features is None or len(features) == 0:
                self.prev_features = None  # Prevent crashing if no features detected
                return  

            if self.prev_features is not None:
                # Compute Optical Flow
                new_features, status, _ = cv2.calcOpticalFlowPyrLK(self.prev_gray, gray, self.prev_features, None)

                if new_features is not None and len(new_features) == len(self.prev_features):
                    # Compute movement magnitude
                    motion = np.linalg.norm(new_features - self.prev_features, axis=1)
                    moving_points = motion > 5  # Adjust threshold for marine snow filtering

                    for i in range(len(moving_points)):
                        if moving_points[i]:
                            x, y = self.prev_features[i].ravel().astype(int)
                            if 0 <= x < gray.shape[1] and 0 <= y < gray.shape[0]:
                                static_mask[y, x] = 0  # Remove marine snow

                    # Ensure mask shape matches gray image before applying
                    if static_mask.shape != gray.shape:
                        static_mask = cv2.resize(static_mask, (gray.shape[1], gray.shape[0]))

                    gray = cv2.bitwise_and(gray, gray, mask=static_mask)

            # Update previous features for tracking
            self.prev_features = features

        # Store the current frame for the next iteration
        self.prev_gray = gray.copy()

        # ** 4. Canny Edge Detection for Mooring Line Detection **
        edges = cv2.Canny(gray, 50, 150)

        # ** 5. Hough Line Transform to detect Mooring Line **
        lines = cv2.HoughLinesP(edges, 1, np.pi/180, 50, minLineLength=100, maxLineGap=50)
        if lines is not None:
            for line in lines:
                x1, y1, x2, y2 = line[0]
                cv2.line(frame, (x1, y1), (x2, y2), (0, 255, 0), 2)

        # Show Results
        cv2.imshow('Hybrid Approach', frame)
        cv2.waitKey(1)

def main(args=None):
    rclpy.init(args=args)
    blueye_image = BlueyeImage()
    rclpy.spin(blueye_image)
    blueye_image.destroy_node()
    rclpy.shutdown()
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()