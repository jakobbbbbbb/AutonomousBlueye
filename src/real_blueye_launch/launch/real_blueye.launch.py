import os
from ament_index_python.packages import get_package_share_directory

import launch_ros.actions
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch_ros.actions import Node
from launch_ros.actions import LifecycleNode


def generate_launch_description():

    yolox_ros_share_dir = get_package_share_directory('yolov5_ros')

    Blueye_IMU = Node(
        package='drone_sensors',
        executable='IMU_to_ros2',
        name='imu_node'
    )

    Blueye_pose = Node(
        package='drone_sensors',
        executable='BluEye_Pose',
        name='pose_node'
    )
    Blueye_Force = Node(
        package='drone_sensors',
        executable='BluEye_Force',
        name='force_node'
    )
    Blueye_camera = Node(
        package='drone_sensors',
        executable='Video_to_ros2',
        name='video_node'
    )
    Laptop_camera = Node(
        package='drone_sensors',
        executable='laptop_camera',
        name='laptop_camera'
    )
    Chain_pos_canny = Node(
        package='image_prosessing',
        executable='canny_with_box',
        name = 'Real_image'
    )

    Chain_pos_thresh = Node(
        package='image_prosessing',
        executable='threshold_with_box',
        name = 'Threshold'
    )

    Chain_pos_box_orig = Node(
        package='image_prosessing',
        executable='canny_with_box_original',
        name = 'Real_image2'
    )

    Image_test = Node(
        package='image_prosessing',
        executable='Image_test',
        name = 'test_image'
    )

    yolo_image = Node(
        package='image_prosessing',
        executable='blueye_image_yolo',
        name = 'test_yolo'
    )
    yolo_chain_canny = Node(
        package='image_prosessing',
        executable='yolo_chain_value',
        name = 'yolo_chain'
    )

    Video_topic = Node(
        package='experimental',
        executable='Video_to_topic',
        name = 'test_yolo'
    )

    Desired_velocity = Node(
        package='control',
        executable='desired_velocity',
        name = 'Chain_controller'
    )

    Desired_velocity_test = Node(
        package='control',
        executable='desired_velocity_test',
        name = 'Chain_controller_test'
    )

    Desired_velocity_spiral = Node(
        package='control',
        executable='desired_velocity_spiral_surge',
        name = 'Chain_controller_spiral'
    )
    Desired_velocity_compass = Node(
        package='control',
        executable='desired_velocity_compass',
        name = 'Chain_controller_compas'
    )

    Desired_velocity_switch = Node(
        package='control',
        executable='desired_velocity_switch',
        name = 'Chain_controller_switch'
    )
    
    control = Node(
        package='control',
        executable='control',
        name = 'control_test_name'
    )
    control_test = Node(
        package='control',
        executable='control_test',
        name = 'control_test_name_test'
    )

    yolov5_ros = launch_ros.actions.Node(
        package="yolov5_ros", 
        executable="yolov5_ros",
        parameters=[
            {"view_img": True},
            {"camera_topic": "/camera"}  
        ],
    )

    return LaunchDescription([
        # Blueye_IMU, 
        # Blueye_pose,
        # Blueye_Force,
        # Blueye_camera,

        Video_topic,
        # Laptop_camera,

        # Image_test,
        # Chain_pos_box_orig,
        Chain_pos_canny,
        Chain_pos_thresh,

        # Desired_velocity,
        Desired_velocity_test,
        # Desired_velocity_spiral,
        # Desired_velocity_compass,
        # Desired_velocity_switch,
        # control,
        # control_test,

        # yolov5_ros,-.
        # yolo_image,
        # yolo_chain_canny,
    ])

