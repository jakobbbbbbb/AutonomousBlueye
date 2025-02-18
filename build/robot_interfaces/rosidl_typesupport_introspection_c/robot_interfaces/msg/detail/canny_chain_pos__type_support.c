// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from robot_interfaces:msg/CannyChainPos.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "robot_interfaces/msg/detail/canny_chain_pos__rosidl_typesupport_introspection_c.h"
#include "robot_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "robot_interfaces/msg/detail/canny_chain_pos__functions.h"
#include "robot_interfaces/msg/detail/canny_chain_pos__struct.h"


// Include directives for member types
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void robot_interfaces__msg__CannyChainPos__rosidl_typesupport_introspection_c__CannyChainPos_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robot_interfaces__msg__CannyChainPos__init(message_memory);
}

void robot_interfaces__msg__CannyChainPos__rosidl_typesupport_introspection_c__CannyChainPos_fini_function(void * message_memory)
{
  robot_interfaces__msg__CannyChainPos__fini(message_memory);
}

size_t robot_interfaces__msg__CannyChainPos__rosidl_typesupport_introspection_c__size_function__CannyChainPos__data(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * robot_interfaces__msg__CannyChainPos__rosidl_typesupport_introspection_c__get_const_function__CannyChainPos__data(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robot_interfaces__msg__CannyChainPos__rosidl_typesupport_introspection_c__get_function__CannyChainPos__data(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void robot_interfaces__msg__CannyChainPos__rosidl_typesupport_introspection_c__fetch_function__CannyChainPos__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    robot_interfaces__msg__CannyChainPos__rosidl_typesupport_introspection_c__get_const_function__CannyChainPos__data(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void robot_interfaces__msg__CannyChainPos__rosidl_typesupport_introspection_c__assign_function__CannyChainPos__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    robot_interfaces__msg__CannyChainPos__rosidl_typesupport_introspection_c__get_function__CannyChainPos__data(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool robot_interfaces__msg__CannyChainPos__rosidl_typesupport_introspection_c__resize_function__CannyChainPos__data(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember robot_interfaces__msg__CannyChainPos__rosidl_typesupport_introspection_c__CannyChainPos_message_member_array[1] = {
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_interfaces__msg__CannyChainPos, data),  // bytes offset in struct
    NULL,  // default value
    robot_interfaces__msg__CannyChainPos__rosidl_typesupport_introspection_c__size_function__CannyChainPos__data,  // size() function pointer
    robot_interfaces__msg__CannyChainPos__rosidl_typesupport_introspection_c__get_const_function__CannyChainPos__data,  // get_const(index) function pointer
    robot_interfaces__msg__CannyChainPos__rosidl_typesupport_introspection_c__get_function__CannyChainPos__data,  // get(index) function pointer
    robot_interfaces__msg__CannyChainPos__rosidl_typesupport_introspection_c__fetch_function__CannyChainPos__data,  // fetch(index, &value) function pointer
    robot_interfaces__msg__CannyChainPos__rosidl_typesupport_introspection_c__assign_function__CannyChainPos__data,  // assign(index, value) function pointer
    robot_interfaces__msg__CannyChainPos__rosidl_typesupport_introspection_c__resize_function__CannyChainPos__data  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robot_interfaces__msg__CannyChainPos__rosidl_typesupport_introspection_c__CannyChainPos_message_members = {
  "robot_interfaces__msg",  // message namespace
  "CannyChainPos",  // message name
  1,  // number of fields
  sizeof(robot_interfaces__msg__CannyChainPos),
  robot_interfaces__msg__CannyChainPos__rosidl_typesupport_introspection_c__CannyChainPos_message_member_array,  // message members
  robot_interfaces__msg__CannyChainPos__rosidl_typesupport_introspection_c__CannyChainPos_init_function,  // function to initialize message memory (memory has to be allocated)
  robot_interfaces__msg__CannyChainPos__rosidl_typesupport_introspection_c__CannyChainPos_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robot_interfaces__msg__CannyChainPos__rosidl_typesupport_introspection_c__CannyChainPos_message_type_support_handle = {
  0,
  &robot_interfaces__msg__CannyChainPos__rosidl_typesupport_introspection_c__CannyChainPos_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robot_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robot_interfaces, msg, CannyChainPos)() {
  if (!robot_interfaces__msg__CannyChainPos__rosidl_typesupport_introspection_c__CannyChainPos_message_type_support_handle.typesupport_identifier) {
    robot_interfaces__msg__CannyChainPos__rosidl_typesupport_introspection_c__CannyChainPos_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robot_interfaces__msg__CannyChainPos__rosidl_typesupport_introspection_c__CannyChainPos_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
