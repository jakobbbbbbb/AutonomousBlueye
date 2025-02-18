// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:msg/YoloMedianChainPose.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__YOLO_MEDIAN_CHAIN_POSE__BUILDER_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__YOLO_MEDIAN_CHAIN_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/msg/detail/yolo_median_chain_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_YoloMedianChainPose_width
{
public:
  explicit Init_YoloMedianChainPose_width(::robot_interfaces::msg::YoloMedianChainPose & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::msg::YoloMedianChainPose width(::robot_interfaces::msg::YoloMedianChainPose::_width_type arg)
  {
    msg_.width = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::msg::YoloMedianChainPose msg_;
};

class Init_YoloMedianChainPose_angle_degrees
{
public:
  explicit Init_YoloMedianChainPose_angle_degrees(::robot_interfaces::msg::YoloMedianChainPose & msg)
  : msg_(msg)
  {}
  Init_YoloMedianChainPose_width angle_degrees(::robot_interfaces::msg::YoloMedianChainPose::_angle_degrees_type arg)
  {
    msg_.angle_degrees = std::move(arg);
    return Init_YoloMedianChainPose_width(msg_);
  }

private:
  ::robot_interfaces::msg::YoloMedianChainPose msg_;
};

class Init_YoloMedianChainPose_mid_y
{
public:
  explicit Init_YoloMedianChainPose_mid_y(::robot_interfaces::msg::YoloMedianChainPose & msg)
  : msg_(msg)
  {}
  Init_YoloMedianChainPose_angle_degrees mid_y(::robot_interfaces::msg::YoloMedianChainPose::_mid_y_type arg)
  {
    msg_.mid_y = std::move(arg);
    return Init_YoloMedianChainPose_angle_degrees(msg_);
  }

private:
  ::robot_interfaces::msg::YoloMedianChainPose msg_;
};

class Init_YoloMedianChainPose_mid_x
{
public:
  Init_YoloMedianChainPose_mid_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_YoloMedianChainPose_mid_y mid_x(::robot_interfaces::msg::YoloMedianChainPose::_mid_x_type arg)
  {
    msg_.mid_x = std::move(arg);
    return Init_YoloMedianChainPose_mid_y(msg_);
  }

private:
  ::robot_interfaces::msg::YoloMedianChainPose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::msg::YoloMedianChainPose>()
{
  return robot_interfaces::msg::builder::Init_YoloMedianChainPose_mid_x();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__YOLO_MEDIAN_CHAIN_POSE__BUILDER_HPP_
