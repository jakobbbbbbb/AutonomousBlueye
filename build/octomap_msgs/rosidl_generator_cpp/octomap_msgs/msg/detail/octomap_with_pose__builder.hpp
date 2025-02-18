// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from octomap_msgs:msg/OctomapWithPose.idl
// generated code does not contain a copyright notice

#ifndef OCTOMAP_MSGS__MSG__DETAIL__OCTOMAP_WITH_POSE__BUILDER_HPP_
#define OCTOMAP_MSGS__MSG__DETAIL__OCTOMAP_WITH_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "octomap_msgs/msg/detail/octomap_with_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace octomap_msgs
{

namespace msg
{

namespace builder
{

class Init_OctomapWithPose_octomap
{
public:
  explicit Init_OctomapWithPose_octomap(::octomap_msgs::msg::OctomapWithPose & msg)
  : msg_(msg)
  {}
  ::octomap_msgs::msg::OctomapWithPose octomap(::octomap_msgs::msg::OctomapWithPose::_octomap_type arg)
  {
    msg_.octomap = std::move(arg);
    return std::move(msg_);
  }

private:
  ::octomap_msgs::msg::OctomapWithPose msg_;
};

class Init_OctomapWithPose_origin
{
public:
  explicit Init_OctomapWithPose_origin(::octomap_msgs::msg::OctomapWithPose & msg)
  : msg_(msg)
  {}
  Init_OctomapWithPose_octomap origin(::octomap_msgs::msg::OctomapWithPose::_origin_type arg)
  {
    msg_.origin = std::move(arg);
    return Init_OctomapWithPose_octomap(msg_);
  }

private:
  ::octomap_msgs::msg::OctomapWithPose msg_;
};

class Init_OctomapWithPose_header
{
public:
  Init_OctomapWithPose_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OctomapWithPose_origin header(::octomap_msgs::msg::OctomapWithPose::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_OctomapWithPose_origin(msg_);
  }

private:
  ::octomap_msgs::msg::OctomapWithPose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::octomap_msgs::msg::OctomapWithPose>()
{
  return octomap_msgs::msg::builder::Init_OctomapWithPose_header();
}

}  // namespace octomap_msgs

#endif  // OCTOMAP_MSGS__MSG__DETAIL__OCTOMAP_WITH_POSE__BUILDER_HPP_
