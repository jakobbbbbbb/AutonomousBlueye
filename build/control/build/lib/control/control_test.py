#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from robot_interfaces.msg import DesiredVelocity  # Updated to use DesiredVelocity message
from blueye.sdk import Drone  # Import the Blueye SDK

class DroneController(Node):
    def __init__(self):
        super().__init__('drone_controller')
        self.myDrone = Drone()  # Initialize the drone using the Blueye SDK
        self.subscription = self.create_subscription(
            DesiredVelocity,  # Use DesiredVelocity message type
            '/desired_velocity',  # Subscribe to the /desired_velocity topic
            self.desired_velocity_callback,  # Update the callback function name
            10)

    def desired_velocity_callback(self, msg):
        # Use the sway value to determine light intensity
        if msg.sway > 1:
            self.myDrone.lights = 0.1  # If sway > 1, set lights to low brightness
        else:
            self.myDrone.lights = 0.2  # If sway <= 1, set lights to higher brightness

        # if msg.sway > 1:
        #     self.myDrone.motion.sway = 0.2  # If sway > 1, set lights to low brightness
        # else:
        #     self.myDrone.motion.sway = 0.3  # If sway <= 1, set lights to higher brightness
        # The Blueye SDK is assumed to update the drone's lights automatically upon setting the `lights` attribute.

def main(args=None):
    rclpy.init(args=args)
    drone_controller = DroneController()
    rclpy.spin(drone_controller)
    # Destroy the node explicitly
    drone_controller.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
