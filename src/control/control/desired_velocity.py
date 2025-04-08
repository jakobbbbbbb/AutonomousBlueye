import rclpy
from rclpy.node import Node
from robot_interfaces.msg import DesiredVelocity, ThreshChainPos, CannyChainPos, YoloChainPose
from bboxes_ex_msgs.msg import BoundingBoxes
import cv2
import numpy as np
import threading
from geometry_msgs.msg import Quaternion
from std_msgs.msg import Float32
import csv
import os
import time

def nothing(x):
    pass

class ChainPosController(Node):
    def __init__(self):
        super().__init__('chain_pos_controller')
        
        # Publishers
        self.vel_publisher = self.create_publisher(DesiredVelocity, '/desired_velocity', 10)
        self.desired_width_publisher = self.create_publisher(Float32, '/desired_width', 10)
        self.frame_brightness_pub = self.create_publisher(Float32, '/frame_brightness', 10)

        # Subscribers
        self.current_subscription = None  # Initialized as None to handle the zero output state.
        self.current_topic = 'ZERO_OUTPUT'  # No topic is initially selected.
        self.desired_vel = DesiredVelocity()
        self.bbox_subscriber = self.create_subscription(BoundingBoxes, 'yolov5/bounding_boxes', self.bbox_callback, 10)

        # Initializations
        self.last_normalized_mid_x = 0
        self.current_depth = 0.0
        self.reached_target_depth = False
        self.angle_rad = 0.0
        self.bounding_boxes = None
        self.transition_detected = False
        self.awaiting_cvi = False
        self.awaiting_ascent_confirmation = False

        # Failsafe initialization
        self.line_lost_time = None
        self.failsafe_triggered = False
        self.failsafe_timeout = 20

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

        # Adding mooring line angle
        self.line_angle = self.create_subscription(
            Float32,
            '/line_angle',
            self.line_angle_callback,
            10
        )
        
        self.surge_gain = 1.0
        self.sway_gain = 1.0
        self.heave_gain = 1.0
        self.yaw_gain = 1.0
        self.start_gui()


    def write_header(self):
            """ LOG data """
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
        self.surge_gain = cv2.getTrackbarPos("Surge Gain", 'Gain') / 10.0
        self.sway_gain = cv2.getTrackbarPos("Sway Gain", 'Gain') / 10.0
        self.heave_gain = cv2.getTrackbarPos("Heave Gain", 'Gain') / 10.0   
        self.yaw_gain = cv2.getTrackbarPos("Yaw Gain", 'Gain') / 10.0
        new_width = cv2.getTrackbarPos("Desired Line Width", 'Gain') * 10
        new_depth = cv2.getTrackbarPos("Depth Rating", 'Gain')

        # Check if CVI is acknowledged
        if self.awaiting_cvi and new_width != self.desired_width:
            self.awaiting_cvi = False
            self.awaiting_ascent_confirmation = True
            self.get_logger().info("CVI acknowledged. Press 'a' to begin ascent.")

        self.desired_width = new_width
        self.desired_depth = new_depth
        width_msg = Float32()
        width_msg.data = float(self.desired_width)
        self.publish_desired_width(width_msg)


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

            cv2.imshow('Gain', canvas)
            key = cv2.waitKey(50)
            if key == 27:  # ESC
                break
            elif key == ord('a') and self.awaiting_ascent_confirmation:
                self.awaiting_ascent_confirmation = False
                self.reached_target_depth = True
                self.get_logger().info("User confirmed ascent. Ascending...")

    def chain_pos_callback(self, msg):
        # Line following control
        surge, sway, yaw, heave = self.line_control(msg)

        self.publish_velocity(surge, sway, yaw, heave)


    def publish_velocity(self, surge, sway, yaw, heave):
        self.desired_vel.surge = surge
        self.desired_vel.sway = sway
        self.desired_vel.heave = heave
        self.desired_vel.yaw = yaw
        self.vel_publisher.publish(self.desired_vel)

        # Log PID-data to CSV-fil
        current_time = self.get_clock().now().to_msg().sec
        depth = self.current_depth
        yaw_angle = self.pose["yaw"] if hasattr(self, "pose") else None

        with open(self.log_file, 'a', newline='') as file:
            writer = csv.writer(file)
            writer.writerow([current_time, surge, sway, heave, yaw, depth, yaw_angle, self.desired_depth])

    # Supplementary functions
    def line_control(self, msg):
        # Directly use the gain attributes
        normalized_mid_x = (msg.data[0] / 960)
        width = msg.data[3]
        width_threshhold = max(self.desired_width, 1)  # Prevent divide-by-zero   
        desired_depth = self.desired_depth
        current_depth = self.current_depth # This is the depth the ROV will stop and reverse inspection at
        # Set default values
        surge = 0.0
        sway = 0.0
        heave = 0.0
        yaw = 0.0
        
        # Update last known position if the object is visible
        if width > 20:  # Assuming 20 is the threshold below which the object is considered out of view
            self.line_lost_time = None
            self.failsafe_triggered = False
            self.last_normalized_mid_x = normalized_mid_x
            sway = normalized_mid_x * self.sway_gain
            surge = (1 - width / width_threshhold) * self.surge_gain if width <= width_threshhold else -((width - width_threshhold) / 200.0) * self.surge_gain
            yaw = self.yaw_gain * normalized_mid_x
            if not self.reached_target_depth:
                heave = self.heave_gain * np.sin(np.abs(self.angle_rad))
                if current_depth >= desired_depth:
                    self.reached_target_depth = True
                    self.get_logger().info(f"Reached desired depth {current_depth:.2f}m → Switching to ascent.")
            else:
                heave = -self.heave_gain * np.sin(np.abs(self.angle_rad))
            heave = np.clip(heave, -1.0, 1.0)
        else:
            now = time.time()
            if self.line_lost_time is None:
                self.line_lost_time = now
            
            if (now - self.line_lost_time) > self.failsafe_timeout and not self.failsafe_triggered:
                self.failsafe_triggered = True
                self.failsafe_mode()
        return surge, sway, yaw, heave

    def failsafe_mode(self):
        self.get_logger().warn("Failsafe Activated: Aborting mission")
        surge = 0.0
        sway = 0.0
        # If the object is out of view, set yaw based on the last known side
        yaw = 0.1 if self.last_normalized_mid_x > 0 else -0.1
        heave = -0.3 # starting ascent
        self.publish_velocity(surge, sway, yaw, heave)


    # Callback functions
    def depth_callback(self, msg):
        self.current_depth = msg.w  # Extract depth from the subscription

    def line_angle_callback(self, msg):
        self.angle_rad = msg.data

    def bbox_callback(self, msg):
        self.bounding_boxes = msg.bounding_boxes
        for box in self.bounding_boxes:
            if box.Class == "TransitionPiece":
                if not self.transition_detected:
                    self.transition_detected = True
                    self.awaiting_cvi = True
                    self.get_logger().info("Shackle detected. Perform CVI by adjusting 'Desired Line Width'.")
                    # Optionally pause motion
                    self.publish_velocity(0.0, 0.0, 0.0, 0.0)

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