// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_interfaces:srv/PrintWaypoints.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__PRINT_WAYPOINTS__STRUCT_H_
#define ROBOT_INTERFACES__SRV__DETAIL__PRINT_WAYPOINTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/PrintWaypoints in the package robot_interfaces.
typedef struct robot_interfaces__srv__PrintWaypoints_Request
{
  bool print;
} robot_interfaces__srv__PrintWaypoints_Request;

// Struct for a sequence of robot_interfaces__srv__PrintWaypoints_Request.
typedef struct robot_interfaces__srv__PrintWaypoints_Request__Sequence
{
  robot_interfaces__srv__PrintWaypoints_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__srv__PrintWaypoints_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/PrintWaypoints in the package robot_interfaces.
typedef struct robot_interfaces__srv__PrintWaypoints_Response
{
  bool accepted;
} robot_interfaces__srv__PrintWaypoints_Response;

// Struct for a sequence of robot_interfaces__srv__PrintWaypoints_Response.
typedef struct robot_interfaces__srv__PrintWaypoints_Response__Sequence
{
  robot_interfaces__srv__PrintWaypoints_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__srv__PrintWaypoints_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_INTERFACES__SRV__DETAIL__PRINT_WAYPOINTS__STRUCT_H_
