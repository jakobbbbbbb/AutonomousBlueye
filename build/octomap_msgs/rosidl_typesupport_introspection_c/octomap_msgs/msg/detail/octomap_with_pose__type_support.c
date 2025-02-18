// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from octomap_msgs:msg/OctomapWithPose.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "octomap_msgs/msg/detail/octomap_with_pose__rosidl_typesupport_introspection_c.h"
#include "octomap_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "octomap_msgs/msg/detail/octomap_with_pose__functions.h"
#include "octomap_msgs/msg/detail/octomap_with_pose__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `origin`
#include "geometry_msgs/msg/pose.h"
// Member `origin`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"
// Member `octomap`
#include "octomap_msgs/msg/octomap.h"
// Member `octomap`
#include "octomap_msgs/msg/detail/octomap__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void octomap_msgs__msg__OctomapWithPose__rosidl_typesupport_introspection_c__OctomapWithPose_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  octomap_msgs__msg__OctomapWithPose__init(message_memory);
}

void octomap_msgs__msg__OctomapWithPose__rosidl_typesupport_introspection_c__OctomapWithPose_fini_function(void * message_memory)
{
  octomap_msgs__msg__OctomapWithPose__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember octomap_msgs__msg__OctomapWithPose__rosidl_typesupport_introspection_c__OctomapWithPose_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(octomap_msgs__msg__OctomapWithPose, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "origin",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(octomap_msgs__msg__OctomapWithPose, origin),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "octomap",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(octomap_msgs__msg__OctomapWithPose, octomap),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers octomap_msgs__msg__OctomapWithPose__rosidl_typesupport_introspection_c__OctomapWithPose_message_members = {
  "octomap_msgs__msg",  // message namespace
  "OctomapWithPose",  // message name
  3,  // number of fields
  sizeof(octomap_msgs__msg__OctomapWithPose),
  octomap_msgs__msg__OctomapWithPose__rosidl_typesupport_introspection_c__OctomapWithPose_message_member_array,  // message members
  octomap_msgs__msg__OctomapWithPose__rosidl_typesupport_introspection_c__OctomapWithPose_init_function,  // function to initialize message memory (memory has to be allocated)
  octomap_msgs__msg__OctomapWithPose__rosidl_typesupport_introspection_c__OctomapWithPose_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t octomap_msgs__msg__OctomapWithPose__rosidl_typesupport_introspection_c__OctomapWithPose_message_type_support_handle = {
  0,
  &octomap_msgs__msg__OctomapWithPose__rosidl_typesupport_introspection_c__OctomapWithPose_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_octomap_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, octomap_msgs, msg, OctomapWithPose)() {
  octomap_msgs__msg__OctomapWithPose__rosidl_typesupport_introspection_c__OctomapWithPose_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  octomap_msgs__msg__OctomapWithPose__rosidl_typesupport_introspection_c__OctomapWithPose_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  octomap_msgs__msg__OctomapWithPose__rosidl_typesupport_introspection_c__OctomapWithPose_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, octomap_msgs, msg, Octomap)();
  if (!octomap_msgs__msg__OctomapWithPose__rosidl_typesupport_introspection_c__OctomapWithPose_message_type_support_handle.typesupport_identifier) {
    octomap_msgs__msg__OctomapWithPose__rosidl_typesupport_introspection_c__OctomapWithPose_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &octomap_msgs__msg__OctomapWithPose__rosidl_typesupport_introspection_c__OctomapWithPose_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
