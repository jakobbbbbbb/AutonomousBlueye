// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:srv/SetState.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__SET_STATE__BUILDER_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__SET_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/srv/detail/set_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetState_Request_state
{
public:
  Init_SetState_Request_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_interfaces::srv::SetState_Request state(::robot_interfaces::srv::SetState_Request::_state_type arg)
  {
    msg_.state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::SetState_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::SetState_Request>()
{
  return robot_interfaces::srv::builder::Init_SetState_Request_state();
}

}  // namespace robot_interfaces


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetState_Response_accepted
{
public:
  Init_SetState_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_interfaces::srv::SetState_Response accepted(::robot_interfaces::srv::SetState_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::SetState_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::SetState_Response>()
{
  return robot_interfaces::srv::builder::Init_SetState_Response_accepted();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__SRV__DETAIL__SET_STATE__BUILDER_HPP_
