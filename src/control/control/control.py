#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from robot_interfaces.msg import DesiredVelocity  # Assuming this is your custom message
from blueye.sdk import Drone  # Import the Blueye SDK

class DroneController(Node):
    def __init__(self):
        super().__init__('drone_controller')
        self.myDrone = Drone()  # Initialize the drone using the Blueye SDK
        self.subscription = self.create_subscription(
            DesiredVelocity,  # Use DesiredVelocity message type
            '/desired_velocity',  # Subscribe to the /desired_velocity topic
            self.desired_velocity_callback,  # Name of the callback function
            10)

    def desired_velocity_callback(self, msg):
        # Directly assign the values from the DesiredVelocity message to the drone's motion properties
        self.myDrone.motion.surge = msg.surge
        self.myDrone.motion.sway = msg.sway
        self.myDrone.motion.heave = msg.heave
        self.myDrone.motion.yaw = msg.yaw

        # Log the updated motion values for debugging purposes
        self.get_logger().info(f'Updated Drone Motion: Surge={msg.surge}, Sway={msg.sway}, Heave={msg.heave}, Yaw={msg.yaw}')

def main(args=None):
    rclpy.init(args=args)
    drone_controller = DroneController()
    try:
        rclpy.spin(drone_controller)
    except KeyboardInterrupt:
        drone_controller.get_logger().info("Stopping Drone Controller node.")
    finally:
        drone_controller.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
