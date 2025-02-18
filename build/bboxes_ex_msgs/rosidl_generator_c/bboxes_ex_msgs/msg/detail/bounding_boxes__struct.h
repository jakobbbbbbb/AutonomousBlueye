// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from bboxes_ex_msgs:msg/BoundingBoxes.idl
// generated code does not contain a copyright notice

#ifndef BBOXES_EX_MSGS__MSG__DETAIL__BOUNDING_BOXES__STRUCT_H_
#define BBOXES_EX_MSGS__MSG__DETAIL__BOUNDING_BOXES__STRUCT_H_

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
// Member 'image_header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'bounding_boxes'
#include "bboxes_ex_msgs/msg/detail/bounding_box__struct.h"

/// Struct defined in msg/BoundingBoxes in the package bboxes_ex_msgs.
typedef struct bboxes_ex_msgs__msg__BoundingBoxes
{
  std_msgs__msg__Header header;
  std_msgs__msg__Header image_header;
  bboxes_ex_msgs__msg__BoundingBox__Sequence bounding_boxes;
} bboxes_ex_msgs__msg__BoundingBoxes;

// Struct for a sequence of bboxes_ex_msgs__msg__BoundingBoxes.
typedef struct bboxes_ex_msgs__msg__BoundingBoxes__Sequence
{
  bboxes_ex_msgs__msg__BoundingBoxes * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} bboxes_ex_msgs__msg__BoundingBoxes__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BBOXES_EX_MSGS__MSG__DETAIL__BOUNDING_BOXES__STRUCT_H_
