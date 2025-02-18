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

        # Initialize OpenCV window and trackbars
        cv2.namedWindow("Fitted Line Image", cv2.WINDOW_NORMAL)
        cv2.createTrackbar("Min Threshold", "Fitted Line Image", 100, 255, self.nothing)
        cv2.createTrackbar("Max Threshold", "Fitted Line Image", 200, 255, self.nothing)

        # Add a trackbar for Y Offset
        cv2.createTrackbar("Y Offset", "Fitted Line Image", 255, 510, self.nothing)  # 155 is the starting value (100 offset + 255 to make it positive)
        cv2.createTrackbar("X Offset", "Fitted Line Image", 255, 510, self.nothing)  # 255 is the starting value (0 offset + 255 to make it positive)

    # Trackbar callback function
    def nothing(self, x):
        # This function is called every time a trackbar position is changed
        pass


    def image_callback(self, msg):
        image = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
        
        # Convert the image to grayscale
        grayscale_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

        # Apply Gaussian blur to reduce details
        blurred_image = cv2.GaussianBlur(grayscale_image, (5, 5), 0)

        # Read trackbar positions
        min_val = cv2.getTrackbarPos("Min Threshold", "Fitted Line Image")
        max_val = cv2.getTrackbarPos("Max Threshold", "Fitted Line Image")

        # Apply Canny edge detection with dynamic thresholds
        canny_image = cv2.Canny(blurred_image, min_val, max_val)

        # Get the y-offset from the trackbar (subtract 255 to convert back to the original range of -255 to 255)
        y_offset = cv2.getTrackbarPos("Y Offset", "Fitted Line Image") - 255
        x_offset = cv2.getTrackbarPos("X Offset", "Fitted Line Image") - 255

        # Calculate the center of the image
        center_x, center_y = canny_image.shape[1] // 2, canny_image.shape[0] // 2
        
        # Define the 200x200 pixel box, moved by y_offset and x_offset pixels
        start_x, start_y = center_x - 100 + x_offset, center_y - 100 + y_offset
        end_x, end_y = center_x + 100 + x_offset, center_y + 100 + y_offset
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

            # Draw the line in the fitted_line_image
            cv2.line(fitted_line_image, (x_line[0], y_line[0]), (x_line[1], y_line[1]), (0, 255, 0), 2)

            # Calculate and draw the midpoint of the line relative to the box center
            mid_x_box = int((x_line[0] + x_line[1]) / 2) - start_x
            mid_y_box = int((y_line[0] + y_line[1]) / 2) - start_y

            # Adjust mid_x_box and mid_y_box to make the center of the box (0,0)
            # Note: The origin (0,0) is at the center of the box, so subtract half the box width/height to adjust
            mid_x_box -= 100  # Subtract half the box width
            mid_y_box -= 100  # Subtract half the box height
            # Invert the y coordinate to match the increasing value towards up
            mid_y_box = -mid_y_box

            # Draw the red dot at the new midpoint location (re-adjust to image coordinates for drawing)
            cv2.circle(fitted_line_image, (mid_x_box + start_x + 100, -mid_y_box + start_y + 100), 5, (0, 0, 255), -1)

            # Continue with your existing code to create chain_pos_msg and publish it...
            # Adjust the published midpoint to be relative to the box with (0,0) at the center
            chain_pos_msg = ChainPos()
            chain_pos_msg.data = [float(mid_x_box), float(mid_y_box), float(adjusted_angle)]
            self.chain_pos_publisher.publish(chain_pos_msg)
            print(f"chain_pos: {chain_pos_msg.data}")


            angle_text = f"Angle: {adjusted_angle:.2f}°"
            coord_text = f"Midpoint: ({mid_x_box}, {mid_y_box})"
            cv2.putText(fitted_line_image, angle_text, (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
            cv2.putText(fitted_line_image, coord_text, (10, 60), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)


        self.latest_image = canny_image

        # Convert the Canny image with the line and moved box to ROS Image message and publish
        canny_line_image_msg = self.bridge.cv2_to_imgmsg(fitted_line_image, 'bgr8')
        self.canny_image_publisher.publish(canny_line_image_msg)

        # Resize the image before displaying
        scale_percent = 50  # percentage of original size; adjust as needed
        width = int(fitted_line_image.shape[1] * scale_percent / 100)
        height = int(fitted_line_image.shape[0] * scale_percent / 100)
        dim = (width, height)
        resized_fitted_line_image = cv2.resize(fitted_line_image, dim, interpolation=cv2.INTER_AREA)

        # cv2.imshow("Fitted Line Image", fitted_line_image)
        cv2.imshow("Fitted Line Image", resized_fitted_line_image)
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
