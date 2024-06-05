#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from robot_interfaces.msg import ChainPos, ThreshChainPos
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
        self.publisher = self.create_publisher(ThreshChainPos, "/ThreshChainPos", 10)
        self.bridge = CvBridge()

        cv2.namedWindow('Threshold', cv2.WINDOW_NORMAL)
        cv2.resizeWindow('Threshold', 800, 500)
        
        cv2.createTrackbar("Min Threshold", 'Threshold', 151, 255, nothing)
        cv2.createTrackbar("Box Size", 'Threshold', 800, 1000, nothing)

    def image_callback(self, msg):
        Threshold = self.bridge.imgmsg_to_cv2(msg, "bgr8")

        min_thresh = cv2.getTrackbarPos("Min Threshold", 'Threshold')
        box_size = cv2.getTrackbarPos("Box Size", 'Threshold')
        box_width = int(box_size * 1.6)
        box_height = box_size

        gray = cv2.cvtColor(Threshold, cv2.COLOR_BGR2GRAY)
        _, binary = cv2.threshold(gray, min_thresh, 255, cv2.THRESH_BINARY)

        kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (16, 20))
        opened = cv2.morphologyEx(binary, cv2.MORPH_OPEN, kernel)
        opened_bgr = cv2.cvtColor(opened, cv2.COLOR_GRAY2BGR)

        height, width = Threshold.shape[:2]
        top_left_x = width // 2 - box_width // 2
        top_left_y = height // 2 - box_height // 2
        bottom_right_x = top_left_x + box_width
        bottom_right_y = top_left_y + box_height

        cv2.rectangle(opened_bgr, (top_left_x, top_left_y), (bottom_right_x, bottom_right_y), (0, 0, 255), 4)

        white_pixels = np.column_stack(np.where(opened[top_left_y:bottom_right_y, top_left_x:bottom_right_x]))
        white_pixels[:, [0, 1]] = white_pixels[:, [1, 0]]
        white_pixels[:, 0] += top_left_x
        white_pixels[:, 1] += top_left_y

        if white_pixels.size > 0:
            [vx, vy, x0, y0] = cv2.fitLine(white_pixels, cv2.DIST_L2, 0, 0.01, 0.01)
            angle_rad = math.atan2(vx, vy)
            angle_deg = math.degrees(angle_rad)

            if angle_deg > 90:
                angle_deg = 180 - angle_deg

            mid_point_x, mid_point_y = int(x0), int(y0)
            centered_x = mid_point_x - width // 2
            centered_y = (height // 2) - mid_point_y

            cv2.line(opened_bgr, (int(x0 - vx * 1000), int(y0 - vy * 1000)), (int(x0 + vx * 1000), int(y0 + vy * 1000)), (0, 255, 0), 2)
            cv2.circle(opened_bgr, (mid_point_x, mid_point_y), 5, (255, 0, 0), -1)

            # New code to calculate the average width of the line
            row_white_pixel_counts = np.sum(opened[top_left_y:bottom_right_y, top_left_x:bottom_right_x] == 255, axis=1)
            average_width = np.mean(row_white_pixel_counts)
            width_text = f"Width: {average_width:.2f} pixels"

            chain_pos_msg = ThreshChainPos()
            chain_pos_msg.data = [float(centered_x), float(centered_y), float(angle_deg), float(average_width)]
            self.publisher.publish(chain_pos_msg)

            cv2.putText(opened_bgr, f"Angle: {angle_deg:.2f} degrees", (10, 60), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
            cv2.putText(opened_bgr, f"Coords(X,Y): ({centered_x}, {centered_y})", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
            cv2.putText(opened_bgr, width_text, (10, 90), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)

        cv2.imshow('Threshold', opened_bgr)
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
