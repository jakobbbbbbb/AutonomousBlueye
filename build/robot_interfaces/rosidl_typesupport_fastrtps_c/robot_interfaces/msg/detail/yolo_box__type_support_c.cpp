// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from robot_interfaces:msg/YoloBox.idl
// generated code does not contain a copyright notice
#include "robot_interfaces/msg/detail/yolo_box__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "robot_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "robot_interfaces/msg/detail/yolo_box__struct.h"
#include "robot_interfaces/msg/detail/yolo_box__functions.h"
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

#include "rosidl_runtime_c/string.h"  // cls
#include "rosidl_runtime_c/string_functions.h"  // cls

// forward declare type support functions


using _YoloBox__ros_msg_type = robot_interfaces__msg__YoloBox;

static bool _YoloBox__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _YoloBox__ros_msg_type * ros_message = static_cast<const _YoloBox__ros_msg_type *>(untyped_ros_message);
  // Field name: cls
  {
    const rosidl_runtime_c__String * str = &ros_message->cls;
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

  // Field name: confidence
  {
    cdr << ros_message->confidence;
  }

  // Field name: x_min
  {
    cdr << ros_message->x_min;
  }

  // Field name: y_min
  {
    cdr << ros_message->y_min;
  }

  // Field name: x_max
  {
    cdr << ros_message->x_max;
  }

  // Field name: y_max
  {
    cdr << ros_message->y_max;
  }

  return true;
}

static bool _YoloBox__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _YoloBox__ros_msg_type * ros_message = static_cast<_YoloBox__ros_msg_type *>(untyped_ros_message);
  // Field name: cls
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->cls.data) {
      rosidl_runtime_c__String__init(&ros_message->cls);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->cls,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'cls'\n");
      return false;
    }
  }

  // Field name: confidence
  {
    cdr >> ros_message->confidence;
  }

  // Field name: x_min
  {
    cdr >> ros_message->x_min;
  }

  // Field name: y_min
  {
    cdr >> ros_message->y_min;
  }

  // Field name: x_max
  {
    cdr >> ros_message->x_max;
  }

  // Field name: y_max
  {
    cdr >> ros_message->y_max;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robot_interfaces
size_t get_serialized_size_robot_interfaces__msg__YoloBox(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _YoloBox__ros_msg_type * ros_message = static_cast<const _YoloBox__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name cls
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->cls.size + 1);
  // field.name confidence
  {
    size_t item_size = sizeof(ros_message->confidence);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name x_min
  {
    size_t item_size = sizeof(ros_message->x_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name y_min
  {
    size_t item_size = sizeof(ros_message->y_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name x_max
  {
    size_t item_size = sizeof(ros_message->x_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name y_max
  {
    size_t item_size = sizeof(ros_message->y_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _YoloBox__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_robot_interfaces__msg__YoloBox(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robot_interfaces
size_t max_serialized_size_robot_interfaces__msg__YoloBox(
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

  // member: cls
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
  // member: confidence
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: x_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: y_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: x_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: y_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = robot_interfaces__msg__YoloBox;
    is_plain =
      (
      offsetof(DataType, y_max) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _YoloBox__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_robot_interfaces__msg__YoloBox(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_YoloBox = {
  "robot_interfaces::msg",
  "YoloBox",
  _YoloBox__cdr_serialize,
  _YoloBox__cdr_deserialize,
  _YoloBox__get_serialized_size,
  _YoloBox__max_serialized_size
};

static rosidl_message_type_support_t _YoloBox__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_YoloBox,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robot_interfaces, msg, YoloBox)() {
  return &_YoloBox__type_support;
}

#if defined(__cplusplus)
}
#endif
