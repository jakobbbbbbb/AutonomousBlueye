import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from robot_interfaces.msg import CannyChainPos
import cv2
import numpy as np
import math

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
        cv2.resizeWindow('Filtered', 800, 500)
        cv2.createTrackbar("Lower Threshold", 'Filtered', 30, 255, lambda x: None)
        cv2.createTrackbar("Upper Threshold", 'Filtered', 70, 255, lambda x: None)
        cv2.createTrackbar("Box Size", 'Filtered', 800, 1000, lambda x: None)

        # Improved Background Removal
        self.bg_subtractor = cv2.createBackgroundSubtractorMOG2(history=500, varThreshold=40, detectShadows=False)
        self.prev_frame = None  # Store previous frame for frame differencing

    def image_callback(self, msg):
        frame = self.bridge.imgmsg_to_cv2(msg, "bgr8")

        # Check if window is closed (Proper shutdown)
        if cv2.getWindowProperty('Filtered', cv2.WND_PROP_VISIBLE) < 1:
            rclpy.shutdown()
            return

        # Retrieve trackbar values
        lower_thresh = cv2.getTrackbarPos("Lower Threshold", 'Filtered')
        upper_thresh = cv2.getTrackbarPos("Upper Threshold", 'Filtered')
        box_size = cv2.getTrackbarPos("Box Size", 'Filtered')

        # Define ROI Box
        box_width = int(box_size * 1.6)
        box_height = box_size
        height, width = frame.shape[:2]
        top_left_x = width // 2 - box_width // 2
        top_left_y = height // 2 - box_height // 2
        bottom_right_x = top_left_x + box_width
        bottom_right_y = top_left_y + box_height

        # Convert to Grayscale
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        # Temporal filtering
        alpha = 0.1

        if self.prev_frame is None:
            self.prev_frame = gray.astype(np.float32)

        cv2.accumulateWeighted(gray, self.prev_frame, alpha)

        frame_diff = cv2.absdiff(gray, cv2.convertScaleAbs(self.prev_frame))

        # Apply Background Subtraction + Frame Differencing
        fg_mask = self.bg_subtractor.apply(gray)
        filtered = cv2.bitwise_and(frame_diff, fg_mask)

        # Morphological Opening to Reduce Noise
        kernel = np.ones((5,5), np.uint8)
        cleaned = cv2.morphologyEx(filtered, cv2.MORPH_OPEN, kernel)

        # Adaptive Thresholding (More robust to lighting)
        thresh = cv2.adaptiveThreshold(cleaned, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 11, 2)

        # Edge Detection (Canny)
        edges = cv2.Canny(thresh, lower_thresh, upper_thresh)
        edges_bgr = cv2.cvtColor(edges, cv2.COLOR_GRAY2BGR)

        # Draw ROI Box
        cv2.rectangle(edges_bgr, (top_left_x, top_left_y), (bottom_right_x, bottom_right_y), (0, 0, 255), 4)

        # Detect Line within ROI
        roi = edges[top_left_y:bottom_right_y, top_left_x:bottom_right_x]
        lines = cv2.HoughLinesP(roi, rho=1, theta=np.pi/180, threshold=50, minLineLength=100, maxLineGap=50)

        if lines is not None:
            # Select the line closest to vertical (90°)
            best_line = min(lines, key=lambda l: abs(math.degrees(math.atan2(l[0][3] - l[0][1], l[0][2] - l[0][0])) - 90))

            x1, y1, x2, y2 = best_line[0]

            # Convert ROI coordinates to full frame
            x1 += top_left_x
            x2 += top_left_x
            y1 += top_left_y
            y2 += top_left_y

            # Calculate Line Angle
            angle_rad = math.atan2(y2 - y1, x2 - x1)
            angle_deg = math.degrees(angle_rad)
            angle_deg = 90 - angle_deg  # Adjust reference frame

            # Compute Center Offset
            mid_x = (x1 + x2) // 2
            mid_y = (y1 + y2) // 2
            centered_x = mid_x - width // 2
            centered_y = (height // 2) - mid_y

            # Draw Line on Image
            cv2.line(edges_bgr, (x1, y1), (x2, y2), (0, 255, 0), 2)
            cv2.circle(edges_bgr, (mid_x, mid_y), 5, (255, 0, 0), -1)

            # Publish Line Data
            chain_pos_msg = CannyChainPos()
            chain_pos_msg.data = [float(centered_x), float(centered_y), float(angle_deg)]
            self.publisher.publish(chain_pos_msg)

            # Display Info
            cv2.putText(edges_bgr, f"Angle: {angle_deg:.2f} degrees", (10, 60), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
            cv2.putText(edges_bgr, f"Coords(X,Y): ({centered_x}, {centered_y})", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)

        # Show Result
        cv2.imshow('Filtered', edges_bgr)

        if cv2.waitKey(1) & 0xFF == ord('q'):
            rclpy.shutdown()

def main(args=None):
    rclpy.init(args=args)
    blueye_image = BlueyeImage()
    rclpy.spin(blueye_image)
    blueye_image.destroy_node()
    rclpy.shutdown()
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()