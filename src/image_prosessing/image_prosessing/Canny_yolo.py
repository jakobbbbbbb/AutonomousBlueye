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
        self.bbox_subscriber = self.create_subscription(BoundingBoxes, '/yolov5_ros/detections', self.bbox_callback, 10)
        self.YoloChainPose_publisher = self.create_publisher(YoloCannyChainPose, 'YoloCannyChainPose', 10)
        
        # Create windows and trackbars
        cv2.namedWindow('YOLO Detection', cv2.WINDOW_NORMAL)
        cv2.resizeWindow('YOLO Detection', 960, 600)  # Updated size
        
        cv2.namedWindow('Canny inside Yolo', cv2.WINDOW_NORMAL)
        cv2.resizeWindow('Canny inside Yolo', 960, 600)  # Updated size
        
        cv2.namedWindow('Canny Edges', cv2.WINDOW_NORMAL)
        cv2.resizeWindow('Canny Edges', 960, 600)  # Updated size
        
        cv2.createTrackbar("Lower Threshold", "Canny inside Yolo", 6, 255, nothing)
        cv2.createTrackbar("Upper Threshold", "Canny inside Yolo", 9, 255, nothing)
        cv2.createTrackbar("Box Size", "Canny inside Yolo", 800, 1000, nothing)

    def bbox_callback(self, msg):
        self.bounding_boxes = msg.bounding_boxes
        self.get_logger().info(f"Received {len(msg.bounding_boxes)} bounding boxes")
        for box in msg.bounding_boxes:
            self.get_logger().info(f"Box: class={box.class_id}, prob={box.probability:.2f}, coords=({box.xmin},{box.ymin})-({box.xmax},{box.ymax})")

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
        lower_thresh = cv2.getTrackbarPos("Lower Threshold", 'Canny inside Yolo')
        upper_thresh = cv2.getTrackbarPos("Upper Threshold", 'Canny inside Yolo')
        
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

    def image_callback(self, msg):
        image = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
        yolo_image = image.copy()  # For YOLO visualization
        processed_image = image.copy()  # For final visualization
        edges_display = np.zeros_like(image)  # For displaying Canny edges
        
        image_center_x, image_center_y = image.shape[1] // 2, image.shape[0] // 2

        # Check if windows are closed
        if (cv2.getWindowProperty('Canny inside Yolo', cv2.WND_PROP_VISIBLE) < 1 or
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
            
            # Find the best MooringLine box
            for box in current_boxes:
                if box.class_id == "MooringLine" and box.probability > best_probability:
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
                    result = self.process_roi(image, x1, y1, x2, y2, True)
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
            box_size = cv2.getTrackbarPos("Box Size", 'Canny inside Yolo')
            box_width = int(box_size * 1.6)
            box_height = box_size
            
            # Ensure box stays within image bounds
            top_left_x = max(0, image_center_x - box_width // 2)
            top_left_y = max(0, image_center_y - box_height // 2)
            bottom_right_x = min(image.shape[1], top_left_x + box_width)
            bottom_right_y = min(image.shape[0], top_left_y + box_height)
            
            # Only process if box has valid size
            if bottom_right_x > top_left_x and bottom_right_y > top_left_y:
                result = self.process_roi(image, top_left_x, top_left_y, bottom_right_x, bottom_right_y, False)
                if result:
                    box_type = "Standard"
                    box_color = (0, 0, 255)  # Red for standard box
                    edges_roi = result['edges']
                    
                    # Draw standard box
                    cv2.rectangle(processed_image, (top_left_x, top_left_y), (bottom_right_x, bottom_right_y), box_color, 2)
                    cv2.putText(processed_image, "Active Standard Box", (top_left_x, top_left_y - 10), 
                              cv2.FONT_HERSHEY_SIMPLEX, 0.5, box_color, 2)
                    
                    # Show edges in the edges display
                    edges_display[top_left_y:bottom_right_y, top_left_x:bottom_right_x] = cv2.cvtColor(edges_roi, cv2.COLOR_GRAY2BGR)

        if result:
            # Draw the line and info on both YOLO and processed images
            for img in [yolo_image, processed_image]:
                # Draw the line
                cv2.line(img, result['global_point1'], result['global_point2'], (0, 255, 0), 2)
                
                # Draw midpoint
                cv2.circle(img, (result['mid_x'], result['mid_y']), 5, (255, 0, 0), -1)
                
                # Add status text
                status_text = f"Box Type: {box_type} | Line Found: Yes"
                cv2.putText(img, status_text, (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
                
                # Add position and angle info
                cv2.putText(img, f'Midpoint: ({result["mid_x"]}, {result["mid_y"]})', (10, 50), 
                           cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
                cv2.putText(img, f'Angle: {result["angle_deg"]:.2f} degrees', (10, 70), 
                           cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
                cv2.putText(img, f'Width: {result["average_width"]:.2f} pixels', (10, 90), 
                           cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
            
            # Publish pose
            pose_msg = YoloCannyChainPose()
            pose_msg.mid_x = float(result['mid_x'] - image_center_x)
            pose_msg.mid_y = float(image_center_y - result['mid_y'])
            pose_msg.angle_degrees = float(result['angle_deg'])
            self.YoloChainPose_publisher.publish(pose_msg)

            # Show Canny edges inside the box
            if edges_roi is not None:
                # Convert edges to BGR for visualization
                edges_bgr = cv2.cvtColor(edges_roi, cv2.COLOR_GRAY2BGR)
                
                # Get the box dimensions and ROI based on box type
                if box_type == "YOLO":
                    box_width = x2 - x1
                    box_height = y2 - y1
                    roi = processed_image[y1:y2, x1:x2]
                else:
                    box_width = bottom_right_x - top_left_x
                    box_height = bottom_right_y - top_left_y
                    roi = processed_image[top_left_y:bottom_right_y, top_left_x:bottom_right_x]
                
                # Only process if ROI has valid size
                if box_width > 0 and box_height > 0:
                    # Resize edges to match box size
                    edges_bgr = cv2.resize(edges_bgr, (box_width, box_height))
                    
                    # Blend edges with original image
                    alpha = 0.5
                    blended = cv2.addWeighted(roi, 1-alpha, edges_bgr, alpha, 0)
                    
                    # Put blended image back
                    if box_type == "YOLO":
                        processed_image[y1:y2, x1:x2] = blended
                    else:
                        processed_image[top_left_y:bottom_right_y, top_left_x:bottom_right_x] = blended
        else:
            # Add status text when no line is found
            status_text = f"Box Type: {box_type} | Line Found: No"
            cv2.putText(processed_image, status_text, (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 2)
            cv2.putText(yolo_image, status_text, (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 2)

        # Show all windows
        cv2.imshow("YOLO Detection", yolo_image)  # Shows all YOLO boxes
        cv2.imshow("Canny inside Yolo", processed_image)  # Shows active box and processing
        cv2.imshow("Canny Edges", edges_display)  # Shows just the Canny edges
        cv2.waitKey(1)

def main():
    rclpy.init()
    blueye_img = BlueyeImage()
    rclpy.spin(blueye_img)
    blueye_img.destroy_node()
    rclpy.shutdown()
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main() 