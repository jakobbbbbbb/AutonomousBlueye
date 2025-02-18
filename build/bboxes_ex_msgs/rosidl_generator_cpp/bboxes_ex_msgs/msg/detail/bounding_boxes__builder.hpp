// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from bboxes_ex_msgs:msg/BoundingBoxes.idl
// generated code does not contain a copyright notice

#ifndef BBOXES_EX_MSGS__MSG__DETAIL__BOUNDING_BOXES__BUILDER_HPP_
#define BBOXES_EX_MSGS__MSG__DETAIL__BOUNDING_BOXES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "bboxes_ex_msgs/msg/detail/bounding_boxes__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace bboxes_ex_msgs
{

namespace msg
{

namespace builder
{

class Init_BoundingBoxes_bounding_boxes
{
public:
  explicit Init_BoundingBoxes_bounding_boxes(::bboxes_ex_msgs::msg::BoundingBoxes & msg)
  : msg_(msg)
  {}
  ::bboxes_ex_msgs::msg::BoundingBoxes bounding_boxes(::bboxes_ex_msgs::msg::BoundingBoxes::_bounding_boxes_type arg)
  {
    msg_.bounding_boxes = std::move(arg);
    return std::move(msg_);
  }

private:
  ::bboxes_ex_msgs::msg::BoundingBoxes msg_;
};

class Init_BoundingBoxes_image_header
{
public:
  explicit Init_BoundingBoxes_image_header(::bboxes_ex_msgs::msg::BoundingBoxes & msg)
  : msg_(msg)
  {}
  Init_BoundingBoxes_bounding_boxes image_header(::bboxes_ex_msgs::msg::BoundingBoxes::_image_header_type arg)
  {
    msg_.image_header = std::move(arg);
    return Init_BoundingBoxes_bounding_boxes(msg_);
  }

private:
  ::bboxes_ex_msgs::msg::BoundingBoxes msg_;
};

class Init_BoundingBoxes_header
{
public:
  Init_BoundingBoxes_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoundingBoxes_image_header header(::bboxes_ex_msgs::msg::BoundingBoxes::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_BoundingBoxes_image_header(msg_);
  }

private:
  ::bboxes_ex_msgs::msg::BoundingBoxes msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::bboxes_ex_msgs::msg::BoundingBoxes>()
{
  return bboxes_ex_msgs::msg::builder::Init_BoundingBoxes_header();
}

}  // namespace bboxes_ex_msgs

#endif  // BBOXES_EX_MSGS__MSG__DETAIL__BOUNDING_BOXES__BUILDER_HPP_
