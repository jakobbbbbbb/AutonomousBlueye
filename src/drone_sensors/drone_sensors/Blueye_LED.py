import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32
from blueye.sdk import Drone

# NOTE: This portion publishes LED control
class DroneLEDPublisher(Node):
    def __init__(self):
        super().__init__('led_publisher')
        self.drone = Drone()
        # Publisher to read current brightness
        self.led_publisher = self.create_publisher(Float32, '/led_brightness', 10)

        # Subscription to receive desired brightness
        self.led_subscriber = self.create_subscription(
            Float32, '/set_led_brightness', self.set_led_brightness_callback, 10
        )
        
        # Updates with freq = 10 Hz
        self.timer = self.create_timer(0.1, self.publish_LED_brightness)

    def publish_LED_brightness(self):
        # Fetch brightness of LED
        brightness = self.drone.lights
        if brightness is not None:
            brightness_msg = Float32()
            brightness_msg.data = brightness
            self.led_publisher.publish(brightness_msg)

    def set_led_brightness_callback(self, msg):
        brightness = msg.data
        try:
            self.drone.lights = brightness
        except ValueError as e:
            self.get_logger().error(f"Invalid brightness: {e}")

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