import rclpy
from rclpy.node import Node
from robot_interfaces.msg import DesiredVelocity, ThreshChainPos, CannyChainPos
from geometry_msgs.msg import Quaternion  # Import for subscribing to BlueyePose
import cv2
import math
import threading
import time

def nothing(x):
    pass

class ChainPosController(Node):
    def __init__(self):
        super().__init__('chain_pos_controller')
        self.vel_publisher = self.create_publisher(DesiredVelocity, '/desired_velocity', 10)
        self.chain_pos_subscriber = self.create_subscription(ThreshChainPos, '/ThreshChainPos', self.chain_pos_callback, 10)
        self.pose_subscriber = self.create_subscription(Quaternion, 'BlueyePose', self.pose_callback, 10)  # Subscribe to BlueyePose
        
        self.start_gui()

        self.current_yaw = None  # Store current yaw
        self.target_range = (0, 10)  # Initial target range

    def start_gui(self):
        threading.Thread(target=self.setup_gui, daemon=True).start()

    def setup_gui(self):
        cv2.namedWindow('Gain', cv2.WINDOW_NORMAL)
        cv2.createTrackbar("Surge Gain", 'Gain', 100, 200, nothing)
        cv2.createTrackbar("Sway Gain", 'Gain', 100, 200, nothing)
        cv2.createTrackbar("Heave Gain", 'Gain', 100, 200, nothing)
        cv2.createTrackbar("Yaw Gain", 'Gain', 100, 200, nothing)
        
        while True:
            cv2.waitKey(50)

    def pose_callback(self, msg):
        # Update current yaw from the Quaternion message
        self.current_yaw = msg.z  # Assuming yaw is stored in z

    def chain_pos_callback(self, msg):
        if self.current_yaw is None:
            return  # Do nothing if yaw hasn't been received yet

        surge_gain = cv2.getTrackbarPos("Surge Gain", 'Gain') / 100.0
        sway_gain = cv2.getTrackbarPos("Sway Gain", 'Gain') / 100.0
        yaw_gain = cv2.getTrackbarPos("Yaw Gain", 'Gain') / 100
        heave_gain = (cv2.getTrackbarPos("Heave Gain", 'Gain') - 100) / 100.0

        normalized_mid_x = (msg.data[0] / 960)
        angle_radians = math.radians(self.current_yaw)

        # Check if current yaw is within the target range
        if self.target_range[0] <= self.current_yaw <= self.target_range[1]:
            # Switch target range
            if self.target_range == (0, 10):
                self.target_range = (80, 90)
                sway = -sway_gain  # Use negative sway_gain when target is 80 to 90
            else:
                self.target_range = (0, 10)
                sway = sway_gain   # Use sway_gain when target is 0 to 10
        else:
            # Keep sway based on the last target range
            sway = sway_gain if self.target_range == (0, 10) else -sway_gain

        heave = heave_gain * math.cos(angle_radians) * -1
        yaw = yaw_gain

        self.publish_velocity(0, sway, yaw, heave)  # Set surge to 0 for simplicity

    def publish_velocity(self, surge, sway, yaw, heave):
        desired_vel = DesiredVelocity()
        desired_vel.surge = surge
        desired_vel.sway = sway
        desired_vel.heave = heave
        desired_vel.yaw = yaw

        self.vel_publisher.publish(desired_vel)

def main(args=None):
    rclpy.init(args=args)
    controller = ChainPosController()
    rclpy.spin(controller)
    cv2.destroyAllWindows()
    controller.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
