// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_interfaces:msg/YoloCannyChainPose.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__YOLO_CANNY_CHAIN_POSE__TRAITS_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__YOLO_CANNY_CHAIN_POSE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_interfaces/msg/detail/yolo_canny_chain_pose__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const YoloCannyChainPose & msg,
  std::ostream & out)
{
  out << "{";
  // member: mid_x
  {
    out << "mid_x: ";
    rosidl_generator_traits::value_to_yaml(msg.mid_x, out);
    out << ", ";
  }

  // member: mid_y
  {
    out << "mid_y: ";
    rosidl_generator_traits::value_to_yaml(msg.mid_y, out);
    out << ", ";
  }

  // member: angle_degrees
  {
    out << "angle_degrees: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_degrees, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const YoloCannyChainPose & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mid_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mid_x: ";
    rosidl_generator_traits::value_to_yaml(msg.mid_x, out);
    out << "\n";
  }

  // member: mid_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mid_y: ";
    rosidl_generator_traits::value_to_yaml(msg.mid_y, out);
    out << "\n";
  }

  // member: angle_degrees
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle_degrees: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_degrees, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const YoloCannyChainPose & msg, bool use_flow_style = false)
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

}  // namespace robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robot_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_interfaces::msg::YoloCannyChainPose & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const robot_interfaces::msg::YoloCannyChainPose & msg)
{
  return robot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<robot_interfaces::msg::YoloCannyChainPose>()
{
  return "robot_interfaces::msg::YoloCannyChainPose";
}

template<>
inline const char * name<robot_interfaces::msg::YoloCannyChainPose>()
{
  return "robot_interfaces/msg/YoloCannyChainPose";
}

template<>
struct has_fixed_size<robot_interfaces::msg::YoloCannyChainPose>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robot_interfaces::msg::YoloCannyChainPose>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robot_interfaces::msg::YoloCannyChainPose>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_INTERFACES__MSG__DETAIL__YOLO_CANNY_CHAIN_POSE__TRAITS_HPP_
