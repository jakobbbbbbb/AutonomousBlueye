#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from bboxes_ex_msgs.msg import BoundingBoxes
from robot_interfaces.msg import YoloCannyChainPose
from cv_bridge import CvBridge
import cv2
import numpy as np
import math
from collections import deque
import warnings
import sys

# Ignoring source warning from Yolov5
warnings.filterwarnings("ignore", category=FutureWarning)
warnings.filterwarnings("ignore", category=DeprecationWarning)

class ObjectDetection(Node):
    def __init__(self):
        super().__init__("object_detection")
        # For testing with video file:
        self.image_subscriber = self.create_subscription(Image, "/image_raw", self.image_callback, 1)
        # For actual drone:
        #self.image_subscriber = self.create_subscription(Image, "/camera", self.image_callback, 1)
        
        self.bridge = CvBridge()
        self.bounding_boxes = None
        self.bbox_subscriber = self.create_subscription(BoundingBoxes, '/yolov5_ros/detections', self.bbox_callback, 10)
        self.YoloChainPose_publisher = self.create_publisher(YoloCannyChainPose, 'YoloCannyChainPose', 10)
        
        # Set consistent window sizes for all windows
        self.window_width = 960
        self.window_height = 600
        
        # GUI windows and trackbars
        cv2.namedWindow('YOLO Detection', cv2.WINDOW_NORMAL)
        cv2.resizeWindow('YOLO Detection', self.window_width, self.window_height)
        
        cv2.namedWindow('Canny inside Box', cv2.WINDOW_NORMAL)
        cv2.resizeWindow('Canny inside Box', self.window_width, self.window_height)
        
        cv2.namedWindow('Canny Edges', cv2.WINDOW_NORMAL)
        cv2.resizeWindow('Canny Edges', self.window_width, self.window_height)
        
        # Enhanced trackbars for better control
        cv2.createTrackbar("Min Threshold", "Canny inside Box", 6, 255, lambda x: None)
        cv2.createTrackbar("Max Threshold", "Canny inside Box", 9, 255, lambda x: None)
        cv2.createTrackbar("Box Size", "Canny inside Box", 800, 1000, lambda x: None)
        cv2.createTrackbar("CLAHE Limit", "Canny inside Box", 15, 40, lambda x: None)  # New trackbar for CLAHE
        
        # Initialize state variables
        self.transition_piece_detected = False
        self.last_detection_time = None
        self.detection_history = deque(maxlen=10)  # Keep track of last 10 detections

    def bbox_callback(self, msg):
        self.bounding_boxes = msg.bounding_boxes
        self.get_logger().info(f"Received {len(msg.bounding_boxes)} bounding boxes")

    def guided_filter(self, img, radius=32, eps=0.6):
        """Apply bilateral filter for edge-preserving smoothing"""
        return cv2.bilateralFilter(img, d=radius, sigmaColor=eps*100, sigmaSpace=radius)

    def process_roi(self, roi, is_yolo=False):
        """Enhanced ROI processing with improved image processing pipeline"""
        # Convert to YCrCb color space for better color separation
        YCrCb = cv2.cvtColor(roi, cv2.COLOR_BGR2YCrCb)
        Y, Cr, Cb = cv2.split(YCrCb)

        # Apply CLAHE with dynamic clip limit
        clip_limit = cv2.getTrackbarPos("CLAHE Limit", "Canny inside Box") / 10.0
        clahe = cv2.createCLAHE(clipLimit=clip_limit, tileGridSize=(8, 8))
        Y_clahe = clahe.apply(Y)

        # Apply guided filter for noise reduction while preserving edges
        Y_guided = self.guided_filter(Y_clahe, radius=32, eps=0.6)

        # Enhanced morphological operations
        kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (10, 10))
        Y_eroded = cv2.erode(Y_guided, kernel, iterations=1)
        Y_cleaned = cv2.morphologyEx(Y_eroded, cv2.MORPH_OPEN, kernel)

        # Get Canny thresholds from trackbars
        min_val = cv2.getTrackbarPos("Min Threshold", "Canny inside Box")
        max_val = cv2.getTrackbarPos("Max Threshold", "Canny inside Box")

        # Apply Canny edge detection
        edges = cv2.Canny(Y_cleaned, min_val, max_val)

        # Calculate line properties
        row_white_pixel_counts = np.sum(edges == 255, axis=1)
        average_width = np.mean(row_white_pixel_counts) if row_white_pixel_counts.size > 0 else 0

        # Find line using edge points
        y_coords, x_coords = np.where(edges == 255)
        if len(x_coords) > 0 and len(y_coords) > 0:
            points = np.column_stack((x_coords, y_coords))
            [vx, vy, x0, y0] = cv2.fitLine(points, cv2.DIST_L2, 0, 0.01, 0.01)
            angle_deg = math.degrees(math.atan2(vy, vx)) - 90

            # Calculate line endpoints for visualization
            length = max(1000, int(math.sqrt(roi.shape[0]**2 + roi.shape[1]**2)))
            
            return {
                'edges': edges,
                'angle_deg': angle_deg,
                'average_width': average_width,
                'mid_x': int(x0),
                'mid_y': int(y0),
                'global_point1': (int(x0 - vx * length), int(y0 - vy * length)),
                'global_point2': (int(x0 + vx * length), int(y0 + vy * length)),
                'confidence': 1.0 if is_yolo else 0.5  # Higher confidence for YOLO detections
            }
        return None

    def image_callback(self, msg):
        image = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
        
        # Resize the input image to match window size
        image = cv2.resize(image, (self.window_width, self.window_height))
        
        yolo_image = image.copy()  # For YOLO visualization
        processed_image = image.copy()  # For final visualization
        edges_display = np.zeros_like(image)  # For displaying Canny edges
        
        image_center_x, image_center_y = image.shape[1] // 2, image.shape[0] // 2

        # Check if windows are closed
        if (cv2.getWindowProperty('Canny inside Box', cv2.WND_PROP_VISIBLE) < 1 or
            cv2.getWindowProperty('YOLO Detection', cv2.WND_PROP_VISIBLE) < 1 or
            cv2.getWindowProperty('Canny Edges', cv2.WND_PROP_VISIBLE) < 1):
            rclpy.shutdown()
            return

        result = None
        box_type = "None"
        box_color = (0, 0, 255)  # Default red color for standard box
        edges_roi = None
        current_boxes = self.bounding_boxes  # Store current boxes
        self.bounding_boxes = None

        # First check if we have any YOLO detections
        if current_boxes:
            self.get_logger().info(f"Processing {len(current_boxes)} bounding boxes")
            best_box = None
            best_probability = 0.5  # Minimum probability threshold
            
            # Process all detected objects
            for box in current_boxes:
                if box.probability > best_probability:
                    # Check for TransitionPiece
                    if box.class_id == "TransitionPiece" and not self.transition_piece_detected:
                        self.transition_piece_detected = True
                        self.get_logger().info("Transition Piece detected! Adjusting detection parameters...")
                        # You could add specific handling for transition piece detection here
                    
                    # Process MooringLine detections
                    if box.class_id == "MooringLine":
                        # Ensure box coordinates are within image bounds
                        x1 = max(0, int(box.xmin))
                        y1 = max(0, int(box.ymin))
                        x2 = min(image.shape[1], int(box.xmax))
                        y2 = min(image.shape[0], int(box.ymax))
                        
                        # Only consider if box has valid size
                        if x2 > x1 and y2 > y1:
                            # Draw all valid YOLO boxes in blue on YOLO visualization
                            cv2.rectangle(yolo_image, (x1, y1), (x2, y2), (255, 0, 0), 2)
                            cv2.putText(yolo_image, f"MooringLine ({box.probability:.2f})", 
                                      (x1, y1 - 10),
                                      cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 0, 0), 2)
                            
                            # Update best box if this one has higher probability
                            if box.probability > best_probability:
                                best_box = box
                                best_probability = box.probability

            # Try to find line in the best YOLO box
            if best_box:
                self.get_logger().info(f"Using best MooringLine box with confidence {best_probability:.2f}")
                
                # Ensure box coordinates are within image bounds
                x1 = max(0, int(best_box.xmin))
                y1 = max(0, int(best_box.ymin))
                x2 = min(image.shape[1], int(best_box.xmax))
                y2 = min(image.shape[0], int(best_box.ymax))
                
                # Only process if box has valid size
                if x2 > x1 and y2 > y1:
                    roi = image[y1:y2, x1:x2]
                    result = self.process_roi(roi, True)
                    if result:
                        box_type = "YOLO"
                        box_color = (0, 255, 0)  # Green for YOLO box
                        edges_roi = result['edges']
                        
                        # Draw active YOLO box in green on processed image
                        cv2.rectangle(processed_image, (x1, y1), (x2, y2), box_color, 2)
                        cv2.putText(processed_image, f"Active YOLO Box ({best_probability:.2f})", 
                                  (x1, y1 - 10), 
                                  cv2.FONT_HERSHEY_SIMPLEX, 0.5, box_color, 2)
                        
                        # Show edges in the edges display
                        edges_display[y1:y2, x1:x2] = cv2.cvtColor(edges_roi, cv2.COLOR_GRAY2BGR)

        # If no line found in YOLO box, try standard box
        if result is None:
            self.get_logger().info("Using standard box")
            # Use default centered box
            box_size = cv2.getTrackbarPos("Box Size", 'Canny inside Box')
            box_width = int(box_size * 1.6)
            box_height = box_size
            
            # Ensure box stays within image bounds
            top_left_x = max(0, image_center_x - box_width // 2)
            top_left_y = max(0, image_center_y - box_height // 2)
            bottom_right_x = min(image.shape[1], top_left_x + box_width)
            bottom_right_y = min(image.shape[0], top_left_y + box_height)
            
            # Only process if box has valid size
            if bottom_right_x > top_left_x and bottom_right_y > top_left_y:
                roi = image[top_left_y:bottom_right_y, top_left_x:bottom_right_x]
                result = self.process_roi(roi, False)
                if result:
                    box_type = "Standard"
                    box_color = (0, 0, 255)  # Red for standard box
                    edges_roi = result['edges']
                    
                    # Draw standard box
                    cv2.rectangle(processed_image, (top_left_x, top_left_y), 
                                (bottom_right_x, bottom_right_y), box_color, 2)
                    cv2.putText(processed_image, "Active Standard Box", 
                              (top_left_x, top_left_y - 10), 
                              cv2.FONT_HERSHEY_SIMPLEX, 0.5, box_color, 2)
                    
                    # Show edges in the edges display
                    edges_display[top_left_y:bottom_right_y, top_left_x:bottom_right_x] = \
                        cv2.cvtColor(edges_roi, cv2.COLOR_GRAY2BGR)

        if result:
            # Draw the line and info on both YOLO and processed images
            for img in [yolo_image, processed_image]:
                # Draw the line
                cv2.line(img, result['global_point1'], result['global_point2'], (0, 255, 0), 2)
                
                # Draw midpoint
                cv2.circle(img, (result['mid_x'], result['mid_y']), 5, (255, 0, 0), -1)
                
                # Enhanced status display
                status_text = f"Box Type: {box_type} | Line Found: Yes"
                cv2.putText(img, status_text, (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
                
                # Add detailed position and measurement info
                cv2.putText(img, f'Midpoint: ({result["mid_x"]}, {result["mid_y"]})', (10, 50), 
                           cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
                cv2.putText(img, f'Angle: {result["angle_deg"]:.2f} degrees', (10, 70), 
                           cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
                cv2.putText(img, f'Width: {result["average_width"]:.2f} pixels', (10, 90), 
                           cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
                
                if self.transition_piece_detected:
                    cv2.putText(img, "Transition Piece Detected!", (10, 110), 
                              cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 2)
            
            # Update detection history
            self.detection_history.append({
                'mid_x': result['mid_x'],
                'mid_y': result['mid_y'],
                'angle': result['angle_deg']
            })
            
            # Publish pose
            pose_msg = YoloCannyChainPose()
            pose_msg.mid_x = float(result['mid_x'] - image_center_x)
            pose_msg.mid_y = float(image_center_y - result['mid_y'])
            pose_msg.angle_degrees = float(result['angle_deg'])
            self.YoloChainPose_publisher.publish(pose_msg)

        else:
            # Add status text when no line is found
            status_text = f"Box Type: {box_type} | Line Found: No"
            cv2.putText(processed_image, status_text, (10, 30), 
                       cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 2)
            cv2.putText(yolo_image, status_text, (10, 30), 
                       cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 2)

        # Show all windows
        cv2.imshow("YOLO Detection", yolo_image)  # Shows all YOLO boxes
        cv2.imshow("Canny inside Box", processed_image)  # Shows active box and processing
        cv2.imshow("Canny Edges", edges_display)  # Shows just the Canny edges
        
        # Ensure windows stay on top and maintain size
        cv2.resizeWindow('YOLO Detection', self.window_width, self.window_height)
        cv2.resizeWindow('Canny inside Box', self.window_width, self.window_height)
        cv2.resizeWindow('Canny Edges', self.window_width, self.window_height)
        
        cv2.waitKey(1)

def main(args=None):
    rclpy.init(args=args)
    node = ObjectDetection()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()
        cv2.destroyAllWindows()

if __name__ == '__main__':
    main() 