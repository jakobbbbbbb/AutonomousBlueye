#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np
from robot_interfaces.msg import YoloCannyChainPose
from bboxes_ex_msgs.msg import BoundingBoxes
import math
from std_msgs.msg import Float32
from geometry_msgs.msg import Twist
from experimental.Guided_Filter import guided_filter

def nothing(x):
    pass

class BlueyeImage(Node):
    def __init__(self):
        super().__init__('blueye_image')
        
        # Initialize the CV bridge
        self.bridge = CvBridge()
        
        # Create subscribers
        self.image_sub = self.create_subscription(
            Image,
            '/camera',
            self.image_callback,
            10)
        
        # Subscribe to YOLO detections
        self.bbox_subscriber = self.create_subscription(
            BoundingBoxes,
            '/yolov5/bounding_boxes',
            self.bbox_callback,
            10
        )
        
        # Create publisher for line detection results
        self.pose_pub = self.create_publisher(YoloCannyChainPose, '/YoloCannyChainPose', 10)
        self.velocity_pub = self.create_publisher(Twist, '/desired_velocity', 10)
        self.line_angle_pub = self.create_publisher(Float32, '/line_angle', 10)
        
        # Set consistent window sizes
        self.window_width = 960
        self.window_height = 600
        
        # Create windows for visualization
        cv2.namedWindow('Line Detection', cv2.WINDOW_NORMAL)
        cv2.resizeWindow('Line Detection', self.window_width, self.window_height)
        
        # Create trackbars
        cv2.createTrackbar('Min Threshold', 'Line Detection', 6, 255, nothing)
        cv2.createTrackbar('Max Threshold', 'Line Detection', 9, 255, nothing)
        cv2.createTrackbar('Box Size', 'Line Detection', 800, 1000, nothing)
        cv2.createTrackbar('CLAHE Limit', 'Line Detection', 15, 40, nothing)
        
        # Initialize shackle detection state
        self.shackle_detected = False
        
        self.get_logger().info('Blueye image node initialized')

    def bbox_callback(self, msg):
        """Handle YOLO detection results"""
        self.shackle_detected = False
        for box in msg.bounding_boxes:
            if box.class_id == "shackle" and box.probability > 0.1:
                self.shackle_detected = True
                self.get_logger().info("Shackle detected with confidence: {:.2f}".format(box.probability))
                break

    def process_roi(self, roi):
        """Process the region of interest to detect lines using enhanced image processing."""
        try:
            # Convert to YCrCb color space for better color separation
            YCrCb = cv2.cvtColor(roi, cv2.COLOR_BGR2YCrCb)
            Y, Cr, Cb = cv2.split(YCrCb)

            # Apply CLAHE with fixed clip limit
            clahe = cv2.createCLAHE(clipLimit=1.5, tileGridSize=(8, 8))
            Y_clahe = clahe.apply(Y)

            # Apply guided filter for noise reduction while preserving edges
            Y_guided = guided_filter(Y_clahe, radius=32, eps=0.6)

            # Remove small spots (marine snow) using kernel
            kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (3, 3))
            Y_eroded = cv2.erode(Y_guided, kernel, iterations=1)
            Y_cleaned = cv2.morphologyEx(Y_eroded, cv2.MORPH_CLOSE, kernel)

            # Get Canny thresholds from trackbars
            min_val = cv2.getTrackbarPos('Min Threshold', 'Line Detection')
            max_val = cv2.getTrackbarPos('Max Threshold', 'Line Detection')

            # Apply Canny edge detection
            edges = cv2.Canny(Y_cleaned, min_val, max_val)

            # Find white pixels within the ROI
            white_pixels = np.column_stack(np.where(edges == 255))
            if white_pixels.size > 0:
                white_pixels[:, [0, 1]] = white_pixels[:, [1, 0]]  # Swap columns to get (x, y) coordinates

                # Fit line to the points
                [vx, vy, x0, y0] = cv2.fitLine(white_pixels, cv2.DIST_L2, 0, 0.01, 0.01)
                angle_rad = math.atan2(vy, vx)
                angle_deg = math.degrees(angle_rad) - 90  # Offset by 90 degrees

                # Normalize angle to -90 to 90 degrees
                if angle_deg > 90:
                    angle_deg = 180 - angle_deg

                # Calculate line endpoints for visualization
                length = max(1000, int(math.sqrt(roi.shape[0]**2 + roi.shape[1]**2)))
                point1 = (int(x0 - vx * length), int(y0 - vy * length))
                point2 = (int(x0 + vx * length), int(y0 + vy * length))

                # Calculate average width of the line
                row_white_pixel_counts = np.sum(edges == 255, axis=1)
                average_width = np.mean(row_white_pixel_counts) * 10 if row_white_pixel_counts.size > 0 else 0

                return {
                    'edges': edges,
                    'angle_deg': angle_deg,
                    'average_width': average_width,
                    'mid_x': int(x0),
                    'mid_y': int(y0),
                    'global_point1': point1,
                    'global_point2': point2,
                    'success': True
                }
            else:
                self.get_logger().warning('No edges detected in ROI')
                # Log no detection status
                self.get_logger().info(
                    f"Detection - No line detected in ROI"
                )
                return {
                    'success': False,
                    'edges': edges
                }
                
        except Exception as e:
            self.get_logger().error(f'Error in process_roi: {str(e)}')
            return {'success': False}

    def image_callback(self, msg):
        try:
            # Convert ROS Image message to OpenCV image
            cv_image = self.bridge.imgmsg_to_cv2(msg, "bgr8")
            
            # Resize image to match window size
            cv_image = cv2.resize(cv_image, (self.window_width, self.window_height))
            
            # Get image dimensions and center
            height, width = cv_image.shape[:2]
            image_center_x, image_center_y = width // 2, height // 2
            
            # Get box size from trackbar and calculate dimensions
            box_size = cv2.getTrackbarPos('Box Size', 'Line Detection')
            box_width = int(box_size * 1.6)
            box_height = box_size
            
            # Calculate ROI coordinates (centered box)
            top_left_x = max(0, image_center_x - box_width // 2)
            top_left_y = max(0, image_center_y - box_height // 2)
            bottom_right_x = top_left_x + box_width
            bottom_right_y = top_left_y + box_height
            
            # Create display images
            display_img = cv_image.copy()
            
            # Draw ROI rectangle
            cv2.rectangle(display_img, (top_left_x, top_left_y), 
                        (bottom_right_x, bottom_right_y), (0, 255, 0), 2)
            
            # Process ROI if box has valid size
            if bottom_right_x > top_left_x and bottom_right_y > top_left_y:
                roi = cv_image[top_left_y:bottom_right_y, top_left_x:bottom_right_x]
                result = self.process_roi(roi)
                
                if result.get('success', False):
                    # Adjust coordinates to global image space
                    mid_x = result['mid_x'] + top_left_x
                    mid_y = result['mid_y'] + top_left_y
                    
                    # Calculate centered coordinates
                    centered_x = mid_x - width // 2
                    centered_y = (height // 2) - mid_y
                    
                    # Draw circle at midpoint
                    cv2.circle(display_img, (mid_x, mid_y), 5, (0, 0, 255), -1)
                    
                    # Draw line using global points
                    if 'global_point1' in result and 'global_point2' in result:
                        point1 = (result['global_point1'][0] + top_left_x, result['global_point1'][1] + top_left_y)
                        point2 = (result['global_point2'][0] + top_left_x, result['global_point2'][1] + top_left_y)
                        cv2.line(display_img, point1, point2, (255, 0, 0), 2)
                    
                    # Add text annotations
                    cv2.putText(display_img, f'Angle: {result["angle_deg"]:.1f}°', 
                              (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
                    cv2.putText(display_img, f'Coords(X,Y): ({centered_x:.1f}, {centered_y:.1f})', 
                              (10, 50), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
                    cv2.putText(display_img, f'Width: {result["average_width"]:.1f}px', 
                              (10, 70), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
                    
                    
                    # Show edges in the ROI with transparency
                    if 'edges' in result:
                        edges_color = cv2.cvtColor(result['edges'], cv2.COLOR_GRAY2BGR)
                        # Blend edges with original image in ROI
                        alpha = 0.8  # Transparency factor
                        roi_region = display_img[top_left_y:bottom_right_y, top_left_x:bottom_right_x]
                        blended = cv2.addWeighted(roi_region, 1-alpha, edges_color, alpha, 0)
                        display_img[top_left_y:bottom_right_y, top_left_x:bottom_right_x] = blended
                    
                    # Publish detection results
                    pose_msg = YoloCannyChainPose()
                    # Store values in data array: [centered_x, centered_y, angle_degrees, width]
                    pose_msg.data = [
                        float(centered_x),  # Normalized centered_x
                        float(centered_y),  # Normalized centered_y
                        float(result['angle_deg']),  # angle_degrees
                        float(result['average_width'])  # width
                    ]
                    pose_msg.detection_type = "line"
                    pose_msg.turn_direction = "left" if result['angle_deg'] < 0 else "right"
                    pose_msg.shackle_detected = self.shackle_detected
                    self.pose_pub.publish(pose_msg)
                    
                    # Log detection results
                    self.get_logger().info(
                        f"Detection - "
                        f"Coords(X,Y): ({centered_x:.1f}, {centered_y:.1f}), "
                        f"Angle: {result['angle_deg']:.1f}°, "
                        f"Width: {result['average_width']:.1f}px, "
                        f"Shackle: {'Detected' if self.shackle_detected else 'Not Detected'}"
                    )
            
            # Display the image
            cv2.imshow('Line Detection', display_img)
            cv2.waitKey(1)
            
        except Exception as e:
            self.get_logger().error(f'Error in image_callback: {str(e)}')

def main(args=None):
    rclpy.init(args=args)
    node = BlueyeImage()
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