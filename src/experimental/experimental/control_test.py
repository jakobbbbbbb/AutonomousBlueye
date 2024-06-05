#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from robot_interfaces.msg import ChainPos  # Assuming this is your custom message
from blueye.sdk import Drone  # Import the Blueye SDK

class DroneController(Node):
    def __init__(self):
        super().__init__('drone_controller')
        self.myDrone = Drone()  # Initialize the drone using the Blueye SDK
        self.subscription = self.create_subscription(
            ChainPos,
            '/ChainPos',
            self.chain_pos_callback,
            10)
        self.subscription  # prevent unused variable warning

    def chain_pos_callback(self, msg):
        # Check the condition and set lights accordingly
        if msg.data[0] > 0:
            self.myDrone.lights = 0.2  # Turn off the lights
        else:
            self.myDrone.lights = 0.1  # Set lights to a low brightness level

        # Assuming the Blueye SDK handles light changes automatically upon setting the `lights` attribute.
        # No explicit method call is shown here to update the lights, assuming direct assignment triggers the change.

def main(args=None):
    rclpy.init(args=args)
    drone_controller = DroneController()
    rclpy.spin(drone_controller)
    # Destroy the node explicitly
    drone_controller.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
