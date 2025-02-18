import cv2
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import rclpy
from rclpy.node import Node

class VideoPublisher(Node):
    def __init__(self):
        super().__init__('video_publisher_node')
        self.publisher_ = self.create_publisher(Image, '/camera', 10)
        self.bridge = CvBridge()
        
        self.cap = cv2.VideoCapture('/home/nikolai/Sintef_bouy_22_03_24/autonomous_main_1.mp4') 
        # self.cap = cv2.VideoCapture('/home/nikolai/Sintef_bouy_22_03_24/autonomous_top2.mp4') 
        # self.cap = cv2.VideoCapture('/home/nikolai/Sintef_bouy_22_03_24/autonomous_marine_growth.mp4') 
        # self.cap = cv2.VideoCapture('/home/nikolai/Sintef_bouy_22_03_24/autonomous_main_2.mp4') 
        # self.cap = cv2.VideoCapture('/home/nikolai/Sintef_bouy_22_03_24/autonomous_shackle.mp4') 
        # self.cap = cv2.VideoCapture('/home/nikolai/Sintef_bouy_22_03_24/autonomous_seafloor.mp4') 

        # self.cap = cv2.VideoCapture('/home/nikolai/Sintef_bouy_22_03_24/autonomous_TBS.mp4') 
        # self.cap = cv2.VideoCapture('/home/nikolai/Sintef_bouy_22_03_24/blender2.mp4') 
        # self.cap = cv2.VideoCapture('/home/nikolai/Sintef_bouy_22_03_24/TBS_calibration.MP4') 
        # self.cap = cv2.VideoCapture('/home/nikolai/Sintef_bouy_22_03_24/TBS_calibration1.mp4')

        # self.cap = cv2.VideoCapture('/home/nikolai/Sintef_bouy_22_03_24/m1_AKER_BP.mp4') 

        # self.cap = cv2.VideoCapture('/home/nikolai/Sintef_bouy_22_03_24/Old_inspection5.mp4') 



        if not self.cap.isOpened():
            self.get_logger().error('Unable to open video file.')
            exit()

        # Set desired FPS and dimensions
        self.desired_fps = 30.0
        self.width = 1920
        self.height = 1080

        # Set timer to match the desired FPS
        self.timer = self.create_timer(1.0 / self.desired_fps, self.timer_callback)

    def timer_callback(self):
        ret, frame = self.cap.read()
        if ret:
            # Resize frame to desired dimensions
            resized_frame = cv2.resize(frame, (self.width, self.height))
            
            # Convert the frame to ROS Image message and publish
            msg = self.bridge.cv2_to_imgmsg(resized_frame, 'bgr8')
            self.publisher_.publish(msg)
        else:
            self.get_logger().info('Video has ended, looping.')
            self.cap.set(cv2.CAP_PROP_POS_FRAMES, 0)  # Loop the video

def main(args=None):
    rclpy.init(args=args)
    video_publisher = VideoPublisher()
    rclpy.spin(video_publisher)
    video_publisher.cap.release()
    video_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
