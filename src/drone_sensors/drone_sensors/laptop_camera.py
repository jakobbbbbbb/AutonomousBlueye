import cv2
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import rclpy
from rclpy.node import Node

class CameraPublisher(Node):
    def __init__(self):
        super().__init__('laptop_camera_node')
        self.publisher_ = self.create_publisher(Image, '/camera', 10)
        self.bridge = CvBridge()
        
        # Attempt to open the camera; adjust the device path or index as necessary
        self.cap = cv2.VideoCapture(0)  # Adjust this line if necessary
        
        if not self.cap.isOpened():
            self.get_logger().error('Unable to open camera.')
            exit()

        self.timer = self.create_timer(0.1, self.timer_callback)

    def timer_callback(self):
        ret, frame = self.cap.read()
        if ret:
            msg = self.bridge.cv2_to_imgmsg(frame, 'bgr8')
            self.publisher_.publish(msg)
        else:
            self.get_logger().error('Failed to capture frame')

def main(args=None):
    rclpy.init(args=args)
    camera_publisher = CameraPublisher()
    rclpy.spin(camera_publisher)
    camera_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
