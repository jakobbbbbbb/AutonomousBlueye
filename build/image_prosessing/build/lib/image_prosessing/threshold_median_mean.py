#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from robot_interfaces.msg import MedianChainPos
from cv_bridge import CvBridge
import cv2
import numpy as np
import math

def nothing(x):
    pass

class BlueyeImage(Node):
    def __init__(self):
        super().__init__("blueye_image")
        self.subscription = self.create_subscription(Image, "/camera", self.image_callback, 10)
        self.publisher = self.create_publisher(MedianChainPos, "/MedianChainPos", 10)
        self.bridge = CvBridge()

        cv2.namedWindow('Adaptive Threshold', cv2.WINDOW_NORMAL)
        cv2.resizeWindow('Adaptive Threshold', 800, 500)
        cv2.createTrackbar("Box Size", 'Adaptive Threshold', 930, 1000, nothing)
        cv2.createTrackbar("Median Kernel Size", 'Adaptive Threshold', 16, 20, nothing)

    def image_callback(self, msg):
        try:
            frame = self.bridge.imgmsg_to_cv2(msg, "bgr8")

            gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
            median_kernel_size = cv2.getTrackbarPos("Median Kernel Size", 'Adaptive Threshold')
            median_kernel_size = max(1, median_kernel_size)
            if median_kernel_size % 2 == 0: median_kernel_size += 1
            gray_blur = cv2.medianBlur(gray, median_kernel_size)

            adaptive_mean = cv2.adaptiveThreshold(gray_blur, 255, cv2.ADAPTIVE_THRESH_MEAN_C, cv2.THRESH_BINARY, 19, 2)
            median_mean = cv2.medianBlur(adaptive_mean, median_kernel_size)
            inverted_median_mean = cv2.bitwise_not(median_mean)

            height, width = frame.shape[:2]
            box_size = cv2.getTrackbarPos("Box Size", 'Adaptive Threshold')
            box_width = int(box_size * 1.6)
            box_height = box_size
            top_left_x = width // 2 - box_width // 2
            top_left_y = height // 2 - box_height // 2
            bottom_right_x = top_left_x + box_width
            bottom_right_y = top_left_y + box_height

            inverted_median_mean_bgr = cv2.cvtColor(inverted_median_mean, cv2.COLOR_GRAY2BGR)
            cv2.rectangle(inverted_median_mean_bgr, (top_left_x, top_left_y), (bottom_right_x, bottom_right_y), (0, 0, 255), 4)

            region_of_interest = inverted_median_mean[top_left_y:bottom_right_y, top_left_x:bottom_right_x]
            white_pixels = np.column_stack(np.where(region_of_interest == 255))
            white_pixels[:, [0, 1]] = white_pixels[:, [1, 0]]
            white_pixels[:, 0] += top_left_x
            white_pixels[:, 1] += top_left_y

            if white_pixels.size > 0:
                [vx, vy, x0, y0] = cv2.fitLine(white_pixels, cv2.DIST_L2, 0, 0.01, 0.01)
                angle_rad = math.atan2(vx, vy)
                angle_deg = math.degrees(angle_rad)

                if angle_deg > 90: angle_deg = 180 - angle_deg

                mid_point_x, mid_point_y = int(x0), int(y0)
                centered_x = mid_point_x - width // 2
                centered_y = (height // 2) - mid_point_y

                cv2.line(inverted_median_mean_bgr, (int(x0 - vx * 1000), int(y0 - vy * 1000)), (int(x0 + vx * 1000), int(y0 + vy * 1000)), (0, 255, 0), 2)
                cv2.circle(inverted_median_mean_bgr, (mid_point_x, mid_point_y), 5, (255, 0, 0), -1)

                row_white_pixel_counts = np.sum(region_of_interest == 255, axis=1)
                average_width = np.mean(row_white_pixel_counts)
                width_text = f"Width: {average_width:.2f} pixels"

                chain_pos_msg = MedianChainPos()
                chain_pos_msg.data = [float(centered_x), float(centered_y), float(angle_deg), float(average_width)]
                self.publisher.publish(chain_pos_msg)

                cv2.putText(inverted_median_mean_bgr, f"Angle: {angle_deg:.2f} degrees", (10, 60), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
                cv2.putText(inverted_median_mean_bgr, f"Coords(X,Y): ({centered_x}, {centered_y})", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
                cv2.putText(inverted_median_mean_bgr, width_text, (10, 90), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)

            cv2.imshow('Adaptive Threshold', inverted_median_mean_bgr)
            if cv2.waitKey(1) & 0xFF == ord('q'): rclpy.shutdown()

        except Exception as e:
            self.get_logger().error(f"Image callback failed: {e}")

def main(args=None):
    rclpy.init(args=args)
    blueye_image = BlueyeImage()
    rclpy.spin(blueye_image)
    blueye_image.destroy_node()
    rclpy.shutdown()
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()
