# blueye_chain_follower
This is the first ever ros2 project I have made from scratch so there will be some errors.

Git repo for a control system that ensures autonomous following of a chain using a blueye drone. This project has an emphasis on only utilizing camera and IMU as sensors to ensure low-cost.
The way this ros2 control system is structured is two nodes listening for IMU data and camera data. One node Subscribes to the camera data and outputs angle and position to where it thinks the chain is in the camera frame. 
Another node takes this info and outputs values in surge, sway, heave, and yaw. These values will then be translated into thruster values by the onboard SDK which includes thrust allocation. 

## Project details:
I am using ros2 Humble and ubuntu 22.04
This project is done as part of a master thesis at NTNU in collaboration with DNV. 


