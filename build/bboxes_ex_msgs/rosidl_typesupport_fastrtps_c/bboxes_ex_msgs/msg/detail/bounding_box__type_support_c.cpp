// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from bboxes_ex_msgs:msg/BoundingBox.idl
// generated code does not contain a copyright notice
#include "bboxes_ex_msgs/msg/detail/bounding_box__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "bboxes_ex_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "bboxes_ex_msgs/msg/detail/bounding_box__struct.h"
#include "bboxes_ex_msgs/msg/detail/bounding_box__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // class_id
#include "rosidl_runtime_c/string_functions.h"  // class_id

// forward declare type support functions


using _BoundingBox__ros_msg_type = bboxes_ex_msgs__msg__BoundingBox;

static bool _BoundingBox__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _BoundingBox__ros_msg_type * ros_message = static_cast<const _BoundingBox__ros_msg_type *>(untyped_ros_message);
  // Field name: probability
  {
    cdr << ros_message->probability;
  }

  // Field name: xmin
  {
    cdr << ros_message->xmin;
  }

  // Field name: ymin
  {
    cdr << ros_message->ymin;
  }

  // Field name: xmax
  {
    cdr << ros_message->xmax;
  }

  // Field name: ymax
  {
    cdr << ros_message->ymax;
  }

  // Field name: id
  {
    cdr << ros_message->id;
  }

  // Field name: img_width
  {
    cdr << ros_message->img_width;
  }

  // Field name: img_height
  {
    cdr << ros_message->img_height;
  }

  // Field name: center_dist
  {
    cdr << ros_message->center_dist;
  }

  // Field name: class_id
  {
    const rosidl_runtime_c__String * str = &ros_message->class_id;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: class_id_int
  {
    cdr << ros_message->class_id_int;
  }

  return true;
}

static bool _BoundingBox__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _BoundingBox__ros_msg_type * ros_message = static_cast<_BoundingBox__ros_msg_type *>(untyped_ros_message);
  // Field name: probability
  {
    cdr >> ros_message->probability;
  }

  // Field name: xmin
  {
    cdr >> ros_message->xmin;
  }

  // Field name: ymin
  {
    cdr >> ros_message->ymin;
  }

  // Field name: xmax
  {
    cdr >> ros_message->xmax;
  }

  // Field name: ymax
  {
    cdr >> ros_message->ymax;
  }

  // Field name: id
  {
    cdr >> ros_message->id;
  }

  // Field name: img_width
  {
    cdr >> ros_message->img_width;
  }

  // Field name: img_height
  {
    cdr >> ros_message->img_height;
  }

  // Field name: center_dist
  {
    cdr >> ros_message->center_dist;
  }

  // Field name: class_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->class_id.data) {
      rosidl_runtime_c__String__init(&ros_message->class_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->class_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'class_id'\n");
      return false;
    }
  }

  // Field name: class_id_int
  {
    cdr >> ros_message->class_id_int;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_bboxes_ex_msgs
size_t get_serialized_size_bboxes_ex_msgs__msg__BoundingBox(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _BoundingBox__ros_msg_type * ros_message = static_cast<const _BoundingBox__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name probability
  {
    size_t item_size = sizeof(ros_message->probability);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name xmin
  {
    size_t item_size = sizeof(ros_message->xmin);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ymin
  {
    size_t item_size = sizeof(ros_message->ymin);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name xmax
  {
    size_t item_size = sizeof(ros_message->xmax);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ymax
  {
    size_t item_size = sizeof(ros_message->ymax);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name id
  {
    size_t item_size = sizeof(ros_message->id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name img_width
  {
    size_t item_size = sizeof(ros_message->img_width);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name img_height
  {
    size_t item_size = sizeof(ros_message->img_height);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name center_dist
  {
    size_t item_size = sizeof(ros_message->center_dist);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name class_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->class_id.size + 1);
  // field.name class_id_int
  {
    size_t item_size = sizeof(ros_message->class_id_int);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _BoundingBox__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_bboxes_ex_msgs__msg__BoundingBox(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_bboxes_ex_msgs
size_t max_serialized_size_bboxes_ex_msgs__msg__BoundingBox(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: probability
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: xmin
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: ymin
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: xmax
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: ymax
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: img_width
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: img_height
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: center_dist
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: class_id
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: class_id_int
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = bboxes_ex_msgs__msg__BoundingBox;
    is_plain =
      (
      offsetof(DataType, class_id_int) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _BoundingBox__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_bboxes_ex_msgs__msg__BoundingBox(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_BoundingBox = {
  "bboxes_ex_msgs::msg",
  "BoundingBox",
  _BoundingBox__cdr_serialize,
  _BoundingBox__cdr_deserialize,
  _BoundingBox__get_serialized_size,
  _BoundingBox__max_serialized_size
};

static rosidl_message_type_support_t _BoundingBox__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_BoundingBox,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, bboxes_ex_msgs, msg, BoundingBox)() {
  return &_BoundingBox__type_support;
}

#if defined(__cplusplus)
}
#endif
