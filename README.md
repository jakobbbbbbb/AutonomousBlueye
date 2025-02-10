# Autonomous mooring line inspection using Blueye SDK
This is a project which continues on the work conducted by Nikolai Arntzen as part of his master thesis at NTNU.

The code consists of a control system that ensures autonomous following of a mooring line chain using a Blueye Pioneer ROV. This project has an emphasis on only utilizing camera and IMU as sensors to ensure low-cost. The code is tested solely on a Blueye Pioneer, but should in theory work similarily with Blueye X3 as the thrusters dimensions are equal.

The way this ROS2 control system is structured is two nodes listening for IMU data and camera data. One node Subscribes to the camera data and outputs angle and position to where it thinks the chain is in the camera frame. 

Another node takes this info and outputs values in surge, sway, heave, and yaw. These values will then be translated into thruster values by the onboard SDK which includes thrust allocation. 

## Project details:
This project is developed by Christian Lindahl Elseth and Jakob Rude Øvstaas as part of our master thesis at Marine Technology NTNU.

## Connection guide:
To be written...