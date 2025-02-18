// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_interfaces:msg/MedianChainPos.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__MEDIAN_CHAIN_POS__STRUCT_H_
#define ROBOT_INTERFACES__MSG__DETAIL__MEDIAN_CHAIN_POS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/MedianChainPos in the package robot_interfaces.
typedef struct robot_interfaces__msg__MedianChainPos
{
  /// To store mid_x, mid_y, angle_degrees
  rosidl_runtime_c__double__Sequence data;
} robot_interfaces__msg__MedianChainPos;

// Struct for a sequence of robot_interfaces__msg__MedianChainPos.
typedef struct robot_interfaces__msg__MedianChainPos__Sequence
{
  robot_interfaces__msg__MedianChainPos * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__msg__MedianChainPos__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_INTERFACES__MSG__DETAIL__MEDIAN_CHAIN_POS__STRUCT_H_
