// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from octomap_msgs:msg/Octomap.idl
// generated code does not contain a copyright notice

#ifndef OCTOMAP_MSGS__MSG__DETAIL__OCTOMAP__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define OCTOMAP_MSGS__MSG__DETAIL__OCTOMAP__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "octomap_msgs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "octomap_msgs/msg/detail/octomap__struct.hpp"

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

#include "fastcdr/Cdr.h"

namespace octomap_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_octomap_msgs
cdr_serialize(
  const octomap_msgs::msg::Octomap & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_octomap_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  octomap_msgs::msg::Octomap & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_octomap_msgs
get_serialized_size(
  const octomap_msgs::msg::Octomap & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_octomap_msgs
max_serialized_size_Octomap(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace octomap_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_octomap_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, octomap_msgs, msg, Octomap)();

#ifdef __cplusplus
}
#endif

#endif  // OCTOMAP_MSGS__MSG__DETAIL__OCTOMAP__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
