import rclpy
from rclpy.node import Node
from robot_interfaces.msg import DesiredVelocity, ChainPos
import math

class ChainPosController(Node):
    def __init__(self):
        super().__init__('chain_pos_controller')

        self.vel_publisher = self.create_publisher(DesiredVelocity, '/desired_velocity', 10)
        self.chain_pos_subscriber = self.create_subscription(ChainPos, '/ChainPos', self.chain_pos_callback, 10)

    def chain_pos_callback(self, msg):
        # Accessing mid_x, mid_y, and adjusted_angle from the data list
        mid_x = msg.data[0]
        mid_y = msg.data[1]
        adjusted_angle = msg.data[2]

        # Process the ChainPos message and publish desired velocity
        # Example logic based on mid_x and adjusted_angle
        sway = -2.0 if mid_x > 250 else 2.0
        heave = -2 * abs(math.cos(math.radians(adjusted_angle)))

        self.publish_velocity(0.0, sway, 0.0, heave)

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
    controller.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
