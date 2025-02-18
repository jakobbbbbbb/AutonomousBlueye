#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from robot_interfaces.msg import ChainPos  # Import the custom message
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np  # Make sure this line is present
import math  # Make sure to import math for the atan2 function
from sklearn.linear_model import LinearRegression


class BlueyeImage(Node):

    def __init__(self):
        super().__init__("blueye_image")
        self.image_subscriber = self.create_subscription(
            Image,
            "/camera",
            self.image_callback,
            1)
        self.bridge = CvBridge()

        # Publisher for the Canny edge image
        self.canny_image_publisher = self.create_publisher(
            Image,
            "blueye/front_camera_canny",
            10)
        
        self.chain_pos_publisher = self.create_publisher(
            ChainPos,
            'ChainPos',
            10)
        
        self.update_rate = 10.0  # Update rate in Hz
        self.timer = self.create_timer(1.0 / self.update_rate, self.timer_callback)
        self.latest_image = None

    def image_callback(self, msg):
        image = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
        
        # Convert the image to grayscale
        grayscale_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

        # Apply Gaussian blur to reduce details
        blurred_image = cv2.GaussianBlur(grayscale_image, (5, 5), 0)

        # Apply Canny edge detection
        canny_image = cv2.Canny(blurred_image, 100, 200)

        # Calculate the center of the image
        center_x, center_y = canny_image.shape[1] // 2, canny_image.shape[0] // 2
        
        # Define the 200x200 pixel box, moved 100 pixels up
        start_x, start_y = center_x - 100, center_y - 100 - 100  # Moving up by 100 pixels
        end_x, end_y = center_x + 100, center_y + 100 - 100  # Moving up by 100 pixels
        box_canny_image = canny_image[start_y:end_y, start_x:end_x]

        # Find all white pixels within the moved 200x200 box
        y_coords, x_coords = np.where(box_canny_image == 255)

        # Adjust coordinates to the full image scale
        x_coords += start_x
        y_coords += start_y

        # Convert the Canny image to BGR for colored drawing
        fitted_line_image = cv2.cvtColor(canny_image, cv2.COLOR_GRAY2BGR)

        # Draw the moved 200x200 pixel box in red
        cv2.rectangle(fitted_line_image, (start_x, start_y), (end_x, end_y), (0, 0, 255), 2)

        # Check if there are enough points to fit a line
        if len(x_coords) >= 2:
            # Fit a line using polynomial fitting, 1st order for a straight line
            z = np.polyfit(x_coords, y_coords, 1)
            p = np.poly1d(z)

            # Calculate the angle of the line
            slope = z[0]
            angle_radians = math.atan2(slope, 1)
            angle_degrees = math.degrees(angle_radians)
            adjusted_angle = angle_degrees - 270
            if adjusted_angle < 0:
                adjusted_angle += 360

            # Create line points
            x_line = np.array([min(x_coords), max(x_coords)])
            y_line = p(x_line).astype(int)
            cv2.line(fitted_line_image, (x_line[0], y_line[0]), (x_line[1], y_line[1]), (0, 255, 0), 2)


            # Calculate and draw the midpoint of the line
            mid_x = int((x_line[0] + x_line[1]) / 2)
            mid_y = int((y_line[0] + y_line[1]) / 2)
            cv2.circle(fitted_line_image, (mid_x, mid_y), 5, (0, 0, 255), -1)  # Red dot

            # Create the chain_pos matrix and publish it
            chain_pos_msg = ChainPos()
            chain_pos_msg.data = [float(mid_x), float(mid_y), float(adjusted_angle)]
            self.chain_pos_publisher.publish(chain_pos_msg)
            print(f"chain_pos: {chain_pos_msg.data}")


            angle_text = f"Angle: {adjusted_angle:.2f}°"
            coord_text = f"Midpoint: ({mid_x}, {mid_y})"
            cv2.putText(fitted_line_image, angle_text, (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
            cv2.putText(fitted_line_image, coord_text, (10, 60), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)


        self.latest_image = canny_image

        # Convert the Canny image with the line and moved box to ROS Image message and publish
        canny_line_image_msg = self.bridge.cv2_to_imgmsg(fitted_line_image, 'bgr8')
        self.canny_image_publisher.publish(canny_line_image_msg)

        cv2.imshow("Canny Image with Line and Moved Box Displayer", fitted_line_image)
        cv2.waitKey(1)


    def timer_callback(self):
        # Additional processing in the main loop if needed
        pass

def main():
    rclpy.init()
    blueye_img = BlueyeImage()
    rclpy.spin(blueye_img)
    blueye_img.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
