from setuptools import find_packages, setup
import os

package_name = 'drone_sensors'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='nikolai',
    maintainer_email='nikolarn@stud.ntnu.no',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'IMU_to_ros2 = drone_sensors.IMU_to_ros2:main',
            'Video_to_ros2 = drone_sensors.Video_to_ros2:main',
            'laptop_camera = drone_sensors.laptop_camera:main',
            'blueye_image_simple = drone_sensors.blueye_image_simple:main',
            'BluEye_Pose = drone_sensors.BluEye_Pose:main',
            'BluEye_Force = drone_sensors.BluEye_Force:main',
        ],
    },
)

