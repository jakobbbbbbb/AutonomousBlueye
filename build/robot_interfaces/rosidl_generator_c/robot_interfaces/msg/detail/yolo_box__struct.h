// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_interfaces:msg/YoloBox.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__YOLO_BOX__STRUCT_H_
#define ROBOT_INTERFACES__MSG__DETAIL__YOLO_BOX__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'cls'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/YoloBox in the package robot_interfaces.
typedef struct robot_interfaces__msg__YoloBox
{
  rosidl_runtime_c__String cls;
  double confidence;
  double x_min;
  double y_min;
  double x_max;
  double y_max;
} robot_interfaces__msg__YoloBox;

// Struct for a sequence of robot_interfaces__msg__YoloBox.
typedef struct robot_interfaces__msg__YoloBox__Sequence
{
  robot_interfaces__msg__YoloBox * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__msg__YoloBox__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_INTERFACES__MSG__DETAIL__YOLO_BOX__STRUCT_H_
