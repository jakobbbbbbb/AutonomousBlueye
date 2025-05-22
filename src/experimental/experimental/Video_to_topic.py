import cv2
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import rclpy
from rclpy.node import Node
import time

def nothing(x):
    pass

class VideoPublisher(Node):
    def __init__(self):
        super().__init__('video_publisher_node')
        self.publisher_ = self.create_publisher(Image, '/camera', 10)
        self.bridge = CvBridge()
        
        # Velg videokilde:
        #self.cap = cv2.VideoCapture('/home/cle/upward_inspection.mp4')
        self.cap = cv2.VideoCapture('/home/cle/shackle_success.MP4')
        
        # om du heller vil bruke webkamera: uncomment neste linje
        # self.cap = cv2.VideoCapture(0)

        if not self.cap.isOpened():
            self.get_logger().error('Unable to open video device.')
            exit()

        # Hent videoegenskaper
        self.video_fps = self.cap.get(cv2.CAP_PROP_FPS)
        self.width    = int(self.cap.get(cv2.CAP_PROP_FRAME_WIDTH))
        self.height   = int(self.cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
        self.total_frames = int(self.cap.get(cv2.CAP_PROP_FRAME_COUNT))

        self.paused = False
        self.last_trackbar_val = 0

        # Timer basert på videofps
        self.timer = self.create_timer(1.0 / self.video_fps, self.timer_callback)

        # OpenCV-vindu og trackbar for å spole i video
        cv2.namedWindow('Video', cv2.WINDOW_NORMAL)
        cv2.resizeWindow('Video', 700, 500)
        if self.total_frames > 0:
            cv2.createTrackbar('Frames', 'Video', 0, self.total_frames, nothing)

        # Default crop-verdier (i piksler)
        self.crop_left   = 50
        self.crop_right  = 50
        self.crop_top    = 20
        self.crop_bottom = 20

        # Trackbars for cropping
        cv2.createTrackbar('Left',   'Video', self.crop_left,   self.width//2,  nothing)
        cv2.createTrackbar('Right',  'Video', self.crop_right,  self.width//2,  nothing)
        cv2.createTrackbar('Top',    'Video', self.crop_top,    self.height//2, nothing)
        cv2.createTrackbar('Bottom', 'Video', self.crop_bottom, self.height//2, nothing)

    def timer_callback(self):
        key = cv2.waitKey(1) & 0xFF
        if key == ord(' '):  # mellomrom = play/pause
            self.paused = not self.paused

        # Spoling via Frames-trackbar
        if self.total_frames > 0:
            trackbar_val = cv2.getTrackbarPos('Frames', 'Video')
            if trackbar_val != self.last_trackbar_val:
                self.cap.set(cv2.CAP_PROP_POS_FRAMES, trackbar_val)
                self.last_trackbar_val = trackbar_val

        if self.paused:
            return

        ret, frame = self.cap.read()
        if not ret:
            self.get_logger().info('Video has ended, looping.')
            self.cap.set(cv2.CAP_PROP_POS_FRAMES, 0)
            return

        # Oppdater crop-verdier fra trackbars
        self.crop_left   = cv2.getTrackbarPos('Left',   'Video')
        self.crop_right  = cv2.getTrackbarPos('Right',  'Video')
        self.crop_top    = cv2.getTrackbarPos('Top',    'Video')
        self.crop_bottom = cv2.getTrackbarPos('Bottom', 'Video')

        # Beregn ROI-koordinater
        x1 = self.crop_left
        x2 = frame.shape[1] - self.crop_right
        y1 = self.crop_top
        y2 = frame.shape[0] - self.crop_bottom
        # Sikre gyldige verdier
        x2 = max(x1 + 1, min(x2, frame.shape[1]))
        y2 = max(y1 + 1, min(y2, frame.shape[0]))

        # Crop
        cropped = frame[y1:y2, x1:x2]

        # Oppdater display- og publiseringsstørrelse dynamisk
        crop_w = x2 - x1
        crop_h = y2 - y1
        resized = cv2.resize(cropped, (crop_w, crop_h), interpolation=cv2.INTER_AREA)

        # Vis og publiser
        cv2.imshow('Video', resized)
        msg = self.bridge.cv2_to_imgmsg(resized, 'bgr8')
        self.publisher_.publish(msg)

        # Oppdater Frames-trackbar til gjeldende posisjon
        if self.total_frames > 0:
            cv2.setTrackbarPos('Frames', 'Video', int(self.cap.get(cv2.CAP_PROP_POS_FRAMES)))

    def destroy_node(self):
        # Cleanup
        self.cap.release()
        cv2.destroyAllWindows()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = VideoPublisher()
    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
