// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from octomap_msgs:msg/OctomapWithPose.idl
// generated code does not contain a copyright notice

#ifndef OCTOMAP_MSGS__MSG__DETAIL__OCTOMAP_WITH_POSE__STRUCT_H_
#define OCTOMAP_MSGS__MSG__DETAIL__OCTOMAP_WITH_POSE__STRUCT_H_

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
// Member 'origin'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'octomap'
#include "octomap_msgs/msg/detail/octomap__struct.h"

/// Struct defined in msg/OctomapWithPose in the package octomap_msgs.
/**
  * A 3D map in binary format, as Octree
 */
typedef struct octomap_msgs__msg__OctomapWithPose
{
  std_msgs__msg__Header header;
  /// The pose of the octree with respect to the header frame
  geometry_msgs__msg__Pose origin;
  /// The actual octree msg
  octomap_msgs__msg__Octomap octomap;
} octomap_msgs__msg__OctomapWithPose;

// Struct for a sequence of octomap_msgs__msg__OctomapWithPose.
typedef struct octomap_msgs__msg__OctomapWithPose__Sequence
{
  octomap_msgs__msg__OctomapWithPose * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} octomap_msgs__msg__OctomapWithPose__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OCTOMAP_MSGS__MSG__DETAIL__OCTOMAP_WITH_POSE__STRUCT_H_
