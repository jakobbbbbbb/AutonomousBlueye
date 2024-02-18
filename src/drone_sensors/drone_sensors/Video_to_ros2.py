import rclpy
from rclpy.node import Node
import cv2
from cv_bridge import CvBridge
from sensor_msgs.msg import Image

class BlueyeCommandNode(Node):

    def __init__(self):
        super().__init__("blueye_commands_node")

        self.bridge = CvBridge()
        self.camera_publisher = self.create_publisher(Image, "/camera", 10)

        self.read_camera()

    def read_camera(self):
        rtsp_url = "rtsp://192.168.1.101:8554/test"
        cap = cv2.VideoCapture(rtsp_url)

        if not cap.isOpened():
            self.get_logger().error("Unable to open camera stream.")
            return

        try:
            while rclpy.ok():
                ret, frame = cap.read()
                if not ret:
                    self.get_logger().error("Unable to fetch frame")
                    break

                # Resize the frame for a smaller window
                small_frame = cv2.resize(frame, (640, 480))

                # Display the resulting frame
                cv2.imshow("Camera Feed", small_frame)
                if cv2.waitKey(1) & 0xFF == ord('q'):
                    break

                # Convert OpenCV image to ROS2 message
                ros_image = self.bridge.cv2_to_imgmsg(frame, encoding="bgr8")
                self.camera_publisher.publish(ros_image)

        finally:
            cap.release()
            cv2.destroyAllWindows()

def main(args=None):
    rclpy.init(args=args)
    blueye_commands_node = BlueyeCommandNode()
    rclpy.spin(blueye_commands_node)
    blueye_commands_node.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
