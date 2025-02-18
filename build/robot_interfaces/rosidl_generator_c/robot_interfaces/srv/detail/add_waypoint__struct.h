// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_interfaces:srv/AddWaypoint.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__ADD_WAYPOINT__STRUCT_H_
#define ROBOT_INTERFACES__SRV__DETAIL__ADD_WAYPOINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/AddWaypoint in the package robot_interfaces.
typedef struct robot_interfaces__srv__AddWaypoint_Request
{
  float x;
  float y;
  float z;
  int64_t position;
} robot_interfaces__srv__AddWaypoint_Request;

// Struct for a sequence of robot_interfaces__srv__AddWaypoint_Request.
typedef struct robot_interfaces__srv__AddWaypoint_Request__Sequence
{
  robot_interfaces__srv__AddWaypoint_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__srv__AddWaypoint_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/AddWaypoint in the package robot_interfaces.
typedef struct robot_interfaces__srv__AddWaypoint_Response
{
  bool accepted;
} robot_interfaces__srv__AddWaypoint_Response;

// Struct for a sequence of robot_interfaces__srv__AddWaypoint_Response.
typedef struct robot_interfaces__srv__AddWaypoint_Response__Sequence
{
  robot_interfaces__srv__AddWaypoint_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__srv__AddWaypoint_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_INTERFACES__SRV__DETAIL__ADD_WAYPOINT__STRUCT_H_
