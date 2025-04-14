#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from bboxes_ex_msgs.msg import BoundingBoxes
from robot_interfaces.msg import YoloCannyChainPose
from experimental.Guided_Filter import guided_filter
from cv_bridge import CvBridge
import cv2
import numpy as np
import math

def nothing(x):
    pass

class BlueyeImage(Node):
    def __init__(self):
        super().__init__("blueye_image")
        # For testing with video file:
        self.image_subscriber = self.create_subscription(Image, "/image_raw", self.image_callback, 1)
        # For actual drone:
        #self.image_subscriber = self.create_subscription(Image, "/camera", self.image_callback, 1)
        
        self.bridge = CvBridge()
        self.bounding_boxes = None
        self.last_bbox_time = None
        
        # Subscribe to YOLO detections
        self.bbox_subscriber = self.create_subscription(
            BoundingBoxes, 
            '/yolov5/bounding_boxes',  # Updated topic name
            self.bbox_callback, 
            10
        )
        self.get_logger().info(f"Subscribed to YOLO topic: {self.bbox_subscriber.topic_name}")
        
        # Publisher for mooring line data
        self.mooring_line_publisher = self.create_publisher(
            YoloCannyChainPose,
            '/mooring_line_data',
            10
        )
        self.get_logger().info("Created publisher for mooring line data")
        
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
        
        cv2.createTrackbar("Lower Threshold", "Canny inside Box", 6, 255, nothing)
        cv2.createTrackbar("Upper Threshold", "Canny inside Box", 9, 255, nothing)
        cv2.createTrackbar("Box Size", "Canny inside Box", 800, 1000, nothing)

    def bbox_callback(self, msg):
        self.bounding_boxes = msg.bounding_boxes
        if not msg.bounding_boxes:
            self.bounding_boxes = None
            return

    def process_roi(self, image, x1, y1, x2, y2, is_yolo_box=True):
        # Extract ROI
        roi = image[y1:y2, x1:x2]
        
        # Converting to YCbCr
        YCrCb = cv2.cvtColor(roi, cv2.COLOR_BGR2YCrCb)
        # Splitting YCrCb image components
        Y, Cr, Cb = cv2.split(YCrCb)
        
        # Applying guided filtering to luminance (Y) component
        Y_guided = guided_filter(Y, radius=32, eps=0.1)
        
        # Remove small spots (marine snow)
        kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (3, 3))
        Y_eroded = cv2.erode(Y_guided, kernel, iterations = 1)
        Y_cleaned = cv2.morphologyEx(Y_eroded, cv2.MORPH_CLOSE, kernel)
        
        # Get trackbar values
        lower_thresh = cv2.getTrackbarPos("Lower Threshold", 'Canny inside Box')
        upper_thresh = cv2.getTrackbarPos("Upper Threshold", 'Canny inside Box')
        
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
            average_width = np.mean(row_white_pixel_counts) if row_white_pixel_counts.size > 0 else 0
            
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

    def get_best_yolo_box(self, boxes, image_shape):
        if boxes is None:
            self.get_logger().info("boxes is None in get_best_yolo_box")
            return None, 0.0
            
        best_box = None
        threshold = 0.3  # Minimum confidence threshold
        best_probability = threshold
        
        self.get_logger().info(f"Checking {len(boxes)} boxes for TransitionPiece")
        for box in boxes:
            # Debug print to see actual class_id value
            self.get_logger().info(f"Processing box - class_id: '{box.class_id}' (type: {type(box.class_id)})")
            
            # Prioritize TransitionPiece
            if box.class_id == "TransitionPiece":  # Exact match for TransitionPiece
                self.get_logger().info(f"Found TransitionPiece with probability {box.probability:.2f}")
                if box.probability > threshold:
                    # Ensure box coordinates are within image bounds and have valid size
                    x1 = max(0, int(box.xmin))
                    y1 = max(0, int(box.ymin))
                    x2 = min(image_shape[1], int(box.xmax))
                    y2 = min(image_shape[0], int(box.ymax))
                    
                    # Calculate box dimensions
                    box_width = x2 - x1
                    box_height = y2 - y1
                    
                    # Log box details
                    self.get_logger().info(f"Box dimensions: width={box_width}, height={box_height}")
                    self.get_logger().info(f"Box coordinates: ({x1}, {y1}) to ({x2}, {y2})")
                    self.get_logger().info(f"Image dimensions: width={image_shape[1]}, height={image_shape[0]}")
                    
                    # Only consider if box has valid size and is not too large
                    if (box_width > 50 and box_height > 50 and  # Minimum size
                        box_width < image_shape[1] * 0.9 and    # Not too wide (increased from 0.8)
                        box_height < image_shape[0] * 0.9):     # Not too tall (increased from 0.8)
                        if box.probability > best_probability:
                            best_box = box
                            best_probability = box.probability
                            self.get_logger().info(f"New best box found with probability {best_probability:.2f}")
                    else:
                        self.get_logger().info(f"Box size invalid: width={box_width}, height={box_height}")
                        self.get_logger().info(f"Max allowed: width={image_shape[1] * 0.9}, height={image_shape[0] * 0.9}")
                else:
                    self.get_logger().info(f"Box probability {box.probability:.2f} below threshold {threshold}")
            else:
                self.get_logger().info(f"Box class_id '{box.class_id}' is not TransitionPiece")

        if best_box is None:
            self.get_logger().info("No valid TransitionPiece detections found")
        return best_box, best_probability

    def get_standard_box(self, image_shape, image_center_x, image_center_y):
        box_size = cv2.getTrackbarPos("Box Size", 'Canny inside Box')
        box_width = int(box_size * 1.6)
        box_height = box_size
        
        # Ensure box stays within image bounds
        top_left_x = max(0, image_center_x - box_width // 2)
        top_left_y = max(0, image_center_y - box_height // 2)
        bottom_right_x = min(image_shape[1], top_left_x + box_width)
        bottom_right_y = min(image_shape[0], top_left_y + box_height)
        
        return (top_left_x, top_left_y, bottom_right_x, bottom_right_y)

    def scale_box_coordinates(self, x1, y1, x2, y2, original_width, original_height):
        """Scale bounding box coordinates to fit the window size"""
        # Add a scaling factor to make boxes smaller
        scale_factor = 0.5  # Reduce box size by 50%
        
        # Calculate scaling factors
        scale_x = (self.window_width / original_width) * scale_factor
        scale_y = (self.window_height / original_height) * scale_factor
        
        # Calculate center of the box
        center_x = (x1 + x2) / 2
        center_y = (y1 + y2) / 2
        
        # Calculate new width and height
        width = (x2 - x1) * scale_x
        height = (y2 - y1) * scale_y
        
        # Calculate new coordinates centered on the original center
        scaled_x1 = int(center_x - width/2)
        scaled_y1 = int(center_y - height/2)
        scaled_x2 = int(center_x + width/2)
        scaled_y2 = int(center_y + height/2)
        
        # Ensure coordinates are within window bounds
        scaled_x1 = max(0, min(scaled_x1, self.window_width - 1))
        scaled_y1 = max(0, min(scaled_y1, self.window_height - 1))
        scaled_x2 = max(0, min(scaled_x2, self.window_width - 1))
        scaled_y2 = max(0, min(scaled_y2, self.window_height - 1))
        
        self.get_logger().info(f"Original dimensions: {original_width}x{original_height}")
        self.get_logger().info(f"Window dimensions: {self.window_width}x{self.window_height}")
        self.get_logger().info(f"Scaling factors: x={scale_x:.2f}, y={scale_y:.2f}")
        self.get_logger().info(f"Original box: ({x1}, {y1}) to ({x2}, {y2})")
        self.get_logger().info(f"Scaled box: ({scaled_x1}, {scaled_y1}) to ({scaled_x2}, {scaled_y2})")
        
        return scaled_x1, scaled_y1, scaled_x2, scaled_y2

    def filter_roi(self, roi):
        """Apply the same filtering as in MarineSnowRemoval.py"""
        # Converting to YCbCr
        YCrCb = cv2.cvtColor(roi, cv2.COLOR_BGR2YCrCb)
        # Splitting YCrCb image components
        Y, Cr, Cb = cv2.split(YCrCb)
        
        # Applying guided filtering to luminance (Y) component
        Y_guided = guided_filter(Y, radius=32, eps=0.1)
        
        # Remove small spots (marine snow)
        kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (3, 3))
        Y_eroded = cv2.erode(Y_guided, kernel, iterations=1)
        Y_cleaned = cv2.morphologyEx(Y_eroded, cv2.MORPH_CLOSE, kernel)
        
        # Convert back to BGR
        filtered = cv2.merge([Y_cleaned, Cr, Cb])
        filtered = cv2.cvtColor(filtered, cv2.COLOR_YCrCb2BGR)
        
        return filtered

    def image_callback(self, msg):
        try:
            # Convert ROS image message to OpenCV format
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
            if cv_image is None or cv_image.size == 0:
                self.get_logger().error("Received empty image")
                return
                
            image = cv_image.copy()
            image_center_x = image.shape[1] // 2
            image_center_y = image.shape[0] // 2
            
            self.get_logger().info(f"\n=== New Image Callback ===")
            self.get_logger().info(f"Image dimensions: {image.shape[1]}x{image.shape[0]}")
            
            # Create separate images for each visualization
            yolo_image = image.copy()  # For YOLO Detection window
            processed_image = image.copy()  # For Canny inside Box window
            edges_display = np.zeros_like(image)  # For Canny Edges window
            
            # Get current boxes from YOLO
            current_boxes = self.bounding_boxes
            
            # Process YOLO detections
            yolo_result = None
            if current_boxes is not None and len(current_boxes) > 0:
                self.get_logger().info(f"\nProcessing {len(current_boxes)} YOLO boxes")
                for box in current_boxes:
                    if box.class_id == "MooringLine":
                        self.get_logger().info(f"\nProcessing MooringLine box:")
                        self.get_logger().info(f"  Probability: {box.probability:.2f}")
                        self.get_logger().info(f"  Original coordinates: ({box.xmin}, {box.ymin}) to ({box.xmax}, {box.ymax})")
                        
                        # Extract ROI for MooringLine box
                        x1, y1, x2, y2 = int(box.xmin), int(box.ymin), int(box.xmax), int(box.ymax)
                        roi = image[y1:y2, x1:x2]
                        
                        # Apply filtering to MooringLine ROI
                        filtered_roi = self.filter_roi(roi)
                        
                        # Process ROI for line detection
                        yolo_result = self.process_roi(image, x1, y1, x2, y2, True)
                        
                        if yolo_result:
                            # Draw Canny edges in YOLO window
                            edges_roi = cv2.cvtColor(yolo_result['edges'], cv2.COLOR_GRAY2BGR)
                            yolo_image[y1:y2, x1:x2] = edges_roi
                            
                            # Draw mooring line in YOLO window
                            cv2.line(yolo_image, yolo_result['global_point1'], yolo_result['global_point2'], (0, 255, 0), 2)
                            cv2.circle(yolo_image, (yolo_result['mid_x'], yolo_result['mid_y']), 5, (255, 0, 0), -1)
                            
                            # Draw blue box for MooringLine in YOLO window
                            cv2.rectangle(yolo_image, (x1, y1), (x2, y2), (255, 0, 0), 2)
                            cv2.putText(yolo_image, f"{box.class_id} ({box.probability:.2f})", 
                                      (x1, y1 - 10),
                                      cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 0, 0), 2)
                            
                            # Add info text to YOLO window
                            cv2.putText(yolo_image, f'Angle: {yolo_result["angle_deg"]:.2f} degrees', 
                                      (x1, y1 - 30), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 0, 0), 2)
                            cv2.putText(yolo_image, f'Width: {yolo_result["average_width"]:.2f} pixels', 
                                      (x1, y1 - 50), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 0, 0), 2)
                            
                            self.get_logger().info(f"  Drew filtered box for {box.class_id} at original coordinates")
                            
                            # Publish mooring line data from YOLO detection
                            self.publish_mooring_line_data(yolo_result, image_center_x, image_center_y, "YOLO")
                            break
            else:
                self.get_logger().info("\nNo YOLO boxes to process")
            
            # Process standard box if no YOLO detection
            standard_result = None
            if yolo_result is None:
                top_left_x, top_left_y, bottom_right_x, bottom_right_y = self.get_standard_box(image.shape, image_center_x, image_center_y)
                
                # Extract ROI for standard box
                roi = image[top_left_y:bottom_right_y, top_left_x:bottom_right_x]
                
                # Apply filtering to standard box ROI
                filtered_roi = self.filter_roi(roi)
                
                # Process ROI for line detection
                standard_result = self.process_roi(image, top_left_x, top_left_y, bottom_right_x, bottom_right_y, False)
                
                if standard_result:
                    # Draw Canny edges in Canny window
                    edges_roi = cv2.cvtColor(standard_result['edges'], cv2.COLOR_GRAY2BGR)
                    processed_image[top_left_y:bottom_right_y, top_left_x:bottom_right_x] = edges_roi
                    
                    # Draw mooring line in Canny window
                    cv2.line(processed_image, standard_result['global_point1'], standard_result['global_point2'], (0, 255, 0), 2)
                    cv2.circle(processed_image, (standard_result['mid_x'], standard_result['mid_y']), 5, (255, 0, 0), -1)
                    
                    # Draw red box for standard detection in Canny window
                    cv2.rectangle(processed_image, (top_left_x, top_left_y), 
                                (bottom_right_x, bottom_right_y), (0, 0, 255), 2)
                    cv2.putText(processed_image, "Standard Box", 
                              (top_left_x, top_left_y - 10),
                              cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 2)
                    
                    # Add info text to Canny window
                    cv2.putText(processed_image, f'Angle: {standard_result["angle_deg"]:.2f} degrees', 
                              (top_left_x, top_left_y - 30), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 2)
                    cv2.putText(processed_image, f'Width: {standard_result["average_width"]:.2f} pixels', 
                              (top_left_x, top_left_y - 50), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 2)
                    
                    # Publish mooring line data from standard box detection
                    self.publish_mooring_line_data(standard_result, image_center_x, image_center_y, "Standard")
            
            # Show all windows with their specific content
            if cv2.getWindowProperty('YOLO Detection', cv2.WND_PROP_VISIBLE) >= 0:
                cv2.imshow("YOLO Detection", yolo_image)
                cv2.resizeWindow('YOLO Detection', self.window_width, self.window_height)
            else:
                self.get_logger().error("YOLO Detection window is not visible")
            
            if cv2.getWindowProperty('Canny inside Box', cv2.WND_PROP_VISIBLE) >= 0:
                cv2.imshow("Canny inside Box", processed_image)
                cv2.resizeWindow('Canny inside Box', self.window_width, self.window_height)
            else:
                self.get_logger().error("Canny inside Box window is not visible")
            
            if cv2.getWindowProperty('Canny Edges', cv2.WND_PROP_VISIBLE) >= 0:
                cv2.imshow("Canny Edges", edges_display)
                cv2.resizeWindow('Canny Edges', self.window_width, self.window_height)
            else:
                self.get_logger().error("Canny Edges window is not visible")
            
            cv2.waitKey(1)

        except Exception as e:
            self.get_logger().error(f"Error processing image: {e}")

    def publish_mooring_line_data(self, result, image_center_x, image_center_y, detection_type):
        """Publish mooring line data for control system"""
        msg = YoloCannyChainPose()
        
        # Calculate relative position from image center
        msg.mid_x = float(result['mid_x'] - image_center_x)
        msg.mid_y = float(image_center_y - result['mid_y'])
        msg.angle_degrees = float(result['angle_deg'])
        msg.detection_type = detection_type
        msg.width = float(result['average_width'])
        
        # Publish the message
        self.mooring_line_publisher.publish(msg)
        self.get_logger().info(
            f"Published: mid_x={msg.mid_x:.2f}, width={msg.width:.2f}, type={detection_type}"
        )

def main():
    rclpy.init()
    blueye_img = BlueyeImage()
    rclpy.spin(blueye_img)
    blueye_img.destroy_node()
    rclpy.shutdown()
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main() 