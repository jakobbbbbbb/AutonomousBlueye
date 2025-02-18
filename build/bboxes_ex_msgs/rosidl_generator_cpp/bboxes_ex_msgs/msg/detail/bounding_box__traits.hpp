// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from bboxes_ex_msgs:msg/BoundingBox.idl
// generated code does not contain a copyright notice

#ifndef BBOXES_EX_MSGS__MSG__DETAIL__BOUNDING_BOX__TRAITS_HPP_
#define BBOXES_EX_MSGS__MSG__DETAIL__BOUNDING_BOX__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "bboxes_ex_msgs/msg/detail/bounding_box__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace bboxes_ex_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const BoundingBox & msg,
  std::ostream & out)
{
  out << "{";
  // member: probability
  {
    out << "probability: ";
    rosidl_generator_traits::value_to_yaml(msg.probability, out);
    out << ", ";
  }

  // member: xmin
  {
    out << "xmin: ";
    rosidl_generator_traits::value_to_yaml(msg.xmin, out);
    out << ", ";
  }

  // member: ymin
  {
    out << "ymin: ";
    rosidl_generator_traits::value_to_yaml(msg.ymin, out);
    out << ", ";
  }

  // member: xmax
  {
    out << "xmax: ";
    rosidl_generator_traits::value_to_yaml(msg.xmax, out);
    out << ", ";
  }

  // member: ymax
  {
    out << "ymax: ";
    rosidl_generator_traits::value_to_yaml(msg.ymax, out);
    out << ", ";
  }

  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: img_width
  {
    out << "img_width: ";
    rosidl_generator_traits::value_to_yaml(msg.img_width, out);
    out << ", ";
  }

  // member: img_height
  {
    out << "img_height: ";
    rosidl_generator_traits::value_to_yaml(msg.img_height, out);
    out << ", ";
  }

  // member: center_dist
  {
    out << "center_dist: ";
    rosidl_generator_traits::value_to_yaml(msg.center_dist, out);
    out << ", ";
  }

  // member: class_id
  {
    out << "class_id: ";
    rosidl_generator_traits::value_to_yaml(msg.class_id, out);
    out << ", ";
  }

  // member: class_id_int
  {
    out << "class_id_int: ";
    rosidl_generator_traits::value_to_yaml(msg.class_id_int, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BoundingBox & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: probability
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "probability: ";
    rosidl_generator_traits::value_to_yaml(msg.probability, out);
    out << "\n";
  }

  // member: xmin
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "xmin: ";
    rosidl_generator_traits::value_to_yaml(msg.xmin, out);
    out << "\n";
  }

  // member: ymin
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ymin: ";
    rosidl_generator_traits::value_to_yaml(msg.ymin, out);
    out << "\n";
  }

  // member: xmax
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "xmax: ";
    rosidl_generator_traits::value_to_yaml(msg.xmax, out);
    out << "\n";
  }

  // member: ymax
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ymax: ";
    rosidl_generator_traits::value_to_yaml(msg.ymax, out);
    out << "\n";
  }

  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: img_width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "img_width: ";
    rosidl_generator_traits::value_to_yaml(msg.img_width, out);
    out << "\n";
  }

  // member: img_height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "img_height: ";
    rosidl_generator_traits::value_to_yaml(msg.img_height, out);
    out << "\n";
  }

  // member: center_dist
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_dist: ";
    rosidl_generator_traits::value_to_yaml(msg.center_dist, out);
    out << "\n";
  }

  // member: class_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "class_id: ";
    rosidl_generator_traits::value_to_yaml(msg.class_id, out);
    out << "\n";
  }

  // member: class_id_int
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "class_id_int: ";
    rosidl_generator_traits::value_to_yaml(msg.class_id_int, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BoundingBox & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace bboxes_ex_msgs

namespace rosidl_generator_traits
{

[[deprecated("use bboxes_ex_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const bboxes_ex_msgs::msg::BoundingBox & msg,
  std::ostream & out, size_t indentation = 0)
{
  bboxes_ex_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use bboxes_ex_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const bboxes_ex_msgs::msg::BoundingBox & msg)
{
  return bboxes_ex_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<bboxes_ex_msgs::msg::BoundingBox>()
{
  return "bboxes_ex_msgs::msg::BoundingBox";
}

template<>
inline const char * name<bboxes_ex_msgs::msg::BoundingBox>()
{
  return "bboxes_ex_msgs/msg/BoundingBox";
}

template<>
struct has_fixed_size<bboxes_ex_msgs::msg::BoundingBox>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<bboxes_ex_msgs::msg::BoundingBox>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<bboxes_ex_msgs::msg::BoundingBox>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BBOXES_EX_MSGS__MSG__DETAIL__BOUNDING_BOX__TRAITS_HPP_
