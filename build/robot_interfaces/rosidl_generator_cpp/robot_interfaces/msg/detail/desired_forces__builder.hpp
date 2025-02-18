// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:msg/DesiredForces.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__DESIRED_FORCES__BUILDER_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__DESIRED_FORCES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/msg/detail/desired_forces__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_DesiredForces_yaw
{
public:
  explicit Init_DesiredForces_yaw(::robot_interfaces::msg::DesiredForces & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::msg::DesiredForces yaw(::robot_interfaces::msg::DesiredForces::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::msg::DesiredForces msg_;
};

class Init_DesiredForces_pitch
{
public:
  explicit Init_DesiredForces_pitch(::robot_interfaces::msg::DesiredForces & msg)
  : msg_(msg)
  {}
  Init_DesiredForces_yaw pitch(::robot_interfaces::msg::DesiredForces::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_DesiredForces_yaw(msg_);
  }

private:
  ::robot_interfaces::msg::DesiredForces msg_;
};

class Init_DesiredForces_roll
{
public:
  explicit Init_DesiredForces_roll(::robot_interfaces::msg::DesiredForces & msg)
  : msg_(msg)
  {}
  Init_DesiredForces_pitch roll(::robot_interfaces::msg::DesiredForces::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_DesiredForces_pitch(msg_);
  }

private:
  ::robot_interfaces::msg::DesiredForces msg_;
};

class Init_DesiredForces_heave
{
public:
  explicit Init_DesiredForces_heave(::robot_interfaces::msg::DesiredForces & msg)
  : msg_(msg)
  {}
  Init_DesiredForces_roll heave(::robot_interfaces::msg::DesiredForces::_heave_type arg)
  {
    msg_.heave = std::move(arg);
    return Init_DesiredForces_roll(msg_);
  }

private:
  ::robot_interfaces::msg::DesiredForces msg_;
};

class Init_DesiredForces_sway
{
public:
  explicit Init_DesiredForces_sway(::robot_interfaces::msg::DesiredForces & msg)
  : msg_(msg)
  {}
  Init_DesiredForces_heave sway(::robot_interfaces::msg::DesiredForces::_sway_type arg)
  {
    msg_.sway = std::move(arg);
    return Init_DesiredForces_heave(msg_);
  }

private:
  ::robot_interfaces::msg::DesiredForces msg_;
};

class Init_DesiredForces_surge
{
public:
  Init_DesiredForces_surge()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DesiredForces_sway surge(::robot_interfaces::msg::DesiredForces::_surge_type arg)
  {
    msg_.surge = std::move(arg);
    return Init_DesiredForces_sway(msg_);
  }

private:
  ::robot_interfaces::msg::DesiredForces msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::msg::DesiredForces>()
{
  return robot_interfaces::msg::builder::Init_DesiredForces_surge();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__DESIRED_FORCES__BUILDER_HPP_
