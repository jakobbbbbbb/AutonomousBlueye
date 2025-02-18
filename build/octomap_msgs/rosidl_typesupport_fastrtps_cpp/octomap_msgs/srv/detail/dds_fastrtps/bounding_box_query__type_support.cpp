// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from octomap_msgs:srv/BoundingBoxQuery.idl
// generated code does not contain a copyright notice
#include "octomap_msgs/srv/detail/bounding_box_query__rosidl_typesupport_fastrtps_cpp.hpp"
#include "octomap_msgs/srv/detail/bounding_box_query__struct.hpp"

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
namespace geometry_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const geometry_msgs::msg::Point &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  geometry_msgs::msg::Point &);
size_t get_serialized_size(
  const geometry_msgs::msg::Point &,
  size_t current_alignment);
size_t
max_serialized_size_Point(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace geometry_msgs

// functions for geometry_msgs::msg::Point already declared above


namespace octomap_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_octomap_msgs
cdr_serialize(
  const octomap_msgs::srv::BoundingBoxQuery_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: min
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.min,
    cdr);
  // Member: max
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.max,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_octomap_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  octomap_msgs::srv::BoundingBoxQuery_Request & ros_message)
{
  // Member: min
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.min);

  // Member: max
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.max);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_octomap_msgs
get_serialized_size(
  const octomap_msgs::srv::BoundingBoxQuery_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: min

  current_alignment +=
    geometry_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.min, current_alignment);
  // Member: max

  current_alignment +=
    geometry_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.max, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_octomap_msgs
max_serialized_size_BoundingBoxQuery_Request(
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


  // Member: min
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        geometry_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Point(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: max
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        geometry_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Point(
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
    using DataType = octomap_msgs::srv::BoundingBoxQuery_Request;
    is_plain =
      (
      offsetof(DataType, max) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _BoundingBoxQuery_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const octomap_msgs::srv::BoundingBoxQuery_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _BoundingBoxQuery_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<octomap_msgs::srv::BoundingBoxQuery_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _BoundingBoxQuery_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const octomap_msgs::srv::BoundingBoxQuery_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _BoundingBoxQuery_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_BoundingBoxQuery_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _BoundingBoxQuery_Request__callbacks = {
  "octomap_msgs::srv",
  "BoundingBoxQuery_Request",
  _BoundingBoxQuery_Request__cdr_serialize,
  _BoundingBoxQuery_Request__cdr_deserialize,
  _BoundingBoxQuery_Request__get_serialized_size,
  _BoundingBoxQuery_Request__max_serialized_size
};

static rosidl_message_type_support_t _BoundingBoxQuery_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_BoundingBoxQuery_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace octomap_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_octomap_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<octomap_msgs::srv::BoundingBoxQuery_Request>()
{
  return &octomap_msgs::srv::typesupport_fastrtps_cpp::_BoundingBoxQuery_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, octomap_msgs, srv, BoundingBoxQuery_Request)() {
  return &octomap_msgs::srv::typesupport_fastrtps_cpp::_BoundingBoxQuery_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace octomap_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_octomap_msgs
cdr_serialize(
  const octomap_msgs::srv::BoundingBoxQuery_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: structure_needs_at_least_one_member
  cdr << ros_message.structure_needs_at_least_one_member;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_octomap_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  octomap_msgs::srv::BoundingBoxQuery_Response & ros_message)
{
  // Member: structure_needs_at_least_one_member
  cdr >> ros_message.structure_needs_at_least_one_member;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_octomap_msgs
get_serialized_size(
  const octomap_msgs::srv::BoundingBoxQuery_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: structure_needs_at_least_one_member
  {
    size_t item_size = sizeof(ros_message.structure_needs_at_least_one_member);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_octomap_msgs
max_serialized_size_BoundingBoxQuery_Response(
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


  // Member: structure_needs_at_least_one_member
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = octomap_msgs::srv::BoundingBoxQuery_Response;
    is_plain =
      (
      offsetof(DataType, structure_needs_at_least_one_member) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _BoundingBoxQuery_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const octomap_msgs::srv::BoundingBoxQuery_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _BoundingBoxQuery_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<octomap_msgs::srv::BoundingBoxQuery_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _BoundingBoxQuery_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const octomap_msgs::srv::BoundingBoxQuery_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _BoundingBoxQuery_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_BoundingBoxQuery_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _BoundingBoxQuery_Response__callbacks = {
  "octomap_msgs::srv",
  "BoundingBoxQuery_Response",
  _BoundingBoxQuery_Response__cdr_serialize,
  _BoundingBoxQuery_Response__cdr_deserialize,
  _BoundingBoxQuery_Response__get_serialized_size,
  _BoundingBoxQuery_Response__max_serialized_size
};

static rosidl_message_type_support_t _BoundingBoxQuery_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_BoundingBoxQuery_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace octomap_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_octomap_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<octomap_msgs::srv::BoundingBoxQuery_Response>()
{
  return &octomap_msgs::srv::typesupport_fastrtps_cpp::_BoundingBoxQuery_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, octomap_msgs, srv, BoundingBoxQuery_Response)() {
  return &octomap_msgs::srv::typesupport_fastrtps_cpp::_BoundingBoxQuery_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace octomap_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _BoundingBoxQuery__callbacks = {
  "octomap_msgs::srv",
  "BoundingBoxQuery",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, octomap_msgs, srv, BoundingBoxQuery_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, octomap_msgs, srv, BoundingBoxQuery_Response)(),
};

static rosidl_service_type_support_t _BoundingBoxQuery__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_BoundingBoxQuery__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace octomap_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_octomap_msgs
const rosidl_service_type_support_t *
get_service_type_support_handle<octomap_msgs::srv::BoundingBoxQuery>()
{
  return &octomap_msgs::srv::typesupport_fastrtps_cpp::_BoundingBoxQuery__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, octomap_msgs, srv, BoundingBoxQuery)() {
  return &octomap_msgs::srv::typesupport_fastrtps_cpp::_BoundingBoxQuery__handle;
}

#ifdef __cplusplus
}
#endif
