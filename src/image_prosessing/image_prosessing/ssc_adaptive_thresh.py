import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from robot_interfaces.msg import CannyChainPos
import cv2
import numpy as np
import math

# Function that forces OpenCV to update trackbars
def nothing(x):
    pass

class BlueyeImage(Node):
    def __init__(self):
        super().__init__("blueye_image")
        self.subscription = self.create_subscription(Image, "/camera", self.image_callback, 10)
        #self.publisher = self.create_publisher(CannyChainPos, "/CannyChainPos", 10)

        #tilpasset yolov5
        self.publisher = self.create_publisher(Image, "/filtered_image", 10)
        self.bridge = CvBridge()
        self.prev_gray = None




        # Setup OpenCV Window
        cv2.namedWindow('Filtered', cv2.WINDOW_NORMAL)
        cv2.resizeWindow('Filtered', 960, 600)
        cv2.createTrackbar("Lower Threshold", 'Filtered', 5, 255, nothing)
        cv2.createTrackbar("Upper Threshold", 'Filtered', 20, 255, nothing)
        cv2.createTrackbar("Box Size", 'Filtered', 800, 1000, lambda x: None)

    def image_callback(self, msg):
        #frame = self.bridge.imgmsg_to_cv2(msg, "bgr8")


        # Modify the image_callback function:
        frame = self.bridge.cv2_to_imgmsg(msg, "bgr8")  # Convert processed image
        self.publisher.publish(frame)  # Publish the filtered image

        # Check if window is closed
        if cv2.getWindowProperty('Filtered', cv2.WND_PROP_VISIBLE) < 1:
            rclpy.shutdown()
            return
        
        # Collecting thresholds and box size from GUI
        lower_thresh = cv2.getTrackbarPos("Lower Threshold", 'Filtered')
        upper_thresh = cv2.getTrackbarPos("Upper Threshold", 'Filtered')
        box_size = cv2.getTrackbarPos("Box Size", 'Filtered')
        box_width = int(box_size * 1.6)
        box_height = box_size
        
        # Convert to grayscale
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        # Apply strong bilateral filtering (for edge conservation)
        denoised = cv2.bilateralFilter(gray, 20, 100, 100)

        # Canny Edge Detection (tuned from GUI input)
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

        height, width = frame.shape[:2]
        top_left_x = width // 2 - box_width // 2
        top_left_y = height // 2 - box_height // 2
        bottom_right_x = top_left_x + box_width
        bottom_right_y = top_left_y + box_height

        # Drawing rectangle / focus area
        cv2.rectangle(edges_bgr, (top_left_x, top_left_y), (bottom_right_x, bottom_right_y), (0, 0, 255), 4)

        # Find white pixels within the box in the edge-detected image
        white_pixels = np.column_stack(np.where(edges[top_left_y:bottom_right_y, top_left_x:bottom_right_x]))
        if white_pixels.size > 0:
            white_pixels[:, [0, 1]] = white_pixels[:, [1, 0]]  # Swap columns to get (x, y) coordinates
            white_pixels[:, 0] += top_left_x
            white_pixels[:, 1] += top_left_y

            [vx, vy, x0, y0] = cv2.fitLine(white_pixels, cv2.DIST_L2, 0, 0.01, 0.01)
            angle_rad = math.atan2(vy, vx)  # Note the order of vy and vx
            angle_deg = math.degrees(angle_rad)
            angle_deg += 90  # Offset by 90 degrees

            if angle_deg > 90:
                angle_deg = 180 - angle_deg

            mid_point_x, mid_point_y = int(x0), int(y0)
            centered_x = mid_point_x - width // 2
            centered_y = (height // 2) - mid_point_y

            cv2.line(edges_bgr, (int(x0 - vx * 1000), int(y0 - vy * 1000)), (int(x0 + vx * 1000), int(y0 + vy * 1000)), (0, 255, 0), 8)
            cv2.circle(edges_bgr, (mid_point_x, mid_point_y), 5, (255, 0, 0), -1)

            # New code to calculate the average width of the line
            row_white_pixel_counts = np.sum(edges[top_left_y:bottom_right_y, top_left_x:bottom_right_x] == 255, axis=1)
            average_width = np.mean(row_white_pixel_counts) * 10
            width_text = f"Width: {average_width:.2f} pixels"

            chain_pos_msg = CannyChainPos()
            chain_pos_msg.data = [float(centered_x), float(centered_y), float(angle_deg), float(average_width)]
            self.publisher.publish(chain_pos_msg)

            cv2.putText(edges_bgr, f"Angle: {angle_deg:.2f} degrees", (10, 60), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
            cv2.putText(edges_bgr, f"Coords(X,Y): ({centered_x}, {centered_y})", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
            cv2.putText(edges_bgr, width_text, (10, 90), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)


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