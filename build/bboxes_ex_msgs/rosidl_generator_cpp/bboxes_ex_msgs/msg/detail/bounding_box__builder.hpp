// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from bboxes_ex_msgs:msg/BoundingBox.idl
// generated code does not contain a copyright notice

#ifndef BBOXES_EX_MSGS__MSG__DETAIL__BOUNDING_BOX__BUILDER_HPP_
#define BBOXES_EX_MSGS__MSG__DETAIL__BOUNDING_BOX__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "bboxes_ex_msgs/msg/detail/bounding_box__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace bboxes_ex_msgs
{

namespace msg
{

namespace builder
{

class Init_BoundingBox_class_id_int
{
public:
  explicit Init_BoundingBox_class_id_int(::bboxes_ex_msgs::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  ::bboxes_ex_msgs::msg::BoundingBox class_id_int(::bboxes_ex_msgs::msg::BoundingBox::_class_id_int_type arg)
  {
    msg_.class_id_int = std::move(arg);
    return std::move(msg_);
  }

private:
  ::bboxes_ex_msgs::msg::BoundingBox msg_;
};

class Init_BoundingBox_class_id
{
public:
  explicit Init_BoundingBox_class_id(::bboxes_ex_msgs::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_class_id_int class_id(::bboxes_ex_msgs::msg::BoundingBox::_class_id_type arg)
  {
    msg_.class_id = std::move(arg);
    return Init_BoundingBox_class_id_int(msg_);
  }

private:
  ::bboxes_ex_msgs::msg::BoundingBox msg_;
};

class Init_BoundingBox_center_dist
{
public:
  explicit Init_BoundingBox_center_dist(::bboxes_ex_msgs::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_class_id center_dist(::bboxes_ex_msgs::msg::BoundingBox::_center_dist_type arg)
  {
    msg_.center_dist = std::move(arg);
    return Init_BoundingBox_class_id(msg_);
  }

private:
  ::bboxes_ex_msgs::msg::BoundingBox msg_;
};

class Init_BoundingBox_img_height
{
public:
  explicit Init_BoundingBox_img_height(::bboxes_ex_msgs::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_center_dist img_height(::bboxes_ex_msgs::msg::BoundingBox::_img_height_type arg)
  {
    msg_.img_height = std::move(arg);
    return Init_BoundingBox_center_dist(msg_);
  }

private:
  ::bboxes_ex_msgs::msg::BoundingBox msg_;
};

class Init_BoundingBox_img_width
{
public:
  explicit Init_BoundingBox_img_width(::bboxes_ex_msgs::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_img_height img_width(::bboxes_ex_msgs::msg::BoundingBox::_img_width_type arg)
  {
    msg_.img_width = std::move(arg);
    return Init_BoundingBox_img_height(msg_);
  }

private:
  ::bboxes_ex_msgs::msg::BoundingBox msg_;
};

class Init_BoundingBox_id
{
public:
  explicit Init_BoundingBox_id(::bboxes_ex_msgs::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_img_width id(::bboxes_ex_msgs::msg::BoundingBox::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_BoundingBox_img_width(msg_);
  }

private:
  ::bboxes_ex_msgs::msg::BoundingBox msg_;
};

class Init_BoundingBox_ymax
{
public:
  explicit Init_BoundingBox_ymax(::bboxes_ex_msgs::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_id ymax(::bboxes_ex_msgs::msg::BoundingBox::_ymax_type arg)
  {
    msg_.ymax = std::move(arg);
    return Init_BoundingBox_id(msg_);
  }

private:
  ::bboxes_ex_msgs::msg::BoundingBox msg_;
};

class Init_BoundingBox_xmax
{
public:
  explicit Init_BoundingBox_xmax(::bboxes_ex_msgs::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_ymax xmax(::bboxes_ex_msgs::msg::BoundingBox::_xmax_type arg)
  {
    msg_.xmax = std::move(arg);
    return Init_BoundingBox_ymax(msg_);
  }

private:
  ::bboxes_ex_msgs::msg::BoundingBox msg_;
};

class Init_BoundingBox_ymin
{
public:
  explicit Init_BoundingBox_ymin(::bboxes_ex_msgs::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_xmax ymin(::bboxes_ex_msgs::msg::BoundingBox::_ymin_type arg)
  {
    msg_.ymin = std::move(arg);
    return Init_BoundingBox_xmax(msg_);
  }

private:
  ::bboxes_ex_msgs::msg::BoundingBox msg_;
};

class Init_BoundingBox_xmin
{
public:
  explicit Init_BoundingBox_xmin(::bboxes_ex_msgs::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_ymin xmin(::bboxes_ex_msgs::msg::BoundingBox::_xmin_type arg)
  {
    msg_.xmin = std::move(arg);
    return Init_BoundingBox_ymin(msg_);
  }

private:
  ::bboxes_ex_msgs::msg::BoundingBox msg_;
};

class Init_BoundingBox_probability
{
public:
  Init_BoundingBox_probability()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoundingBox_xmin probability(::bboxes_ex_msgs::msg::BoundingBox::_probability_type arg)
  {
    msg_.probability = std::move(arg);
    return Init_BoundingBox_xmin(msg_);
  }

private:
  ::bboxes_ex_msgs::msg::BoundingBox msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::bboxes_ex_msgs::msg::BoundingBox>()
{
  return bboxes_ex_msgs::msg::builder::Init_BoundingBox_probability();
}

}  // namespace bboxes_ex_msgs

#endif  // BBOXES_EX_MSGS__MSG__DETAIL__BOUNDING_BOX__BUILDER_HPP_
