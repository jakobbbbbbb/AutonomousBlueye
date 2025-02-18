// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:srv/AddWaypoint.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__ADD_WAYPOINT__BUILDER_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__ADD_WAYPOINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/srv/detail/add_waypoint__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_AddWaypoint_Request_position
{
public:
  explicit Init_AddWaypoint_Request_position(::robot_interfaces::srv::AddWaypoint_Request & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::srv::AddWaypoint_Request position(::robot_interfaces::srv::AddWaypoint_Request::_position_type arg)
  {
    msg_.position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::AddWaypoint_Request msg_;
};

class Init_AddWaypoint_Request_z
{
public:
  explicit Init_AddWaypoint_Request_z(::robot_interfaces::srv::AddWaypoint_Request & msg)
  : msg_(msg)
  {}
  Init_AddWaypoint_Request_position z(::robot_interfaces::srv::AddWaypoint_Request::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_AddWaypoint_Request_position(msg_);
  }

private:
  ::robot_interfaces::srv::AddWaypoint_Request msg_;
};

class Init_AddWaypoint_Request_y
{
public:
  explicit Init_AddWaypoint_Request_y(::robot_interfaces::srv::AddWaypoint_Request & msg)
  : msg_(msg)
  {}
  Init_AddWaypoint_Request_z y(::robot_interfaces::srv::AddWaypoint_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_AddWaypoint_Request_z(msg_);
  }

private:
  ::robot_interfaces::srv::AddWaypoint_Request msg_;
};

class Init_AddWaypoint_Request_x
{
public:
  Init_AddWaypoint_Request_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AddWaypoint_Request_y x(::robot_interfaces::srv::AddWaypoint_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_AddWaypoint_Request_y(msg_);
  }

private:
  ::robot_interfaces::srv::AddWaypoint_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::AddWaypoint_Request>()
{
  return robot_interfaces::srv::builder::Init_AddWaypoint_Request_x();
}

}  // namespace robot_interfaces


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_AddWaypoint_Response_accepted
{
public:
  Init_AddWaypoint_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_interfaces::srv::AddWaypoint_Response accepted(::robot_interfaces::srv::AddWaypoint_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::AddWaypoint_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::AddWaypoint_Response>()
{
  return robot_interfaces::srv::builder::Init_AddWaypoint_Response_accepted();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__SRV__DETAIL__ADD_WAYPOINT__BUILDER_HPP_
