import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32
from blueye.sdk import Drone

# NOTE: This portion publishes LED control
class DroneLEDPublisher(Node):
    def __init__(self):
        super().__init__('led_publisher')
        self.led_pub = self.create_publisher(Float32, 'BlueyeLED', 10)
        self.drone = Drone()
        self.brightness = 1.0
        self.timer = self.create_timer(0.1, self.toggle_led)

        def toggle_led(self):
            msg = Float32()
            msg.data = self.brightness
            self.led_pub.publish(msg)

