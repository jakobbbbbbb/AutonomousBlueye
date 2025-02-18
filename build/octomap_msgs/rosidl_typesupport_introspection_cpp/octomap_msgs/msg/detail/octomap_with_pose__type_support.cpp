// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from octomap_msgs:msg/OctomapWithPose.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "octomap_msgs/msg/detail/octomap_with_pose__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace octomap_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void OctomapWithPose_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) octomap_msgs::msg::OctomapWithPose(_init);
}

void OctomapWithPose_fini_function(void * message_memory)
{
  auto typed_message = static_cast<octomap_msgs::msg::OctomapWithPose *>(message_memory);
  typed_message->~OctomapWithPose();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember OctomapWithPose_message_member_array[3] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(octomap_msgs::msg::OctomapWithPose, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "origin",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Pose>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(octomap_msgs::msg::OctomapWithPose, origin),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "octomap",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<octomap_msgs::msg::Octomap>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(octomap_msgs::msg::OctomapWithPose, octomap),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers OctomapWithPose_message_members = {
  "octomap_msgs::msg",  // message namespace
  "OctomapWithPose",  // message name
  3,  // number of fields
  sizeof(octomap_msgs::msg::OctomapWithPose),
  OctomapWithPose_message_member_array,  // message members
  OctomapWithPose_init_function,  // function to initialize message memory (memory has to be allocated)
  OctomapWithPose_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t OctomapWithPose_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &OctomapWithPose_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace octomap_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<octomap_msgs::msg::OctomapWithPose>()
{
  return &::octomap_msgs::msg::rosidl_typesupport_introspection_cpp::OctomapWithPose_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, octomap_msgs, msg, OctomapWithPose)() {
  return &::octomap_msgs::msg::rosidl_typesupport_introspection_cpp::OctomapWithPose_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
