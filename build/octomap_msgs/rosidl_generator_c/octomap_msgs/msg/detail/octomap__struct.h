// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from octomap_msgs:msg/Octomap.idl
// generated code does not contain a copyright notice

#ifndef OCTOMAP_MSGS__MSG__DETAIL__OCTOMAP__STRUCT_H_
#define OCTOMAP_MSGS__MSG__DETAIL__OCTOMAP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'id'
#include "rosidl_runtime_c/string.h"
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/Octomap in the package octomap_msgs.
/**
  * A 3D map in binary format, as Octree
 */
typedef struct octomap_msgs__msg__Octomap
{
  std_msgs__msg__Header header;
  /// Flag to denote a binary (only free/occupied) or full occupancy octree (.bt/.ot file)
  bool binary;
  /// Class id of the contained octree
  rosidl_runtime_c__String id;
  /// Resolution (in m) of the smallest octree nodes
  double resolution;
  /// binary serialization of octree, use conversions.h to read and write octrees
  rosidl_runtime_c__int8__Sequence data;
} octomap_msgs__msg__Octomap;

// Struct for a sequence of octomap_msgs__msg__Octomap.
typedef struct octomap_msgs__msg__Octomap__Sequence
{
  octomap_msgs__msg__Octomap * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} octomap_msgs__msg__Octomap__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OCTOMAP_MSGS__MSG__DETAIL__OCTOMAP__STRUCT_H_
