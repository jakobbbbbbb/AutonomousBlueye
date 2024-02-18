from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
        Blueye_IMU = Node(
            package='drone_sensors',
            executable='imu_to_ros2',
            name='imu_node'
        ),
        Blueye_camera = Node(
            package='drone_sensors',
            executable='video_to_ros2',
            name='video_node'
        ),
        Laptop_camera = Node(
            package='drone_sensors',
            executable='laptop_camera',
            name='laptop_camera'
        )
        Chain_pos = Node(
            package='image_prosessing',
            executable='blueye_image_simple',
            name = 'Real_image'
        )
        canny_tuning = Node(
            package='experimental',
            executable='Image_test',
            name = 'test_image'
        )

        Desired_velocity = Node(
            package='drone_sensors',
            executable='chain_pos_controller',
            name = 'Chain_controller'
        )

        return LaunchDescription([
            # Blueye_IMU, 
            # Blueye_camera,
            Laptop_camera,
            # Chain_pos,
            canny_tuning,
            # Desired_velocity
    ])
