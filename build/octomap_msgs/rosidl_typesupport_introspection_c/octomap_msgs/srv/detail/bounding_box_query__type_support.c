// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from octomap_msgs:srv/BoundingBoxQuery.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "octomap_msgs/srv/detail/bounding_box_query__rosidl_typesupport_introspection_c.h"
#include "octomap_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "octomap_msgs/srv/detail/bounding_box_query__functions.h"
#include "octomap_msgs/srv/detail/bounding_box_query__struct.h"


// Include directives for member types
// Member `min`
// Member `max`
#include "geometry_msgs/msg/point.h"
// Member `min`
// Member `max`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void octomap_msgs__srv__BoundingBoxQuery_Request__rosidl_typesupport_introspection_c__BoundingBoxQuery_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  octomap_msgs__srv__BoundingBoxQuery_Request__init(message_memory);
}

void octomap_msgs__srv__BoundingBoxQuery_Request__rosidl_typesupport_introspection_c__BoundingBoxQuery_Request_fini_function(void * message_memory)
{
  octomap_msgs__srv__BoundingBoxQuery_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember octomap_msgs__srv__BoundingBoxQuery_Request__rosidl_typesupport_introspection_c__BoundingBoxQuery_Request_message_member_array[2] = {
  {
    "min",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(octomap_msgs__srv__BoundingBoxQuery_Request, min),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "max",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(octomap_msgs__srv__BoundingBoxQuery_Request, max),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers octomap_msgs__srv__BoundingBoxQuery_Request__rosidl_typesupport_introspection_c__BoundingBoxQuery_Request_message_members = {
  "octomap_msgs__srv",  // message namespace
  "BoundingBoxQuery_Request",  // message name
  2,  // number of fields
  sizeof(octomap_msgs__srv__BoundingBoxQuery_Request),
  octomap_msgs__srv__BoundingBoxQuery_Request__rosidl_typesupport_introspection_c__BoundingBoxQuery_Request_message_member_array,  // message members
  octomap_msgs__srv__BoundingBoxQuery_Request__rosidl_typesupport_introspection_c__BoundingBoxQuery_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  octomap_msgs__srv__BoundingBoxQuery_Request__rosidl_typesupport_introspection_c__BoundingBoxQuery_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t octomap_msgs__srv__BoundingBoxQuery_Request__rosidl_typesupport_introspection_c__BoundingBoxQuery_Request_message_type_support_handle = {
  0,
  &octomap_msgs__srv__BoundingBoxQuery_Request__rosidl_typesupport_introspection_c__BoundingBoxQuery_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_octomap_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, octomap_msgs, srv, BoundingBoxQuery_Request)() {
  octomap_msgs__srv__BoundingBoxQuery_Request__rosidl_typesupport_introspection_c__BoundingBoxQuery_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  octomap_msgs__srv__BoundingBoxQuery_Request__rosidl_typesupport_introspection_c__BoundingBoxQuery_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!octomap_msgs__srv__BoundingBoxQuery_Request__rosidl_typesupport_introspection_c__BoundingBoxQuery_Request_message_type_support_handle.typesupport_identifier) {
    octomap_msgs__srv__BoundingBoxQuery_Request__rosidl_typesupport_introspection_c__BoundingBoxQuery_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &octomap_msgs__srv__BoundingBoxQuery_Request__rosidl_typesupport_introspection_c__BoundingBoxQuery_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "octomap_msgs/srv/detail/bounding_box_query__rosidl_typesupport_introspection_c.h"
// already included above
// #include "octomap_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "octomap_msgs/srv/detail/bounding_box_query__functions.h"
// already included above
// #include "octomap_msgs/srv/detail/bounding_box_query__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void octomap_msgs__srv__BoundingBoxQuery_Response__rosidl_typesupport_introspection_c__BoundingBoxQuery_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  octomap_msgs__srv__BoundingBoxQuery_Response__init(message_memory);
}

void octomap_msgs__srv__BoundingBoxQuery_Response__rosidl_typesupport_introspection_c__BoundingBoxQuery_Response_fini_function(void * message_memory)
{
  octomap_msgs__srv__BoundingBoxQuery_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember octomap_msgs__srv__BoundingBoxQuery_Response__rosidl_typesupport_introspection_c__BoundingBoxQuery_Response_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(octomap_msgs__srv__BoundingBoxQuery_Response, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers octomap_msgs__srv__BoundingBoxQuery_Response__rosidl_typesupport_introspection_c__BoundingBoxQuery_Response_message_members = {
  "octomap_msgs__srv",  // message namespace
  "BoundingBoxQuery_Response",  // message name
  1,  // number of fields
  sizeof(octomap_msgs__srv__BoundingBoxQuery_Response),
  octomap_msgs__srv__BoundingBoxQuery_Response__rosidl_typesupport_introspection_c__BoundingBoxQuery_Response_message_member_array,  // message members
  octomap_msgs__srv__BoundingBoxQuery_Response__rosidl_typesupport_introspection_c__BoundingBoxQuery_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  octomap_msgs__srv__BoundingBoxQuery_Response__rosidl_typesupport_introspection_c__BoundingBoxQuery_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t octomap_msgs__srv__BoundingBoxQuery_Response__rosidl_typesupport_introspection_c__BoundingBoxQuery_Response_message_type_support_handle = {
  0,
  &octomap_msgs__srv__BoundingBoxQuery_Response__rosidl_typesupport_introspection_c__BoundingBoxQuery_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_octomap_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, octomap_msgs, srv, BoundingBoxQuery_Response)() {
  if (!octomap_msgs__srv__BoundingBoxQuery_Response__rosidl_typesupport_introspection_c__BoundingBoxQuery_Response_message_type_support_handle.typesupport_identifier) {
    octomap_msgs__srv__BoundingBoxQuery_Response__rosidl_typesupport_introspection_c__BoundingBoxQuery_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &octomap_msgs__srv__BoundingBoxQuery_Response__rosidl_typesupport_introspection_c__BoundingBoxQuery_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "octomap_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "octomap_msgs/srv/detail/bounding_box_query__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers octomap_msgs__srv__detail__bounding_box_query__rosidl_typesupport_introspection_c__BoundingBoxQuery_service_members = {
  "octomap_msgs__srv",  // service namespace
  "BoundingBoxQuery",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // octomap_msgs__srv__detail__bounding_box_query__rosidl_typesupport_introspection_c__BoundingBoxQuery_Request_message_type_support_handle,
  NULL  // response message
  // octomap_msgs__srv__detail__bounding_box_query__rosidl_typesupport_introspection_c__BoundingBoxQuery_Response_message_type_support_handle
};

static rosidl_service_type_support_t octomap_msgs__srv__detail__bounding_box_query__rosidl_typesupport_introspection_c__BoundingBoxQuery_service_type_support_handle = {
  0,
  &octomap_msgs__srv__detail__bounding_box_query__rosidl_typesupport_introspection_c__BoundingBoxQuery_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, octomap_msgs, srv, BoundingBoxQuery_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, octomap_msgs, srv, BoundingBoxQuery_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_octomap_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, octomap_msgs, srv, BoundingBoxQuery)() {
  if (!octomap_msgs__srv__detail__bounding_box_query__rosidl_typesupport_introspection_c__BoundingBoxQuery_service_type_support_handle.typesupport_identifier) {
    octomap_msgs__srv__detail__bounding_box_query__rosidl_typesupport_introspection_c__BoundingBoxQuery_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)octomap_msgs__srv__detail__bounding_box_query__rosidl_typesupport_introspection_c__BoundingBoxQuery_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, octomap_msgs, srv, BoundingBoxQuery_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, octomap_msgs, srv, BoundingBoxQuery_Response)()->data;
  }

  return &octomap_msgs__srv__detail__bounding_box_query__rosidl_typesupport_introspection_c__BoundingBoxQuery_service_type_support_handle;
}
