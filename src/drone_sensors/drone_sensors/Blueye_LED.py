import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32
from blueye.sdk import Drone

# NOTE: This portion publishes LED control
class DroneLEDPublisher(Node):
    def __init__(self):
        super().__init__('led_publisher')
        self.led_publisher = self.create_publisher(Float32, '/led_brightness', 10)
        self.drone = Drone()
        self.timer = self.create_timer(0.1, self.publish_led)

    def publish_led(self):
        # Fetch drone LED brightness
        led_brightness = self.drone.lights()

        led_msg = Float32()
        led_msg.data = led_brightness
        self.led_publisher.publish(led_msg)


def main(args = None):
    rclpy.init(args = args)
    led_publisher = DroneLEDPublisher()
    
    try:
        rclpy.spin(led_publisher)
    except KeyboardInterrupt:
        led_publisher.get_logger().info("Stopping LED publisher node.")
    finally:
        led_publisher.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()