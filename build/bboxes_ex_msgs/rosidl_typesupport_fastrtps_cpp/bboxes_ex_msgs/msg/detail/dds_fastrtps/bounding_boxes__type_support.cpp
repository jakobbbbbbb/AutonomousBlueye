// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from bboxes_ex_msgs:msg/BoundingBoxes.idl
// generated code does not contain a copyright notice
#include "bboxes_ex_msgs/msg/detail/bounding_boxes__rosidl_typesupport_fastrtps_cpp.hpp"
#include "bboxes_ex_msgs/msg/detail/bounding_boxes__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs

// functions for std_msgs::msg::Header already declared above

namespace bboxes_ex_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const bboxes_ex_msgs::msg::BoundingBox &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  bboxes_ex_msgs::msg::BoundingBox &);
size_t get_serialized_size(
  const bboxes_ex_msgs::msg::BoundingBox &,
  size_t current_alignment);
size_t
max_serialized_size_BoundingBox(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace bboxes_ex_msgs


namespace bboxes_ex_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bboxes_ex_msgs
cdr_serialize(
  const bboxes_ex_msgs::msg::BoundingBoxes & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: image_header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.image_header,
    cdr);
  // Member: bounding_boxes
  {
    size_t size = ros_message.bounding_boxes.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      bboxes_ex_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.bounding_boxes[i],
        cdr);
    }
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bboxes_ex_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  bboxes_ex_msgs::msg::BoundingBoxes & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: image_header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.image_header);

  // Member: bounding_boxes
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.bounding_boxes.resize(size);
    for (size_t i = 0; i < size; i++) {
      bboxes_ex_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.bounding_boxes[i]);
    }
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bboxes_ex_msgs
get_serialized_size(
  const bboxes_ex_msgs::msg::BoundingBoxes & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: image_header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.image_header, current_alignment);
  // Member: bounding_boxes
  {
    size_t array_size = ros_message.bounding_boxes.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        bboxes_ex_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.bounding_boxes[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bboxes_ex_msgs
max_serialized_size_BoundingBoxes(
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


  // Member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: image_header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: bounding_boxes
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        bboxes_ex_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_BoundingBox(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = bboxes_ex_msgs::msg::BoundingBoxes;
    is_plain =
      (
      offsetof(DataType, bounding_boxes) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _BoundingBoxes__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const bboxes_ex_msgs::msg::BoundingBoxes *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _BoundingBoxes__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<bboxes_ex_msgs::msg::BoundingBoxes *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _BoundingBoxes__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const bboxes_ex_msgs::msg::BoundingBoxes *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _BoundingBoxes__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_BoundingBoxes(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _BoundingBoxes__callbacks = {
  "bboxes_ex_msgs::msg",
  "BoundingBoxes",
  _BoundingBoxes__cdr_serialize,
  _BoundingBoxes__cdr_deserialize,
  _BoundingBoxes__get_serialized_size,
  _BoundingBoxes__max_serialized_size
};

static rosidl_message_type_support_t _BoundingBoxes__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_BoundingBoxes__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace bboxes_ex_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_bboxes_ex_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<bboxes_ex_msgs::msg::BoundingBoxes>()
{
  return &bboxes_ex_msgs::msg::typesupport_fastrtps_cpp::_BoundingBoxes__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, bboxes_ex_msgs, msg, BoundingBoxes)() {
  return &bboxes_ex_msgs::msg::typesupport_fastrtps_cpp::_BoundingBoxes__handle;
}

#ifdef __cplusplus
}
#endif
