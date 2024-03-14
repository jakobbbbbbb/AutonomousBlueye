import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu, MagneticField
from geometry_msgs.msg import Vector3
from tf2_ros import TransformBroadcaster
from geometry_msgs.msg import TransformStamped
import time
import blueye.protocol as bp
from blueye.sdk import Drone

class IMUPublisher(Node):
    def __init__(self):
        super().__init__('imu_publisher')
        self.imu_publisher = self.create_publisher(Imu, '/blueye/imu', 100)
        self.magnetometer_publisher = self.create_publisher(MagneticField, 'magnetometer/data', 100)  # Magnetometer publisher
        self.br = TransformBroadcaster(self)  # TF2 Transform Broadcaster
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

        # Assuming msg.imu also contains magnetometer data (x, y, z)
        magnetometer_msg = MagneticField()
        magnetometer_msg.header.stamp = imu_msg.header.stamp
        magnetometer_msg.header.frame_id = 'imu_link'
        # Populate magnetometer_msg.magnetic_field with magnetometer data
        magnetometer_msg.magnetic_field.x = msg.imu.magnetometer.x  # Placeholder, adjust according to actual data structure
        magnetometer_msg.magnetic_field.y = msg.imu.magnetometer.y
        magnetometer_msg.magnetic_field.z = msg.imu.magnetometer.z
        self.magnetometer_publisher.publish(magnetometer_msg)

        # Now broadcast the transform
        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = 'base_link'
        t.child_frame_id = 'imu_link'
        t.transform.translation.x = 1.0  # Adjust these values based on the actual physical location of the IMU
        t.transform.translation.y = 1.0
        t.transform.translation.z = 1.0
        # Assuming no rotation from base_link to imu_link; adjust as necessary
        t.transform.rotation.x = 0.0
        t.transform.rotation.y = 0.0
        t.transform.rotation.z = 0.0
        t.transform.rotation.w = 1.0
        self.br.sendTransform(t)

        # Your existing TF broadcasting code here...

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
