// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:msg/DesiredVelocity.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__DESIRED_VELOCITY__BUILDER_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__DESIRED_VELOCITY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/msg/detail/desired_velocity__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_DesiredVelocity_yaw
{
public:
  explicit Init_DesiredVelocity_yaw(::robot_interfaces::msg::DesiredVelocity & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::msg::DesiredVelocity yaw(::robot_interfaces::msg::DesiredVelocity::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::msg::DesiredVelocity msg_;
};

class Init_DesiredVelocity_heave
{
public:
  explicit Init_DesiredVelocity_heave(::robot_interfaces::msg::DesiredVelocity & msg)
  : msg_(msg)
  {}
  Init_DesiredVelocity_yaw heave(::robot_interfaces::msg::DesiredVelocity::_heave_type arg)
  {
    msg_.heave = std::move(arg);
    return Init_DesiredVelocity_yaw(msg_);
  }

private:
  ::robot_interfaces::msg::DesiredVelocity msg_;
};

class Init_DesiredVelocity_sway
{
public:
  explicit Init_DesiredVelocity_sway(::robot_interfaces::msg::DesiredVelocity & msg)
  : msg_(msg)
  {}
  Init_DesiredVelocity_heave sway(::robot_interfaces::msg::DesiredVelocity::_sway_type arg)
  {
    msg_.sway = std::move(arg);
    return Init_DesiredVelocity_heave(msg_);
  }

private:
  ::robot_interfaces::msg::DesiredVelocity msg_;
};

class Init_DesiredVelocity_surge
{
public:
  Init_DesiredVelocity_surge()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DesiredVelocity_sway surge(::robot_interfaces::msg::DesiredVelocity::_surge_type arg)
  {
    msg_.surge = std::move(arg);
    return Init_DesiredVelocity_sway(msg_);
  }

private:
  ::robot_interfaces::msg::DesiredVelocity msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::msg::DesiredVelocity>()
{
  return robot_interfaces::msg::builder::Init_DesiredVelocity_surge();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__DESIRED_VELOCITY__BUILDER_HPP_
