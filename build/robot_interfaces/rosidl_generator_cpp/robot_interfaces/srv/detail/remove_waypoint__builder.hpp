// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:srv/RemoveWaypoint.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__REMOVE_WAYPOINT__BUILDER_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__REMOVE_WAYPOINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/srv/detail/remove_waypoint__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_RemoveWaypoint_Request_position
{
public:
  Init_RemoveWaypoint_Request_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_interfaces::srv::RemoveWaypoint_Request position(::robot_interfaces::srv::RemoveWaypoint_Request::_position_type arg)
  {
    msg_.position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::RemoveWaypoint_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::RemoveWaypoint_Request>()
{
  return robot_interfaces::srv::builder::Init_RemoveWaypoint_Request_position();
}

}  // namespace robot_interfaces


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_RemoveWaypoint_Response_accepted
{
public:
  Init_RemoveWaypoint_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_interfaces::srv::RemoveWaypoint_Response accepted(::robot_interfaces::srv::RemoveWaypoint_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::RemoveWaypoint_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::RemoveWaypoint_Response>()
{
  return robot_interfaces::srv::builder::Init_RemoveWaypoint_Response_accepted();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__SRV__DETAIL__REMOVE_WAYPOINT__BUILDER_HPP_
