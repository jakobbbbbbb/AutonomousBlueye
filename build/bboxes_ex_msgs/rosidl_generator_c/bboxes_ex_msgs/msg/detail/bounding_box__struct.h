// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from bboxes_ex_msgs:msg/BoundingBox.idl
// generated code does not contain a copyright notice

#ifndef BBOXES_EX_MSGS__MSG__DETAIL__BOUNDING_BOX__STRUCT_H_
#define BBOXES_EX_MSGS__MSG__DETAIL__BOUNDING_BOX__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'class_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/BoundingBox in the package bboxes_ex_msgs.
typedef struct bboxes_ex_msgs__msg__BoundingBox
{
  float probability;
  uint16_t xmin;
  uint16_t ymin;
  uint16_t xmax;
  uint16_t ymax;
  uint16_t id;
  uint16_t img_width;
  uint16_t img_height;
  int32_t center_dist;
  rosidl_runtime_c__String class_id;
  uint16_t class_id_int;
} bboxes_ex_msgs__msg__BoundingBox;

// Struct for a sequence of bboxes_ex_msgs__msg__BoundingBox.
typedef struct bboxes_ex_msgs__msg__BoundingBox__Sequence
{
  bboxes_ex_msgs__msg__BoundingBox * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} bboxes_ex_msgs__msg__BoundingBox__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BBOXES_EX_MSGS__MSG__DETAIL__BOUNDING_BOX__STRUCT_H_
