// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from octomap_msgs:srv/GetOctomap.idl
// generated code does not contain a copyright notice

#ifndef OCTOMAP_MSGS__SRV__DETAIL__GET_OCTOMAP__BUILDER_HPP_
#define OCTOMAP_MSGS__SRV__DETAIL__GET_OCTOMAP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "octomap_msgs/srv/detail/get_octomap__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace octomap_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::octomap_msgs::srv::GetOctomap_Request>()
{
  return ::octomap_msgs::srv::GetOctomap_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace octomap_msgs


namespace octomap_msgs
{

namespace srv
{

namespace builder
{

class Init_GetOctomap_Response_map
{
public:
  Init_GetOctomap_Response_map()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::octomap_msgs::srv::GetOctomap_Response map(::octomap_msgs::srv::GetOctomap_Response::_map_type arg)
  {
    msg_.map = std::move(arg);
    return std::move(msg_);
  }

private:
  ::octomap_msgs::srv::GetOctomap_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::octomap_msgs::srv::GetOctomap_Response>()
{
  return octomap_msgs::srv::builder::Init_GetOctomap_Response_map();
}

}  // namespace octomap_msgs

#endif  // OCTOMAP_MSGS__SRV__DETAIL__GET_OCTOMAP__BUILDER_HPP_
