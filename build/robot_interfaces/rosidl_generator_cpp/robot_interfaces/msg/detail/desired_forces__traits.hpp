// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_interfaces:msg/DesiredForces.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__DESIRED_FORCES__TRAITS_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__DESIRED_FORCES__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_interfaces/msg/detail/desired_forces__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const DesiredForces & msg,
  std::ostream & out)
{
  out << "{";
  // member: surge
  {
    out << "surge: ";
    rosidl_generator_traits::value_to_yaml(msg.surge, out);
    out << ", ";
  }

  // member: sway
  {
    out << "sway: ";
    rosidl_generator_traits::value_to_yaml(msg.sway, out);
    out << ", ";
  }

  // member: heave
  {
    out << "heave: ";
    rosidl_generator_traits::value_to_yaml(msg.heave, out);
    out << ", ";
  }

  // member: roll
  {
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << ", ";
  }

  // member: pitch
  {
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << ", ";
  }

  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DesiredForces & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: surge
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "surge: ";
    rosidl_generator_traits::value_to_yaml(msg.surge, out);
    out << "\n";
  }

  // member: sway
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sway: ";
    rosidl_generator_traits::value_to_yaml(msg.sway, out);
    out << "\n";
  }

  // member: heave
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "heave: ";
    rosidl_generator_traits::value_to_yaml(msg.heave, out);
    out << "\n";
  }

  // member: roll
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << "\n";
  }

  // member: pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << "\n";
  }

  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DesiredForces & msg, bool use_flow_style = false)
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
  const robot_interfaces::msg::DesiredForces & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const robot_interfaces::msg::DesiredForces & msg)
{
  return robot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<robot_interfaces::msg::DesiredForces>()
{
  return "robot_interfaces::msg::DesiredForces";
}

template<>
inline const char * name<robot_interfaces::msg::DesiredForces>()
{
  return "robot_interfaces/msg/DesiredForces";
}

template<>
struct has_fixed_size<robot_interfaces::msg::DesiredForces>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robot_interfaces::msg::DesiredForces>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robot_interfaces::msg::DesiredForces>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_INTERFACES__MSG__DETAIL__DESIRED_FORCES__TRAITS_HPP_
