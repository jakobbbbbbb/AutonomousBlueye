// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:msg/YoloBox.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__YOLO_BOX__BUILDER_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__YOLO_BOX__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/msg/detail/yolo_box__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_YoloBox_y_max
{
public:
  explicit Init_YoloBox_y_max(::robot_interfaces::msg::YoloBox & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::msg::YoloBox y_max(::robot_interfaces::msg::YoloBox::_y_max_type arg)
  {
    msg_.y_max = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::msg::YoloBox msg_;
};

class Init_YoloBox_x_max
{
public:
  explicit Init_YoloBox_x_max(::robot_interfaces::msg::YoloBox & msg)
  : msg_(msg)
  {}
  Init_YoloBox_y_max x_max(::robot_interfaces::msg::YoloBox::_x_max_type arg)
  {
    msg_.x_max = std::move(arg);
    return Init_YoloBox_y_max(msg_);
  }

private:
  ::robot_interfaces::msg::YoloBox msg_;
};

class Init_YoloBox_y_min
{
public:
  explicit Init_YoloBox_y_min(::robot_interfaces::msg::YoloBox & msg)
  : msg_(msg)
  {}
  Init_YoloBox_x_max y_min(::robot_interfaces::msg::YoloBox::_y_min_type arg)
  {
    msg_.y_min = std::move(arg);
    return Init_YoloBox_x_max(msg_);
  }

private:
  ::robot_interfaces::msg::YoloBox msg_;
};

class Init_YoloBox_x_min
{
public:
  explicit Init_YoloBox_x_min(::robot_interfaces::msg::YoloBox & msg)
  : msg_(msg)
  {}
  Init_YoloBox_y_min x_min(::robot_interfaces::msg::YoloBox::_x_min_type arg)
  {
    msg_.x_min = std::move(arg);
    return Init_YoloBox_y_min(msg_);
  }

private:
  ::robot_interfaces::msg::YoloBox msg_;
};

class Init_YoloBox_confidence
{
public:
  explicit Init_YoloBox_confidence(::robot_interfaces::msg::YoloBox & msg)
  : msg_(msg)
  {}
  Init_YoloBox_x_min confidence(::robot_interfaces::msg::YoloBox::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_YoloBox_x_min(msg_);
  }

private:
  ::robot_interfaces::msg::YoloBox msg_;
};

class Init_YoloBox_cls
{
public:
  Init_YoloBox_cls()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_YoloBox_confidence cls(::robot_interfaces::msg::YoloBox::_cls_type arg)
  {
    msg_.cls = std::move(arg);
    return Init_YoloBox_confidence(msg_);
  }

private:
  ::robot_interfaces::msg::YoloBox msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::msg::YoloBox>()
{
  return robot_interfaces::msg::builder::Init_YoloBox_cls();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__YOLO_BOX__BUILDER_HPP_
