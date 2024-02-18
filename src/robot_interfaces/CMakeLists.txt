cmake_minimum_required(VERSION 3.8)
project(robot_interfaces)

find_package(ament_cmake REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/DVL.msg"
  "msg/DesiredVelocity.msg"
  "msg/ChainPos.msg"
  "msg/YoloBox.msg"
  "msg/DesiredForces.msg"
  "srv/AddWaypoint.srv"
  "srv/ClearWaypoints.srv"
  "srv/PrintWaypoints.srv"
  "srv/RemoveWaypoint.srv"
  "srv/SetState.srv"
  DEPENDENCIES builtin_interfaces
  DEPENDENCIES std_msgs
  DEPENDENCIES geometry_msgs
)

ament_package()
