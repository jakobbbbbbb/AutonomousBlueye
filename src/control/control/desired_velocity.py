import rclpy
from rclpy.node import Node
from robot_interfaces.msg import DesiredVelocity, ThreshChainPos, CannyChainPos
import cv2
import math
import numpy as np
import threading

def nothing(x):
    pass

class ChainPosController(Node):
    def __init__(self):
        super().__init__('chain_pos_controller')
        self.vel_publisher = self.create_publisher(DesiredVelocity, '/desired_velocity', 10)
        self.chain_pos_subscriber = self.create_subscription(ThreshChainPos, '/ThreshChainPos', self.chain_pos_callback, 10)
        # self.chain_pos_subscriber = self.create_subscription(CannyChainPos, '/CannyChainPos', self.chain_pos_callback, 10)

        self.start_gui()
        self.desired_vel = DesiredVelocity()  

    def start_gui(self):
        threading.Thread(target=self.setup_gui, daemon=True).start()

    def setup_gui(self):
        cv2.namedWindow('Gain', cv2.WINDOW_NORMAL)
        cv2.resizeWindow('Gain', 600, 400)  
        
        cv2.createTrackbar("Surge Gain", 'Gain', 100, 200, nothing)  # Adjusted range
        cv2.createTrackbar("Sway Gain", 'Gain', 100, 200, nothing)  # Adjusted range
        cv2.createTrackbar("Heave Gain", 'Gain', 100, 200, nothing)  # 150 corresponds to -0.5
        cv2.createTrackbar("Yaw Gain", 'Gain', 100, 200, nothing)  # Adjusted range
        
        while True:
            canvas = np.zeros((400, 600, 3), dtype=np.uint8)
            cv2.putText(canvas, f"Surge: {self.desired_vel.surge:.2f}", (10, 250), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 255), 2)
            cv2.putText(canvas, f"Sway: {self.desired_vel.sway:.2f}", (10, 290), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 255), 2)
            cv2.putText(canvas, f"Heave: {self.desired_vel.heave:.2f}", (10, 330), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 255), 2)
            cv2.putText(canvas, f"Yaw: {self.desired_vel.yaw:.2f}", (10, 370), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 255), 2)
            
            cv2.imshow('Gain', canvas)
            cv2.waitKey(50)

    def chain_pos_callback(self, msg):
        # Convert trackbar values to gains
        surge_gain = (cv2.getTrackbarPos("Surge Gain", 'Gain') - 100) / 100.0  #values between -1 and 1
        sway_gain = cv2.getTrackbarPos("Sway Gain", 'Gain') / 100.0            #values between 0 and 1
        yaw_gain = (cv2.getTrackbarPos("Yaw Gain", 'Gain') - 100) / 100.0
        heave_gain = (cv2.getTrackbarPos("Heave Gain", 'Gain') - 100) / 100.0

        normalized_mid_x = (msg.data[0] / 960)  
        normalized_mid_y = (msg.data[1] / 540)  

        surge = surge_gain
        # surge = width * surge_gain
        sway = normalized_mid_x * sway_gain
        heave = heave_gain
        yaw = yaw_gain

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
