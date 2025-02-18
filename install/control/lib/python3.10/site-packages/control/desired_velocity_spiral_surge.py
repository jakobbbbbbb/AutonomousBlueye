import rclpy
from rclpy.node import Node
from robot_interfaces.msg import DesiredVelocity, ThreshChainPos, CannyChainPos, YoloChainPose
import cv2
import math
import time
import numpy as np
import threading

def nothing(x):
    pass

class ChainPosController(Node):
    def __init__(self):
        super().__init__('chain_pos_controller')
        self.vel_publisher = self.create_publisher(DesiredVelocity, '/desired_velocity', 10)
        self.current_subscription = None  # Initialized as None to handle the zero output state.
        self.current_topic = 'ZERO_OUTPUT'  # No topic is initially selected.
        self.desired_vel = DesiredVelocity()
        self.last_normalized_mid_x = 0  # Initialize to 0, assuming the object starts centered.

        
        self.surge_gain = 1.0
        self.sway_gain = 1.0
        self.heave_gain = 1.0
        self.yaw_gain = 1.0
        self.start_gui()

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
        # self.sway_gain = cv2.getTrackbarPos("Sway Gain", 'Gain') / 10.0
        # self.heave_gain = cv2.getTrackbarPos("Heave Gain", 'Gain') / 10.0
        self.yaw_gain = cv2.getTrackbarPos("Yaw Gain", 'Gain') / 10.0

        #Between -1 and 1
        # self.surge_gain = (cv2.getTrackbarPos("Surge Gain", 'Gain') - 10) / 10.0
        self.sway_gain = (cv2.getTrackbarPos("Sway Gain", 'Gain') - 10) / 10.0
        self.heave_gain = (cv2.getTrackbarPos("Heave Gain", 'Gain') - 10) / 10.0
        # self.yaw_gain = (cv2.getTrackbarPos("Yaw Gain", 'Gain') - 10) / 10.0

    def start_gui(self):
        threading.Thread(target=self.setup_gui, daemon=True).start()

    def setup_gui(self):
        cv2.namedWindow('Gain', cv2.WINDOW_NORMAL)
        cv2.resizeWindow('Gain', 600, 600)

        cv2.createTrackbar("Surge Gain", 'Gain', 5, 20, nothing)
        cv2.createTrackbar("Sway Gain", 'Gain', 10, 20, nothing)
        cv2.createTrackbar("Heave Gain", 'Gain', 10, 20, nothing)
        cv2.createTrackbar("Yaw Gain", 'Gain', 10, 20, nothing)
        cv2.createTrackbar("Toggle Topic", 'Gain', 0, 3, lambda x: self.switch_subscription(x))

        while True:
            self.update_gains_from_trackbars()  # Update gain values based on trackbars
            canvas = np.zeros((400, 600, 3), dtype=np.uint8)
            # Increased font size from 0.7 to 1.0 and added more vertical space between lines
            font_scale = 1.0  # Larger font size for increased text size
            line_space = 40  # Increased space between lines

            cv2.putText(canvas, f"Surge: {self.desired_vel.surge:.2f}", (10, 250), cv2.FONT_HERSHEY_SIMPLEX, font_scale, (255, 255, 255), 2)
            cv2.putText(canvas, f"Surge Gain: {self.surge_gain:.1f}", (300, 250), cv2.FONT_HERSHEY_SIMPLEX, font_scale, (255, 255, 255), 2)

            cv2.putText(canvas, f"Sway: {self.desired_vel.sway:.2f}", (10, 250 + line_space), cv2.FONT_HERSHEY_SIMPLEX, font_scale, (255, 255, 255), 2)
            cv2.putText(canvas, f"Sway Gain: {self.sway_gain:.1f}", (300, 250 + line_space), cv2.FONT_HERSHEY_SIMPLEX, font_scale, (255, 255, 255), 2)

            cv2.putText(canvas, f"Heave: {self.desired_vel.heave:.2f}", (10, 250 + 2 * line_space), cv2.FONT_HERSHEY_SIMPLEX, font_scale, (255, 255, 255), 2)
            cv2.putText(canvas, f"Heave Gain: {self.heave_gain:.1f}", (300, 250 + 2 * line_space), cv2.FONT_HERSHEY_SIMPLEX, font_scale, (255, 255, 255), 2)

            cv2.putText(canvas, f"Yaw: {self.desired_vel.yaw:.2f}", (10, 250 + 3 * line_space), cv2.FONT_HERSHEY_SIMPLEX, font_scale, (255, 255, 255), 2)
            cv2.putText(canvas, f"Yaw Gain: {self.yaw_gain:.1f}", (300, 250 + 3 * line_space), cv2.FONT_HERSHEY_SIMPLEX, font_scale, (255, 255, 255), 2)

            cv2.putText(canvas, f"Subscriber: {self.current_topic}", (10, 220 - line_space), cv2.FONT_HERSHEY_SIMPLEX, font_scale, (255, 255, 255), 2)  # Position adjusted for consistency
            cv2.imshow('Gain', canvas)
            if cv2.waitKey(50) == 27:  # Exit on ESC
                break

    def chain_pos_callback(self, msg):
        # Directly use the gain attributes
        normalized_mid_x = (msg.data[0] / 960)
        width = msg.data[3]
        width_threshhold = 70.0

        
        # Set default values
        surge = 0.0
        sway = 0.0
        heave = self.heave_gain
        yaw = 0.0
        
        # Update last known position if the object is visible
        if width > 20:  # Assuming 20 is the threshold below which the object is considered out of view
            self.last_normalized_mid_x = normalized_mid_x
            surge = (1 - width / width_threshhold) * self.surge_gain if width <= width_threshhold else -((width - width_threshhold) / 200.0) * self.surge_gain
            yaw = self.yaw_gain * normalized_mid_x

            current_time = time.time()
            if int(current_time) % 20 < 10:
                sway = self.sway_gain
            else:
                sway = -self.sway_gain
        else:
            # If the object is out of view, set yaw based on the last known side
            yaw = 0.1 if self.last_normalized_mid_x > 0 else -0.1
       
        self.publish_velocity(surge, sway, yaw, heave)

    def publish_velocity(self, surge, sway, yaw, heave):
        self.desired_vel.surge = surge
        self.desired_vel.sway = sway
        self.desired_vel.heave = heave
        self.desired_vel.yaw = yaw
        self.vel_publisher.publish(self.desired_vel)

def main(args=None):
    rclpy.init(args=args)
    controller = ChainPosController()
    rclpy.spin(controller)
    cv2.destroyAllWindows()
    controller.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

#setting a constant sway that alternats pos/neg on a timer 10 sec
#Controlling yaw to put line in middle of camera.
#If line goes ourtside box a constand sway is set depending on side it dissapres on
#Controlling surge to be within with threshold at 70 
#Heave is controlled with gain values where negative -> down 