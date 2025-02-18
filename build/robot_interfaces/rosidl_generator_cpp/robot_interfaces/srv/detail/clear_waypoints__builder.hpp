// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:srv/ClearWaypoints.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__CLEAR_WAYPOINTS__BUILDER_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__CLEAR_WAYPOINTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/srv/detail/clear_waypoints__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_ClearWaypoints_Request_clear
{
public:
  Init_ClearWaypoints_Request_clear()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_interfaces::srv::ClearWaypoints_Request clear(::robot_interfaces::srv::ClearWaypoints_Request::_clear_type arg)
  {
    msg_.clear = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::ClearWaypoints_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::ClearWaypoints_Request>()
{
  return robot_interfaces::srv::builder::Init_ClearWaypoints_Request_clear();
}

}  // namespace robot_interfaces


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_ClearWaypoints_Response_accepted
{
public:
  Init_ClearWaypoints_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_interfaces::srv::ClearWaypoints_Response accepted(::robot_interfaces::srv::ClearWaypoints_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::ClearWaypoints_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::ClearWaypoints_Response>()
{
  return robot_interfaces::srv::builder::Init_ClearWaypoints_Response_accepted();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__SRV__DETAIL__CLEAR_WAYPOINTS__BUILDER_HPP_
