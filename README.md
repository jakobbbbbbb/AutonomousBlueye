# Autonomous mooring line inspection using Blueye SDK
This is a project which continues on the work conducted by [Nikolai Arntzen](https://github.com/Nikolaiarn) as part of his master thesis at NTNU.

The code consists of a control system that ensures autonomous following of a mooring line chain using a Blueye Pioneer ROV. This project has an emphasis on only utilizing camera and IMU as sensors to ensure low-cost. The code is tested solely on a Blueye Pioneer, but should in theory work satisfactory with Blueye X3 as the thrusters dimensions are equal.

The way this ROS2 control system is structured is two nodes listening for IMU data and camera data. One node subscribes to the camera data and outputs angle and position to where it thinks the chain is in the camera frame. 

Another node takes this info and outputs values in surge, sway, heave, and yaw. These values will then be translated into thruster values by the onboard SDK which includes thrust allocation. 

The code is developed for Ubuntu 22.04.5 LTS (Jammy Jellyfish). It is strongly advised to run from a native Linux computer or a dual boot.

## Project details:
This project is developed by Christian Lindahl Elseth and Jakob Rude Øvstaas as part of our master thesis at Marine Technology NTNU.

## Setup guide:
Install all necessary libraries:
```sh
pip install -r requirements.txt
```

Install [ROS2 Humble](https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debs.html)

Clone this repository:
```sh
git clone https://github.com/jakobbbbbbb/AutonomousBlueye.git
```
Clone this repo which converts YOLOv5 to ROS2 messages (Note: there are two separates repos to be cloned)
https://github.com/Ar-Ray-code/YOLOv5-ROS.git

## Connection guide:
1. Power on Blueye Pioneer and tether. Connect computer to Blueye's WiFi.
2. Source the code:
```sh
source /opt/ros/humble/setup.bash
```
3. Build the code:
```sh
colcon build
```
4. Run the code:
```sh
ros2 launch real_blueye.launch.py
```