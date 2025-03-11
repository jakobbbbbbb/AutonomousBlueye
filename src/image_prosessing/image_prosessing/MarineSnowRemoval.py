import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from robot_interfaces.msg import CannyChainPos
import cv2
from experimental.Guided_Filter import guided_filter
import math
import numpy as np
from std_msgs.msg import Float32

def nothing(x):
    pass

class BlueyeImage(Node):
    def __init__(self):
        super().__init__("blueye_image")
        self.subscription = self.create_subscription(Image, "/camera", self.image_callback, 10)
        self.publisher = self.create_publisher(CannyChainPos, "/CannyChainPos", 10)
        self.bridge = CvBridge()
        self.prev_gray = None
        self.desired_width = 0
        self.desired_width_sub = self.create_subscription(
            Float32,
            '/desired_width',
            self.width_callback,
            10
        )


        # Setup OpenCV Window
        cv2.namedWindow('Canny Edge Detection', cv2.WINDOW_NORMAL)
        cv2.resizeWindow('Canny Edge Detection', 960, 600)
        # Setup extra window for comparison
        #cv2.namedWindow('Unfiltered', cv2.WINDOW_NORMAL)
        #cv2.resizeWindow('Unfiltered', 960, 600)

        # Creating trackbars for adjusting thresholds
        cv2.createTrackbar("Lower Threshold", 'Canny Edge Detection', 6, 255, nothing)
        cv2.createTrackbar("Upper Threshold", 'Canny Edge Detection', 9, 255, nothing)
        cv2.createTrackbar("Box Size", 'Canny Edge Detection', 800, 1000, lambda x: None)    

    def image_callback(self, msg):
        frame = self.bridge.imgmsg_to_cv2(msg, "bgr8")

        # Check if window is closed
        if cv2.getWindowProperty('Canny Edge Detection', cv2.WND_PROP_VISIBLE) < 1:
            rclpy.shutdown()
            return
        
        # Collecting thresholds and box size from GUI
        lower_thresh = cv2.getTrackbarPos("Lower Threshold", 'Canny Edge Detection')
        upper_thresh = cv2.getTrackbarPos("Upper Threshold", 'Canny Edge Detection')
        box_size = cv2.getTrackbarPos("Box Size", 'Canny Edge Detection')
        box_width = int(box_size * 1.6)
        box_height = box_size
           
        # Converting to YCbCr
        YCrCb = cv2.cvtColor(frame, cv2.COLOR_BGR2YCrCb)
        # Splitting YCrCb image components
        Y, Cr, Cb = cv2.split(YCrCb)
        # Applying guided filtering to luminance (Y) component
        Y_guided = guided_filter(Y, Y, radius = 32, eps = 0.1)
        # Remove small spots (marine snow)
        kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (3, 3))
        Y_eroded = cv2.erode(Y_guided, kernel, iterations = 1)
        Y_cleaned = cv2.morphologyEx(Y_eroded, cv2.MORPH_CLOSE, kernel)
        # Merging filtered component with unfiltered components


        # Applying Canny Edge Detection
        edges = cv2.Canny(Y_cleaned, lower_thresh, upper_thresh)
        # Converting to bgr format
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

        # Drawing line with desired width of mooring line
        if self.desired_width > 0:
            center_x = edges_bgr.shape[1] // 2
            center_y = edges_bgr.shape[0] - 20  # Near bottom of image
            half_width = int(self.desired_width / 2)

            start_point = (center_x - half_width, center_y)
            end_point = (center_x + half_width, center_y)

            # Draw desired width line near bottom
            cv2.line(edges_bgr, start_point, end_point, (0, 255, 0), 2)
            # Text below the existing info (Angle, Coords, Width)
            cv2.putText(edges_bgr, f"Desired Width: {self.desired_width:.0f}px",
                        (10, 120), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
            
        cv2.imshow('Canny Edge Detection', edges_bgr)
        #cv2.imshow('Unfiltered', YCrCb_bgr)
        cv2.waitKey(1)

    def width_callback(self, msg):
        self.desired_width = msg.data
        

def main(args=None):
    rclpy.init(args=args)
    blueye_image = BlueyeImage()
    rclpy.spin(blueye_image)
    blueye_image.destroy_node()
    rclpy.shutdown()
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()