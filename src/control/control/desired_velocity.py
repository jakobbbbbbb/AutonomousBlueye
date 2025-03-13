import rclpy
from rclpy.node import Node
from robot_interfaces.msg import DesiredVelocity, ThreshChainPos, CannyChainPos, YoloChainPose
import cv2
import numpy as np
import threading
from geometry_msgs.msg import Quaternion
from std_msgs.msg import Float32
import csv
import os

def nothing(x):
    pass

class ChainPosController(Node):
    def __init__(self):
        super().__init__('chain_pos_controller')
        self.vel_publisher = self.create_publisher(DesiredVelocity, '/desired_velocity', 10)
        self.desired_width_publisher = self.create_publisher(Float32, '/desired_width', 10)
        self.led_publisher = self.create_publisher(Float32, '/led_brightness', 10)
        self.frame_brightness_pub = self.create_publisher(Float32, '/frame_brightness', 10)
        self.current_subscription = None  # Initialized as None to handle the zero output state.
        self.current_topic = 'ZERO_OUTPUT'  # No topic is initially selected.
        self.desired_vel = DesiredVelocity()
        self.last_normalized_mid_x = 0  # Initialize to 0, assuming the object starts centered.
        self.current_depth = 0.0
        self.reached_target_depth = False

        # Initial values for LED and frame
        self.current_brightness = 0.0 
        self.frame_brightness = 128.0 # dummy value, will be updated upon running code
        self.last_led_brightness = None

        # Logging stuff
        self.log_file = "pid_log.csv"
        self.write_header()

        

        # Adding depth from BluEye_Pose.py
        self.depth_sub = self.create_subscription(
            Quaternion,
            'BlueyePose',
            self.depth_callback,
            10
        )

        # Adding LED brightness from Blueye_LED.py
        self.led_brightness_sub = self.create_subscription(
            Float32,
            '/led_brightness',
            self.led_callback,
            10
        )

        # Adding mean frame brightness from MarineSnowRemoval.py
        self.frame_brightness_sub = self.create_subscription(
            Float32,
            '/frame_brightness',
            self.frame_brightness_callback,
            10
        )
        
        self.surge_gain = 1.0
        self.sway_gain = 1.0
        self.heave_gain = 1.0
        self.yaw_gain = 1.0
        self.start_gui()


    def write_header(self):
            """ Skriver en header til loggfilen. """
            if not os.path.exists(self.log_file):
                with open(self.log_file, 'w', newline='') as file:
                    writer = csv.writer(file)
                    writer.writerow(["Time", "Surge", "Sway", "Heave", "Yaw", "Depth", "Yaw Angle", "Desired Depth"])
    
    def switch_subscription(self, index):
        topic_options = {0: 'ZERO_OUTPUT', 1: '/CannyChainPos', 2: '/ThreshChainPos', 3: '/YoloChainPose'}
        topic = topic_options.get(index, 'ZERO_OUTPUT')  # Default to ZERO_OUTPUT if not specified.

        if topic == 'ZERO_OUTPUT':
            if self.current_subscription is not None:
                self.destroy_subscription(self.current_subscription)
                self.current_subscription = None
            # Explicitly cast 0 to float to ensure type consistency.
            self.publish_velocity(0.0, 0.0, 0.0, 0.0)
            self.current_topic = 'ZERO_OUTPUT'
        else:
            if self.current_topic == 'ZERO_OUTPUT' or self.current_subscription is None:
                # Create a new subscription if coming from ZERO_OUTPUT or if it's the initial setup.
                self.create_new_subscription(topic)
            elif self.current_topic != topic:
                self.destroy_subscription(self.current_subscription)
                self.create_new_subscription(topic)

    def create_new_subscription(self, topic):
        # Creates a new subscription based on the topic.
        if topic == '/CannyChainPos':
            self.current_subscription = self.create_subscription(CannyChainPos, topic, self.chain_pos_callback, 10)
        elif topic == '/ThreshChainPos':
            self.current_subscription = self.create_subscription(ThreshChainPos, topic, self.chain_pos_callback, 10)
        elif topic == '/YoloChainPose':
            self.current_subscription = self.create_subscription(YoloChainPose, topic, self.chain_pos_callback, 10)
        self.current_topic = topic

    def update_gains_from_trackbars(self):
        #between 0 and 2
        self.surge_gain = cv2.getTrackbarPos("Surge Gain", 'Gain') / 10.0
        self.sway_gain = cv2.getTrackbarPos("Sway Gain", 'Gain') / 10.0
        # self.heave_gain = cv2.getTrackbarPos("Heave Gain", 'Gain') / 10.0
        self.yaw_gain = cv2.getTrackbarPos("Yaw Gain", 'Gain') / 10.0
        self.desired_width = cv2.getTrackbarPos("Desired Line Width", 'Gain') * 10
        self.desired_depth = cv2.getTrackbarPos("Depth Rating", 'Gain')
        width_msg = Float32()
        width_msg.data = float(self.desired_width)
        self.publish_desired_width(width_msg)

        #Between -1 and 1
        # self.surge_gain = (cv2.getTrackbarPos("Surge Gain", 'Gain') - 10) / 10.0
        # self.sway_gain = (cv2.getTrackbarPos("Sway Gain", 'Gain') - 10) / 10.0
        self.heave_gain = cv2.getTrackbarPos("Heave Gain", 'Gain') / 10.0        
        # self.yaw_gain = (cv2.getTrackbarPos("Yaw Gain", 'Gain') - 10) / 10.0

    def start_gui(self):
        threading.Thread(target=self.setup_gui, daemon=True).start()

    def setup_gui(self):
        cv2.namedWindow('Gain', cv2.WINDOW_NORMAL)
        cv2.resizeWindow('Gain', 600, 600)

        cv2.createTrackbar("Surge Gain", 'Gain', 5, 20, nothing)
        cv2.createTrackbar("Sway Gain", 'Gain', 10, 20, nothing)
        cv2.createTrackbar("Heave Gain", 'Gain', 10, 20, nothing)
        cv2.createTrackbar("Yaw Gain", 'Gain', 10, 100, nothing)
        cv2.createTrackbar("Desired Line Width", 'Gain', 7, 10, nothing) # Set default to 70
        cv2.createTrackbar("Depth Rating", 'Gain', 50, 100, nothing) # Depthfor turnaround
        cv2.createTrackbar("Toggle Topic", 'Gain', 0, 3, lambda x: self.switch_subscription(x))

        while True:
            self.update_gains_from_trackbars()  # Update gain values based on trackbars
            canvas = np.zeros((400, 600, 3), dtype=np.uint8)
            # Increased font size from 0.7 to 1.0 and added more vertical space between lines
            font_scale = 1.0  # Larger font size for increased text size
            line_space = 40  # Increased space between lines

            # Layout offsets
            font_scale = 1.0
            line_space = 40
            start_y = 150 # Shifting all text up a bit

            # Subscriber info
            cv2.putText(canvas, f"Subscriber: {self.current_topic}", (10, start_y - line_space), cv2.FONT_HERSHEY_SIMPLEX, font_scale, (255, 255, 255), 2)

            # Depth info (Line 1)
            cv2.putText(canvas, f"Depth Now: {self.current_depth:.2f}", (10, start_y), cv2.FONT_HERSHEY_SIMPLEX, font_scale, (255, 255, 255), 2)
            cv2.putText(canvas, f"Depth Rating: {self.desired_depth}", (300, start_y), cv2.FONT_HERSHEY_SIMPLEX, font_scale, (255, 255, 255), 2)

            # Surge info (Line 2)
            cv2.putText(canvas, f"Surge: {self.desired_vel.surge:.2f}", (10, start_y + 1 * line_space), cv2.FONT_HERSHEY_SIMPLEX, font_scale, (255, 255, 255), 2)
            cv2.putText(canvas, f"Surge Gain: {self.surge_gain:.1f}", (300, start_y + 1 * line_space), cv2.FONT_HERSHEY_SIMPLEX, font_scale, (255, 255, 255), 2)

            # Sway info (Line 3)
            cv2.putText(canvas, f"Sway: {self.desired_vel.sway:.2f}", (10, start_y + 2 * line_space), cv2.FONT_HERSHEY_SIMPLEX, font_scale, (255, 255, 255), 2)
            cv2.putText(canvas, f"Sway Gain: {self.sway_gain:.1f}", (300, start_y + 2 * line_space), cv2.FONT_HERSHEY_SIMPLEX, font_scale, (255, 255, 255), 2)

            # Heave info (Line 4)
            cv2.putText(canvas, f"Heave: {self.desired_vel.heave:.2f}", (10, start_y + 3 * line_space), cv2.FONT_HERSHEY_SIMPLEX, font_scale, (255, 255, 255), 2)
            cv2.putText(canvas, f"Heave Gain: {self.heave_gain:.1f}", (300, start_y + 3 * line_space), cv2.FONT_HERSHEY_SIMPLEX, font_scale, (255, 255, 255), 2)

            # Yaw info (Line 5)
            cv2.putText(canvas, f"Yaw: {self.desired_vel.yaw:.2f}", (10, start_y + 4 * line_space), cv2.FONT_HERSHEY_SIMPLEX, font_scale, (255, 255, 255), 2)
            cv2.putText(canvas, f"Yaw Gain: {self.yaw_gain:.1f}", (300, start_y + 4 * line_space), cv2.FONT_HERSHEY_SIMPLEX, font_scale, (255, 255, 255), 2)

            cv2.putText(canvas, f"LED Brightness: {self.current_brightness:.2f}", (10, start_y + 5 * line_space),
            cv2.FONT_HERSHEY_SIMPLEX, font_scale, (0, 255, 255), 2)

            cv2.imshow('Gain', canvas)
            if cv2.waitKey(50) == 27:  # Exit on ESC
                break

    def chain_pos_callback(self, msg):
        # Directly use the gain attributes
        normalized_mid_x = (msg.data[0] / 960)
        width = msg.data[3]
        width_threshhold = max(self.desired_width, 1)  # Prevent divide-by-zero   
        desired_depth = self.desired_depth
        current_depth = self.current_depth # This is the depth the ROV will stop and reverse inspection at
        # Set default values
        surge = 0.0
        sway = 0.0
        # heave = self.heave_gain
        yaw = 0.0
        
        # Update last known position if the object is visible
        if width > 20:  # Assuming 20 is the threshold below which the object is considered out of view
            self.last_normalized_mid_x = normalized_mid_x
            sway = normalized_mid_x * self.sway_gain
            surge = (1 - width / width_threshhold) * self.surge_gain if width <= width_threshhold else -((width - width_threshhold) / 200.0) * self.surge_gain
            yaw = self.yaw_gain * normalized_mid_x
            if not self.reached_target_depth:
                heave = self.heave_gain
                if current_depth >= desired_depth:
                    self.reached_target_depth = True
                    self.get_logger().info(f"Reached desired depth {current_depth:.2f}m → Switching to ascent.")
            else:
                heave = -self.heave_gain

        else:
            # If the object is out of view, set yaw based on the last known side
            yaw = 0.1 if self.last_normalized_mid_x > 0 else -0.1
            heave = 0.0 # ROV stays put in heave if mooring line disappears

        # Adding logic for enabling LED based on pixel data
        frame_brightness = self.frame_brightness
        if frame_brightness < 100:
            brightness = 1.0
        elif frame_brightness < 130:
            brightness = 0.6
        else:
            brightness = 0.0

        if brightness != self.last_led_brightness:
            led_msg = Float32()
            led_msg.data = brightness
            self.led_publisher.publish(led_msg)
            self.last_led_brightness = brightness
       
        self.publish_velocity(surge, sway, yaw, heave)

    def publish_velocity(self, surge, sway, yaw, heave):
        self.desired_vel.surge = surge
        self.desired_vel.sway = sway
        self.desired_vel.heave = heave
        self.desired_vel.yaw = yaw
        self.vel_publisher.publish(self.desired_vel)
        
        # Log PID-data til CSV-fil
        current_time = self.get_clock().now().to_msg().sec
        depth = self.current_depth
        yaw_angle = self.pose["yaw"] if hasattr(self, "pose") else None

        with open(self.log_file, 'a', newline='') as file:
            writer = csv.writer(file)
            writer.writerow([current_time, surge, sway, heave, yaw, depth, yaw_angle, self.desired_depth])


    def depth_callback(self, msg):
        self.current_depth = msg.w  # Extract depth from the subscription

    def led_callback(self, msg):
        self.current_brightness = msg.data # Extract LED brightness from subscription

    def frame_brightness_callback(self, msg):
        self.frame_brightness = msg.data

    def publish_desired_width(self, msg): # Publish desired depth
        self.desired_width_publisher.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    controller = ChainPosController()
    rclpy.spin(controller)
    cv2.destroyAllWindows()
    controller.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()