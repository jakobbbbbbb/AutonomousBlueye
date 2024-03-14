import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Quaternion
from blueye.sdk import Drone

class DronePosePublisher(Node):
    def __init__(self):
        super().__init__('drone_pose_and_depth_publisher')
        self.pose_publisher = self.create_publisher(Quaternion, 'BlueyePose', 10)
        self.drone = Drone()
        self.timer = self.create_timer(0.1, self.publish_drone_pose_and_depth)

    def publish_drone_pose_and_depth(self):
        # Fetch pose data from drone
        pose_data = self.drone.pose
        # Fetch depth data from drone
        depth = self.drone.depth
        
        # Create a Quaternion message to carry roll, pitch, yaw, and depth
        pose_msg = Quaternion()
        pose_msg.x = pose_data['roll']  # Roll
        pose_msg.y = pose_data['pitch']  # Pitch
        pose_msg.z = pose_data['yaw']    # Yaw
        pose_msg.w = depth               # Depth is used in the 'w' component
        
        # Publish the pose and depth data
        self.pose_publisher.publish(pose_msg)
        # self.get_logger().info(f"Published pose and depth: Roll={pose_msg.x}, Pitch={pose_msg.y}, Yaw={pose_msg.z}, Depth={pose_msg.w}")

def main(args=None):
    rclpy.init(args=args)
    drone_pose_publisher = DronePosePublisher()

    try:
        rclpy.spin(drone_pose_publisher)
    except KeyboardInterrupt:
        drone_pose_publisher.get_logger().info("Stopping Drone Pose Publisher node.")
    finally:
        drone_pose_publisher.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()

