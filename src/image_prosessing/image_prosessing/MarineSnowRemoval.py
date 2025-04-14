import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from robot_interfaces.msg import CannyChainPos
from bboxes_ex_msgs.msg import BoundingBoxes
import cv2
from experimental.Guided_Filter import guided_filter
import math
import numpy as np

def nothing(x):
    pass

class BlueyeImage(Node):
    def __init__(self):
        super().__init__("blueye_image")
        self.subscription = self.create_subscription(Image, "/image_raw", self.image_callback, 10)
        self.publisher = self.create_publisher(CannyChainPos, "/CannyChainPos", 10)
        self.bridge = CvBridge()
        self.prev_gray = None
        self.bounding_boxes = None
        self.bbox_subscriber = self.create_subscription(BoundingBoxes, '/yolov5_ros/detections', self.bbox_callback, 10)

        # Setup OpenCV Window
        cv2.namedWindow('Canny Edge Detection', cv2.WINDOW_NORMAL)
        cv2.resizeWindow('Canny Edge Detection', 960, 600)
        # Setup extra window for comparison
        #cv2.namedWindow('Unfiltered', cv2.WINDOW_NORMAL)
        #cv2.resizeWindow('Unfiltered', 960, 600)

        # Creating trackbars for adjusting thresholds
        cv2.createTrackbar("Lower Threshold", 'Canny Edge Detection', 5, 255, nothing)
        cv2.createTrackbar("Upper Threshold", 'Canny Edge Detection', 14, 255, nothing)
        cv2.createTrackbar("Box Size", 'Canny Edge Detection', 800, 1000, nothing)    

    def bbox_callback(self, msg):
        self.bounding_boxes = msg.bounding_boxes
        self.get_logger().info(f"Received {len(msg.bounding_boxes)} bounding boxes")

    def process_roi(self, image, x1, y1, x2, y2, is_yolo_box=True):
        # Extract ROI
        roi = image[y1:y2, x1:x2]
        
        # Converting to YCbCr
        YCrCb = cv2.cvtColor(roi, cv2.COLOR_BGR2YCrCb)
        # Splitting YCrCb image components
        Y, Cr, Cb = cv2.split(YCrCb)
        
        # Applying guided filtering to luminance (Y) component
        Y_guided = guided_filter(Y, Y, radius = 32, eps = 0.1)
        
        # Remove small spots (marine snow)
        kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (3, 3))
        Y_eroded = cv2.erode(Y_guided, kernel, iterations = 1)
        Y_cleaned = cv2.morphologyEx(Y_eroded, cv2.MORPH_CLOSE, kernel)
        
        # Get trackbar values
        lower_thresh = cv2.getTrackbarPos("Lower Threshold", 'Canny Edge Detection')
        upper_thresh = cv2.getTrackbarPos("Upper Threshold", 'Canny Edge Detection')
        
        # Applying Canny Edge Detection
        edges = cv2.Canny(Y_cleaned, lower_thresh, upper_thresh)
        
        # Find white pixels
        y_coords, x_coords = np.where(edges == 255)
        if len(x_coords) > 0 and len(y_coords) > 0:
            points = np.column_stack((x_coords, y_coords))
            [vx, vy, x0, y0] = cv2.fitLine(points, cv2.DIST_L2, 0, 0.01, 0.01)
            angle_deg = math.degrees(math.atan2(vy, vx)) - 90
            
            # Calculate points for line drawing
            length = max(1000, int(math.sqrt(image.shape[0]**2 + image.shape[1]**2)))
            point1 = (int(x0 - vx * length), int(y0 - vy * length))
            point2 = (int(x0 + vx * length), int(y0 + vy * length))
            
            # Convert points to global image coordinates
            global_point1 = (point1[0]+x1, point1[1]+y1)
            global_point2 = (point2[0]+x1, point2[1]+y1)
            
            # Calculate midpoint
            mid_x = int(x0 + x1)
            mid_y = int(y0 + y1)
            
            # Calculate average width
            row_white_pixel_counts = np.sum(edges == 255, axis=1)
            average_width = np.mean(row_white_pixel_counts) * 10 if row_white_pixel_counts.size > 0 else 0
            
            return {
                'angle_deg': angle_deg,
                'mid_x': mid_x,
                'mid_y': mid_y,
                'average_width': average_width,
                'global_point1': global_point1,
                'global_point2': global_point2,
                'edges': edges
            }
        return None

    def image_callback(self, msg):
        frame = self.bridge.imgmsg_to_cv2(msg, "bgr8")
        height, width = frame.shape[:2]
        image_center_x, image_center_y = width // 2, height // 2

        # Check if window is closed
        if cv2.getWindowProperty('Canny Edge Detection', cv2.WND_PROP_VISIBLE) < 1:
            rclpy.shutdown()
            return
        
        result = None
        box_type = "None"
        box_color = (0, 0, 255)  # Default red color for standard box

        if self.bounding_boxes:
            for box in self.bounding_boxes:
                self.get_logger().info(f"Found box with class: {box.class_id}, confidence: {box.probability}")
                if box.class_id == "MooringLine" and box.probability > 0.5:
                    self.get_logger().info("Processing YOLO box")
                    result = self.process_roi(frame, box.xmin, box.ymin, box.xmax, box.ymax, True)
                    if result:
                        box_type = "YOLO"
                        box_color = (0, 255, 0)  # Green for YOLO box
                        cv2.rectangle(frame, (box.xmin, box.ymin), (box.xmax, box.ymax), box_color, 2)
                        cv2.putText(frame, f"YOLO Box ({box.probability:.2f})", (box.xmin, box.ymin - 10), 
                                  cv2.FONT_HERSHEY_SIMPLEX, 0.5, box_color, 2)
                        break
                    else:
                        self.get_logger().info("No line found in YOLO box")

        if result is None:
            self.get_logger().info("Using standard box")
            # Use default centered box
            box_size = cv2.getTrackbarPos("Box Size", 'Canny Edge Detection')
            box_width = int(box_size * 1.6)
            box_height = box_size
            
            top_left_x = image_center_x - box_width // 2
            top_left_y = image_center_y - box_height // 2
            bottom_right_x = top_left_x + box_width
            bottom_right_y = top_left_y + box_height
            
            result = self.process_roi(frame, top_left_x, top_left_y, bottom_right_x, bottom_right_y, False)
            if result:
                box_type = "Standard"
                box_color = (0, 0, 255)  # Red for standard box
                cv2.rectangle(frame, (top_left_x, top_left_y), (bottom_right_x, bottom_right_y), box_color, 2)
                cv2.putText(frame, "Standard Box", (top_left_x, top_left_y - 10), 
                          cv2.FONT_HERSHEY_SIMPLEX, 0.5, box_color, 2)

        if result:
            # Draw the line
            cv2.line(frame, result['global_point1'], result['global_point2'], (0, 255, 0), 2)
            
            # Draw midpoint
            cv2.circle(frame, (result['mid_x'], result['mid_y']), 5, (255, 0, 0), -1)
            
            # Add status text
            status_text = f"Box Type: {box_type} | Line Found: Yes"
            cv2.putText(frame, status_text, (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
            
            # Add position and angle info
            cv2.putText(frame, f'Midpoint: ({result["mid_x"]}, {result["mid_y"]})', (10, 50), 
                       cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
            cv2.putText(frame, f'Angle: {result["angle_deg"]:.2f} degrees', (10, 70), 
                       cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
            cv2.putText(frame, f'Width: {result["average_width"]:.2f} pixels', (10, 90), 
                       cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
            
            # Publish pose
            chain_pos_msg = CannyChainPos()
            chain_pos_msg.data = [
                float(result['mid_x'] - image_center_x),
                float(image_center_y - result['mid_y']),
                float(result['angle_deg']),
                float(result['average_width'])
            ]
            self.publisher.publish(chain_pos_msg)
        else:
            # Add status text when no line is found
            status_text = f"Box Type: {box_type} | Line Found: No"
            cv2.putText(frame, status_text, (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 2)

        cv2.imshow('Canny Edge Detection', frame)
        #cv2.imshow('Unfiltered', YCrCb_bgr)
        cv2.waitKey(1)

def main(args=None):
    rclpy.init(args=args)
    blueye_image = BlueyeImage()
    rclpy.spin(blueye_image)
    blueye_image.destroy_node()
    rclpy.shutdown()
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()