import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu
from geometry_msgs.msg import Vector3
import time
import blueye.protocol as bp
from blueye.sdk import Drone

class IMUPublisher(Node):
    def __init__(self):
        super().__init__('imu_publisher')
        self.imu_publisher = self.create_publisher(Imu, 'imu/data', 10)
        self.temperature_publisher = self.create_publisher(Vector3, 'imu/temperature', 10)
        self.initialize_drone()

    def initialize_drone(self):
        self.my_drone = Drone()
        self.my_drone.telemetry.set_msg_publish_frequency(bp.CalibratedImuTel, 1)
        self.my_drone.telemetry.add_msg_callback([bp.CalibratedImuTel], self.callback_imu_calibrated)

    def callback_imu_calibrated(self, msg_type, msg):
        imu_msg = Imu()
        imu_msg.header.stamp = self.get_clock().now().to_msg()
        imu_msg.header.frame_id = 'imu_link'
        imu_msg.angular_velocity.x = msg.imu.gyroscope.x
        imu_msg.angular_velocity.y = msg.imu.gyroscope.y
        imu_msg.angular_velocity.z = msg.imu.gyroscope.z
        imu_msg.linear_acceleration.x = msg.imu.accelerometer.x
        imu_msg.linear_acceleration.y = msg.imu.accelerometer.y
        imu_msg.linear_acceleration.z = msg.imu.accelerometer.z
        self.imu_publisher.publish(imu_msg)

        # For temperature, using Vector3 as a simple example. You might want to use a more appropriate message type.
        temp_msg = Vector3()
        temp_msg.x = msg.imu.temperature
        self.temperature_publisher.publish(temp_msg)

        print(f"Published IMU and temperature data.")

def main(args=None):
    rclpy.init(args=args)
    imu_publisher = IMUPublisher()

    try:
        print("Press CTRL+C to stop the node.")
        rclpy.spin(imu_publisher)
    except KeyboardInterrupt:
        print("Stopping IMU publisher node.")
    finally:
        imu_publisher.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
