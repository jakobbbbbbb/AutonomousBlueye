#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from robot_interfaces.msg import DesiredVelocity, ThreshChainPos, CannyChainPos, YoloCannyChainPose, BoundingBoxes
import cv2
import numpy as np
import threading
from geometry_msgs.msg import Quaternion
from std_msgs.msg import Float32, Bool
import csv
import os
import time

def nothing(x):
    pass

class ChainPosController(Node):
    def __init__(self):
        super().__init__('chain_pos_controller')
        
        # Publishers
        self.vel_publisher = self.create_publisher(DesiredVelocity, '/desired_velocity', 10)
        self.desired_width_publisher = self.create_publisher(Float32, '/desired_width', 10)
        self.led_publisher = self.create_publisher(Float32, '/set_led_brightness', 10)
        self.frame_brightness_pub = self.create_publisher(Float32, '/frame_brightness', 10)

        # Initialize desired_vel object
        self.desired_vel = DesiredVelocity()
        self.desired_vel.surge = 0.0
        self.desired_vel.sway = 0.0
        self.desired_vel.heave = 0.0
        self.desired_vel.yaw = 0.0

        # Control values dictionary
        self.control_values = {
            'surge': 0.0,
            'sway': 0.0,
            'heave': 0.0,
            'yaw': 0.0
        }

        # Line control parameters
        self.desired_width = 150  # Default desired width
        self.width_threshold = 20  # Minimum width to consider line visible
        self.width = 0
        self.line_lost_time = None
        self.failsafe_triggered = False
        self.failsafe_timeout = 20
        self.last_normalized_mid_x = 0
        self.reached_target_depth = False
        self.desired_depth = 50  # Default desired depth

        # Log file setup
        self.log_dir = os.path.join(os.path.expanduser('~'), 'logs')
        os.makedirs(self.log_dir, exist_ok=True)
        self.log_file = os.path.join(self.log_dir, 'control_log.csv')
        
        # Initialize log file with headers if it doesn't exist
        if not os.path.exists(self.log_file):
            with open(self.log_file, 'w', newline='') as file:
                writer = csv.writer(file)
                writer.writerow(['timestamp', 'surge', 'sway', 'heave', 'yaw', 'depth', 'yaw_angle', 'desired_depth','desired_width', 'width'])

        # Available topics and current topic
        self.topics = {
            0: 'ZERO_OUTPUT',
            1: '/thresh_chain_pos',
            2: '/canny_chain_pos',
            3: '/YoloCannyChainPose'
        }
        self.current_topic = 'ZERO_OUTPUT'
        self.current_subscription = None
        
        # Subscribers
        self.depth_sub = self.create_subscription(Quaternion, 'BlueyePose', self.depth_callback, 10)
        self.led_brightness_sub = self.create_subscription(Float32, '/set_led_brightness', self.led_brightness_callback, 10)
        self.frame_brightness_sub = self.create_subscription(Float32, '/frame_brightness', self.frame_brightness_callback, 10)
        self.line_angle = self.create_subscription(Float32, '/line_angle', self.line_angle_callback, 10)
        self.reverse_sub = self.create_subscription(Bool, '/reverse_command', self.reverse_callback, 10)
        self.bbox_sub = self.create_subscription(BoundingBoxes, '/yolov5/bounding_boxes', self.bbox_callback, 10)

        # Initialize variables
        self.current_depth = 0.0
        self.frame_brightness = 128.0
        self.desired_led = 0.5
        self.angle_rad = 0.0
        self.shackle_detected = False
        self.heave_direction = 1  # -1 for up, 1 for down
        self.shackle_action = None  # 'ned', 'opp', eller None

        # Control gains
        self.surge_gain = 1.0
        self.sway_gain = 1.0
        self.heave_gain = 1.0
        self.yaw_gain = 1.0

        # Start GUI in a separate thread
        self.start_gui()

        # Added for mouse callback
        self.ned_rect = (10, 550, 200, 60)
        self.opp_rect = (220, 550, 200, 60)
        self.last_mouse_event = None

        self.inspection_mode = False
        self.inspection_target_width = None
        self.original_desired_width = self.desired_width
        self.inspection_rect = (430, 550, 200, 60)

    def switch_subscription(self, index):
        """Switch the current subscription to a different topic"""
        topic = self.topics.get(index, 'ZERO_OUTPUT')
        
        if topic == 'ZERO_OUTPUT':
            if self.current_subscription is not None:
                self.destroy_subscription(self.current_subscription)
                self.current_subscription = None
            self.publish_velocity(0.0, 0.0, 0.0, 0.0)
            self.current_topic = 'ZERO_OUTPUT'
        else:
            if self.current_topic == 'ZERO_OUTPUT' or self.current_subscription is None:
                self.create_new_subscription(topic)
            elif self.current_topic != topic:
                self.destroy_subscription(self.current_subscription)
                self.create_new_subscription(topic)

    def create_new_subscription(self, topic):
        """Create a new subscription based on the topic"""
        if topic == '/thresh_chain_pos':
            self.current_subscription = self.create_subscription(
                ThreshChainPos,
                topic,
                self.thresh_callback,
                10)
        elif topic == '/canny_chain_pos':
            self.current_subscription = self.create_subscription(
                CannyChainPos,
                topic,
                self.canny_callback,
                10)
        elif topic == '/YoloCannyChainPose':
            self.current_subscription = self.create_subscription(
                YoloCannyChainPose,
                topic,
                self.mooring_line_callback,
                #self.line_control,
                10)
        self.current_topic = topic
        self.get_logger().info(f'Switched to topic: {topic}')

    def thresh_callback(self, msg):
        """Handle threshold-based chain position data"""
        try:
            # Extract values from data array: [mid_x, mid_y, angle_degrees]
            if len(msg.data) >= 3:
                mid_x = msg.data[0]
                mid_y = msg.data[1]
                angle_degrees = msg.data[2]
                
                # Calculate control values from normalized coordinates [0,1]
                # Convert to [-1,1] range for control
                self.control_values['sway'] = (mid_x - 0.5) * 2 * self.sway_gain
                self.control_values['yaw'] = (angle_degrees / 90.0) * self.yaw_gain
                self.control_values['heave'] = (mid_y - 0.5) * 2 * self.heave_gain * self.heave_direction
                self.control_values['surge'] = 0.5 * self.surge_gain

                # Publish velocity
                self.publish_velocity(
                    self.control_values['surge'],
                    self.control_values['sway'],
                    self.control_values['yaw'],
                    self.control_values['heave']
                )
            else:
                self.get_logger().error("Received data array with insufficient elements in thresh_callback")
        except Exception as e:
            self.get_logger().error(f"Error in thresh_callback: {str(e)}")

    def canny_callback(self, msg):
        """Handle Canny-based chain position data"""
        try:
            # Extract values from data array: [mid_x, mid_y, angle_degrees]
            if len(msg.data) >= 3:
                mid_x = msg.data[0]
                mid_y = msg.data[1]
                angle_degrees = msg.data[2]
                
                # Calculate control values from normalized coordinates [0,1]
                # Convert to [-1,1] range for control
                self.control_values['sway'] = (mid_x - 0.5) * 2 * self.sway_gain
                self.control_values['yaw'] = (angle_degrees / 90.0) * self.yaw_gain
                self.control_values['heave'] = (mid_y - 0.5) * 2 * self.heave_gain * self.heave_direction
                self.control_values['surge'] = 0.5 * self.surge_gain

                # Publish velocity
                self.publish_velocity(
                    self.control_values['surge'],
                    self.control_values['sway'],
                    self.control_values['yaw'],
                    self.control_values['heave']
                )
            else:
                self.get_logger().error("Received data array with insufficient elements in canny_callback")
        except Exception as e:
            self.get_logger().error(f"Error in canny_callback: {str(e)}")

    def mooring_line_callback(self, msg):
        """Handle mooring line data messages"""
        try:
            # Update shackle detection status from the message
            self.shackle_detected = msg.shackle_detected
            self.get_logger().info(f"Shackle detected: {self.shackle_detected}")
            # Reset shackle_action if shackle is not detected
            if not self.shackle_detected:
                self.shackle_action = None
            
            if len(msg.data) >= 4:
                # Extract values from data array: [centered_x, centered_y, angle_degrees, width]
                centered_x = msg.data[0]
                centered_y = msg.data[1]
                angle_degrees = msg.data[2]
                width = msg.data[3]
                self.width = width
                # Calculate normalized mid_x
                normalized_mid_x = centered_x / 960
                width_threshold = max(self.desired_width, 1)  # Prevent divide-by-zero
                
                # Set default values
                surge = 0.0
                sway = 0.0
                heave = 0.0
                yaw = 0.0
                
                # Update last known position if the object is visible
                if width > 20:
                    self.line_lost_time = None
                    self.failsafe_triggered = False
                    self.last_normalized_mid_x = normalized_mid_x
                    
                    sway = normalized_mid_x * self.sway_gain
                    surge = (1 - width / width_threshold) * self.surge_gain if width <= width_threshold else -((width - width_threshold) / 200.0) * self.surge_gain
                    yaw = normalized_mid_x * self.yaw_gain

                    # Inspection mode løkke
                    if self.inspection_mode:
                        if width >= self.inspection_target_width:
                            self.desired_width = self.original_desired_width
                            cv2.setTrackbarPos("Desired Width", 'Control', self.desired_width // 10)
                            self.inspection_mode = False
                            self.get_logger().info("Inspection finished, back to original desired width.")
                        heave = self.heave_direction * abs(self.heave_gain * np.cos(np.abs(np.deg2rad(angle_degrees))))
                    elif self.shackle_detected:
                        heave = self.heave_direction * abs(self.heave_gain * np.cos(np.abs(np.deg2rad(angle_degrees ))))
                    else:
                        heave = self.heave_direction * abs(self.heave_gain * np.cos(np.abs(np.deg2rad(angle_degrees))))
                else:
                    now = time.time()
                    if self.line_lost_time is None:
                        self.line_lost_time = now
                    
                    if (now - self.line_lost_time) > self.failsafe_timeout and not self.failsafe_triggered:
                        self.failsafe_triggered = True
                        self.failsafe_mode()
                
                # Update control_values dictionary for GUI display
                self.control_values['surge'] = surge
                self.control_values['sway'] = sway
                self.control_values['heave'] = heave
                self.control_values['yaw'] = yaw
                
                # Log control values
                self.get_logger().info(
                    f"Control values - "
                    f"Surge: {surge:.3f}, "
                    f"Sway: {sway:.3f}, "
                    f"Yaw: {yaw:.3f}, "
                    f"Heave: {heave:.3f}, "
                    f"Width: {width:.1f}px"
                    f"Angle: {angle_degrees:.1f}°"
                )
                
                # Publish velocity
                self.publish_velocity(surge, sway, yaw, heave)
            else:
                self.get_logger().error("Received data array with insufficient elements")
        except Exception as e:
            self.get_logger().error(f"Error in mooring_line_callback: {str(e)}")

    def bbox_callback(self, msg):
        """Handle bounding box messages"""
        # Remove redundant shackle detection cosce it's now handled by YoloCannyChainPose
        pass

    def start_gui(self):
        """Start GUI in a separate thread"""
        threading.Thread(target=self.setup_gui, daemon=True).start()

    def setup_gui(self):
        """Setup GUI window with trackbars and display"""
        cv2.namedWindow('Control', cv2.WINDOW_NORMAL)
        cv2.resizeWindow('Control', 600, 800)

        # Create trackbars
        cv2.createTrackbar("Surge Gain", 'Control', 5, 20, nothing)
        cv2.createTrackbar("Sway Gain", 'Control', 10, 20, nothing)
        cv2.createTrackbar("Heave Gain", 'Control', 3, 20, nothing)
        cv2.createTrackbar("Yaw Gain", 'Control', 2, 100, nothing)
        cv2.createTrackbar("Desired Width", 'Control', 15, 30, nothing)
        cv2.createTrackbar("LED Brightness", 'Control', 50, 100, nothing)
        cv2.createTrackbar("Desired Depth", 'Control', 50, 100, nothing)
        cv2.createTrackbar("Heave Direction (0:Down 1:Up)", 'Control', 0, 1, self.heave_direction_callback)
        cv2.createTrackbar("Toggle Topic", 'Control', 0, 3, lambda x: self.switch_subscription(x))

        cv2.setMouseCallback('Control', self.mouse_callback)

        while True:
            self.update_gains_from_trackbars()
            canvas = np.zeros((800, 600, 3), dtype=np.uint8)
            
            # Layout settings
            font_scale = 1.0
            line_space = 40
            start_y = 150

            # Display information
            cv2.putText(canvas, f"Current Topic: {self.current_topic}", (10, start_y - line_space), 
                       cv2.FONT_HERSHEY_SIMPLEX, font_scale, (255, 255, 255), 2)

            # Control Parameters
            cv2.putText(canvas, f"Depth: {self.current_depth:.2f}", (10, start_y), 
                       cv2.FONT_HERSHEY_SIMPLEX, font_scale, (255, 255, 255), 2)
            cv2.putText(canvas, f"Desired Depth: {self.desired_depth}", (300, start_y), 
                       cv2.FONT_HERSHEY_SIMPLEX, font_scale, (255, 255, 255), 2)

            # Control Values and Gains
            for i, param in enumerate(['surge', 'sway', 'heave', 'yaw']):
                y_pos = start_y + (i + 1) * line_space
                cv2.putText(canvas, f"{param.capitalize()}: {self.control_values[param]:.2f}", 
                           (10, y_pos), cv2.FONT_HERSHEY_SIMPLEX, font_scale, (255, 255, 255), 2)
                cv2.putText(canvas, f"{param.capitalize()} Gain: {getattr(self, f'{param}_gain'):.1f}", 
                           (300, y_pos), cv2.FONT_HERSHEY_SIMPLEX, font_scale, (255, 255, 255), 2)

            # Additional Parameters
            y_pos = start_y + 5 * line_space
            cv2.putText(canvas, f"Desired Width: {self.desired_width}", (10, y_pos), 
                       cv2.FONT_HERSHEY_SIMPLEX, font_scale, (255, 255, 255), 2)

            y_pos = start_y + 6 * line_space
            cv2.putText(canvas, f"LED Brightness: {self.desired_led:.2f}", (10, y_pos), 
                       cv2.FONT_HERSHEY_SIMPLEX, font_scale, (0, 255, 255), 2)

            # Shackle Detection Status
            y_pos = start_y + 7 * line_space
            status_color = (0, 255, 0) if self.shackle_detected else (0, 0, 255)
            cv2.putText(canvas, f"Shackle Detected: {'Yes' if self.shackle_detected else 'No'}", 
                       (10, y_pos), cv2.FONT_HERSHEY_SIMPLEX, font_scale, status_color, 2)

            # Heave Direction
            y_pos = start_y + 8 * line_space
            cv2.putText(canvas, f"Heave Direction: {'Up' if self.heave_direction == -1 else 'Down'}", 
                       (10, y_pos), cv2.FONT_HERSHEY_SIMPLEX, font_scale, (255, 255, 255), 2)

            self.handle_shackle_buttons(canvas, y_pos)

            cv2.imshow('Control', canvas)
            if cv2.waitKey(50) == 27:  # Exit on ESC
                break

    def update_gains_from_trackbars(self):
        """Update control gains and parameters from trackbar values"""
        self.surge_gain = cv2.getTrackbarPos("Surge Gain", 'Control') / 10.0
        self.sway_gain = cv2.getTrackbarPos("Sway Gain", 'Control') / 10.0
        self.heave_gain = cv2.getTrackbarPos("Heave Gain", 'Control') / 10.0
        self.yaw_gain = cv2.getTrackbarPos("Yaw Gain", 'Control') / 10.0
        self.desired_width = cv2.getTrackbarPos("Desired Width", 'Control') * 10
        self.desired_depth = cv2.getTrackbarPos("Desired Depth", 'Control')
        self.desired_led = cv2.getTrackbarPos("LED Brightness", 'Control') / 100.0

        # Publish desired width
        width_msg = Float32()
        width_msg.data = float(self.desired_width)
        self.desired_width_publisher.publish(width_msg)

    def heave_direction_callback(self, value):
        """Handle heave direction changes from trackbar"""
        self.heave_direction = 1 if value == 0 else -1
        self.get_logger().info(f"Heave direction changed to: {'Up' if self.heave_direction == -1 else 'Down'}")

    def publish_velocity(self, surge, sway, yaw, heave):
        """Publish velocity commands"""
        self.desired_vel.surge = surge
        self.desired_vel.sway = sway
        self.desired_vel.heave = heave
        self.desired_vel.yaw = yaw
        self.vel_publisher.publish(self.desired_vel)

        try:
            # Log PID-data to CSV-file
            current_time = self.get_clock().now().to_msg().sec
            depth = self.current_depth
            yaw_angle = self.angle_rad

            with open(self.log_file, 'a', newline='') as file:
                self.get_logger().info(f"Writing to log file: {self.log_file}")
                writer = csv.writer(file)
                writer.writerow([current_time, surge, sway, heave, yaw, depth, yaw_angle, self.desired_depth, self.desired_width, self.width])
        except Exception as e:
            self.get_logger().error(f"Error writing to log file: {str(e)}")

    def depth_callback(self, msg):
        """Handle depth data"""
        self.current_depth = msg.w

    def led_brightness_callback(self, msg):
        """Handle LED brightness updates"""
        self.desired_led = msg.data

    def frame_brightness_callback(self, msg):
        """Handle frame brightness updates"""
        self.frame_brightness = msg.data

    def line_angle_callback(self, msg):
        """Handle line angle updates"""
        self.angle_rad = msg.data[2]

    def reverse_callback(self, msg):
        """Handle reverse command"""
        if msg.data:
            self.heave_direction *= -1

    def line_control(self, msg):
        """Control ROV based on line detection"""
        try:
            # Extract values from data array
            if len(msg.data) >= 4:
                mid_x = msg.data[0]
                mid_y = msg.data[1]
                angle_degrees = msg.data[2]
                width = msg.data[3]
                
                # Normalize mid_x to [0,1]
                normalized_mid_x = mid_x / 960
                width_threshold = max(self.desired_width, 1)  # Prevent divide-by-zero
                
                # Set default values
                surge = 0.0
                sway = 0.0
                heave = 0.0
                yaw = 0.0
                
                # Update last known position if the object is visible
                if width > self.width_threshold:
                    self.line_lost_time = None
                    self.failsafe_triggered = False
                    self.last_normalized_mid_x = normalized_mid_x
                    
                    # Calculate control values
                    sway = (normalized_mid_x)* self.sway_gain
                    surge = (1 - width / width_threshold) * self.surge_gain if width <= width_threshold else -((width - width_threshold) / 200.0) * self.surge_gain
                    yaw = normalized_mid_x * self.yaw_gain
                    
                    # Depth control
                    if not self.reached_target_depth:
                        heave = self.heave_gain * np.cos(np.abs(self.angle_rad))
                        if self.current_depth >= self.desired_depth:
                            self.reached_target_depth = True
                            self.get_logger().info(f"Reached desired depth {self.current_depth:.2f}m → Switching to ascent.")
                    else:
                        heave = -self.heave_gain * np.cos(np.abs(self.angle_rad))
                    
                    heave = np.clip(heave, -1.0, 1.0)
                else:
                    now = time.time()
                    if self.line_lost_time is None:
                        self.line_lost_time = now
                    
                    if (now - self.line_lost_time) > self.failsafe_timeout and not self.failsafe_triggered:
                        self.failsafe_triggered = True
                        self.failsafe_mode()
                
                return surge, sway, yaw, heave
            else:
                self.get_logger().error("Received data array with insufficient elements in line_control")
                return 0.0, 0.0, 0.0, 0.0
        except Exception as e:
            self.get_logger().error(f"Error in line_control: {str(e)}")
            return 0.0, 0.0, 0.0, 0.0

    def failsafe_mode(self):
        """Handle failsafe mode when line is lost"""
        self.get_logger().warn("Failsafe Activated: Aborting mission")
        surge = 0.0
        sway = 0.0
        yaw = 0.1 if self.last_normalized_mid_x > 0 else -0.1
        heave = 0.3  # Start ascent
        self.publish_velocity(surge, sway, yaw, heave)

    def handle_shackle_buttons(self, canvas, y_pos):
        if self.shackle_detected and self.shackle_action is None:
            #cv2.putText(canvas, "Shackle detected! Choose handling:", (10, y_pos), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0,0,255), 2)
            ned_rect = self.ned_rect
            opp_rect = self.opp_rect
            insp_rect = self.inspection_rect
            cv2.rectangle(canvas, ned_rect[:2], (ned_rect[0]+ned_rect[2], ned_rect[1]+ned_rect[3]), (0,255,0), -1)
            cv2.rectangle(canvas, opp_rect[:2], (opp_rect[0]+opp_rect[2], opp_rect[1]+opp_rect[3]), (255,0,0), -1)
            cv2.rectangle(canvas, insp_rect[:2], (insp_rect[0]+insp_rect[2], insp_rect[1]+insp_rect[3]), (0,255,255), -1)
            cv2.putText(canvas, "Continue down", (ned_rect[0]+10, ned_rect[1]+40), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0,0,0), 2)
            cv2.putText(canvas, "Start ascent", (opp_rect[0]+10, opp_rect[1]+40), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0,0,0), 2)
            cv2.putText(canvas, "Inspection", (insp_rect[0]+10, insp_rect[1]+40), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0,0,0), 2)

    def mouse_callback(self, event, x, y, flags, param):
        if event == cv2.EVENT_LBUTTONDOWN and self.shackle_detected and self.shackle_action is None:
            x1, y1, w1, h1 = self.ned_rect
            if x1 <= x <= x1 + w1 and y1 <= y <= y1 + h1:
                self.heave_direction = 1
                cv2.setTrackbarPos("Heave Direction (0:Down 1:Up)", 'Control', 0)
                self.get_logger().info("User chose: Continue down")
            x2, y2, w2, h2 = self.opp_rect
            if x2 <= x <= x2 + w2 and y2 <= y <= y2 + h2:
                self.heave_direction = -1
                cv2.setTrackbarPos("Heave Direction (0:Down 1:Up)", 'Control', 1)
                self.get_logger().info("User chose: Start ascent")
            x3, y3, w3, h3 = self.inspection_rect
            if x3 <= x <= x3 + w3 and y3 <= y <= y3 + h3:
                self.inspection_mode = True
                self.original_desired_width = self.desired_width
                self.inspection_target_width = self.desired_width + 40
                self.desired_width = self.inspection_target_width
                cv2.setTrackbarPos("Desired Width", 'Control', self.desired_width // 10)
                self.get_logger().info(f"Inspection mode: Increases desired width to {self.desired_width}")

def main(args=None):
    rclpy.init(args=args)
    controller = ChainPosController()
    rclpy.spin(controller)
    cv2.destroyAllWindows()
    controller.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

#Controlling both Sway and yaw to put line in middle of camera.
#If line goes ourtside box a constand sway is set depending on side it dissapres on
#Controlling surge to be within with threshold at 70 
#Heave is controlled with gain values where negative -> down 
