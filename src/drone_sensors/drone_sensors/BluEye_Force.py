import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Vector3  
import blueye.protocol as bp

from blueye.sdk import Drone

class DroneForcePublisher(Node):
    def __init__(self):
        super().__init__('drone_force_publisher')
        self.force_publisher = self.create_publisher(Vector3, 'BlueyeForces', 10)
        self.drone = Drone()
        self.timer = self.create_timer(0.1, self.publish_drone_forces)

    def publish_drone_forces(self):
        # Fetch force data from drone
        surge_force = self.drone.motion.surge
        sway_force = self.drone.motion.sway
        heave_force = self.drone.motion.heave
        # Yaw force can be considheaveered as torque, which is not included in Vector3
        
        # Create a Vector3 message to carry surge, sway, and heave forces
        force_msg = Vector3()
        force_msg.x = float(surge_force) # Surge force
        force_msg.y = float(sway_force)   # Sway force
        force_msg.z = float(heave_force)  # Heave force
        
        # Publish the force data
        self.force_publisher.publish(force_msg)
        self.get_logger().info(f"Published forces: Surge={force_msg.x} N, Sway={force_msg.y} N, Heave={force_msg.z} N")

def main(args=None):
    rclpy.init(args=args)
    drone_force_publisher = DroneForcePublisher()

    try:
        rclpy.spin(drone_force_publisher)
    except KeyboardInterrupt:
        drone_force_publisher.get_logger().info("Stopping Drone Force Publisher node.")
    finally:
        drone_force_publisher.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
