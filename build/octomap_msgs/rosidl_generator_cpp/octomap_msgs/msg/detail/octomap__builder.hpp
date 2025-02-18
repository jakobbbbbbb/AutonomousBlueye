// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from octomap_msgs:msg/Octomap.idl
// generated code does not contain a copyright notice

#ifndef OCTOMAP_MSGS__MSG__DETAIL__OCTOMAP__BUILDER_HPP_
#define OCTOMAP_MSGS__MSG__DETAIL__OCTOMAP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "octomap_msgs/msg/detail/octomap__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace octomap_msgs
{

namespace msg
{

namespace builder
{

class Init_Octomap_data
{
public:
  explicit Init_Octomap_data(::octomap_msgs::msg::Octomap & msg)
  : msg_(msg)
  {}
  ::octomap_msgs::msg::Octomap data(::octomap_msgs::msg::Octomap::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::octomap_msgs::msg::Octomap msg_;
};

class Init_Octomap_resolution
{
public:
  explicit Init_Octomap_resolution(::octomap_msgs::msg::Octomap & msg)
  : msg_(msg)
  {}
  Init_Octomap_data resolution(::octomap_msgs::msg::Octomap::_resolution_type arg)
  {
    msg_.resolution = std::move(arg);
    return Init_Octomap_data(msg_);
  }

private:
  ::octomap_msgs::msg::Octomap msg_;
};

class Init_Octomap_id
{
public:
  explicit Init_Octomap_id(::octomap_msgs::msg::Octomap & msg)
  : msg_(msg)
  {}
  Init_Octomap_resolution id(::octomap_msgs::msg::Octomap::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Octomap_resolution(msg_);
  }

private:
  ::octomap_msgs::msg::Octomap msg_;
};

class Init_Octomap_binary
{
public:
  explicit Init_Octomap_binary(::octomap_msgs::msg::Octomap & msg)
  : msg_(msg)
  {}
  Init_Octomap_id binary(::octomap_msgs::msg::Octomap::_binary_type arg)
  {
    msg_.binary = std::move(arg);
    return Init_Octomap_id(msg_);
  }

private:
  ::octomap_msgs::msg::Octomap msg_;
};

class Init_Octomap_header
{
public:
  Init_Octomap_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Octomap_binary header(::octomap_msgs::msg::Octomap::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Octomap_binary(msg_);
  }

private:
  ::octomap_msgs::msg::Octomap msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::octomap_msgs::msg::Octomap>()
{
  return octomap_msgs::msg::builder::Init_Octomap_header();
}

}  // namespace octomap_msgs

#endif  // OCTOMAP_MSGS__MSG__DETAIL__OCTOMAP__BUILDER_HPP_
