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
        name='laptop_camera',
        parameters=[{"video_device": "/dev/video0"}]
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

    Chain_pos_thresh_mean = Node(
        package='image_prosessing',
        executable='threshold_median_mean',
        name = 'Threshold_mean'
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
        name = 'Yolo_bbox_drawer'
    )
    yolo_chain_canny = Node(
        package='image_prosessing',
        executable='yolo_chain_value',
        name = 'yolo_chain'
    )
    Canny_inside_yolo = Node(
        package='image_prosessing',
        executable='Canny_inside_yolo',
        name = 'Canny_inside_yolo'
    )

    Thresh_inside_yolo = Node(
        package='image_prosessing',
        executable='Thresh_inside_yolo',
        name = 'Thresh_inside_yolo'
    )
    Median_inside_yolo = Node(
        package='image_prosessing',
        executable='Median_inside_yolo',
        name = 'Median_inside_yolo'
    )

    Adaptive_threshold = Node(
        package='image_prosessing',
        executable='Adaptive_threshold',
        name = 'Adaptive_threshold'
    )

    Hybrid_approach = Node(
        package='image_prosessing',
        executable='Hybrid_approach',
        name = 'Hybrid_approach'
    )

    Canny_edge_new = Node(
        package= 'image_prosessing',
        executable = 'Canny_edge_new',
        name = 'Canny_edge_new'
    )

    MarineSnowRemoval = Node(
        package= 'image_prosessing',
        executable = 'MarineSnowRemoval',
        name = 'MarineSnowRemoval' 
    )

    Video_topic = Node(
        package='experimental',
        # executable='Video_to_topic_no_trackbar',
        executable='Video_to_topic',
        name = 'video_topic'
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
            {"input_topic": "/image_raw"},  # Explicitly setting the input topic
            #{"weights": "/home/ovsj/Code/AutonomousBlueye/ws_yolov5/src/YOLOv5-ROS/yolov5_ros/yolov5_ros/config/mooring.pt"},
            #{"data": "/home/ovsj/Code/AutonomousBlueye/ws_yolov5/src/YOLOv5-ROS/yolov5_ros/yolov5_ros/data/mooring.yaml"},
            #{"conf_thres": 0.1},  # Lower confidence threshold
            #{"iou_thres": 0.45},  # Intersection Over Union threshold
        ],
    )


    return LaunchDescription([
        # The following topics can be uncommented depending on desired use
        
        #Blueye_IMU, 
        #Blueye_pose,
        #Blueye_Force,
        #Blueye_camera,

        Video_topic,
        #Laptop_camera,

        #Image_test,
        #Chain_pos_canny,
        #Adaptive_threshold,
        #Hybrid_approach,
        #Canny_edge_new,
        MarineSnowRemoval,
        #Chain_pos_thresh,
        #Chain_pos_thresh_mean,

        # Desired_velocity_test,
        Desired_velocity,
        # Desired_velocity_spiral,
        # Desired_velocity_compass,
        # Desired_velocity_switch,

        #control,

        #yolov5_ros,
        #yolo_image,
        #yolo_chain_canny,

        #Canny_inside_yolo,
        #Thresh_inside_yolo,
        #Median_inside_yolo,
    ])

