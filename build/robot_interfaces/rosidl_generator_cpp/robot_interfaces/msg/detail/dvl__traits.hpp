// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_interfaces:msg/DVL.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__DVL__TRAITS_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__DVL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_interfaces/msg/detail/dvl__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'vel_body'
// Member 'uncertainty_vel'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace robot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const DVL & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: vel_body
  {
    out << "vel_body: ";
    to_flow_style_yaml(msg.vel_body, out);
    out << ", ";
  }

  // member: uncertainty_vel
  {
    out << "uncertainty_vel: ";
    to_flow_style_yaml(msg.uncertainty_vel, out);
    out << ", ";
  }

  // member: vel_beam1
  {
    out << "vel_beam1: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_beam1, out);
    out << ", ";
  }

  // member: vel_beam2
  {
    out << "vel_beam2: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_beam2, out);
    out << ", ";
  }

  // member: vel_beam3
  {
    out << "vel_beam3: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_beam3, out);
    out << ", ";
  }

  // member: uncertainty_beam1
  {
    out << "uncertainty_beam1: ";
    rosidl_generator_traits::value_to_yaml(msg.uncertainty_beam1, out);
    out << ", ";
  }

  // member: uncertainty_beam2
  {
    out << "uncertainty_beam2: ";
    rosidl_generator_traits::value_to_yaml(msg.uncertainty_beam2, out);
    out << ", ";
  }

  // member: uncertainty_beam3
  {
    out << "uncertainty_beam3: ";
    rosidl_generator_traits::value_to_yaml(msg.uncertainty_beam3, out);
    out << ", ";
  }

  // member: pressure
  {
    out << "pressure: ";
    rosidl_generator_traits::value_to_yaml(msg.pressure, out);
    out << ", ";
  }

  // member: temperature
  {
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
    out << ", ";
  }

  // member: vel_valid
  {
    out << "vel_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_valid, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DVL & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: vel_body
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_body:\n";
    to_block_style_yaml(msg.vel_body, out, indentation + 2);
  }

  // member: uncertainty_vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "uncertainty_vel:\n";
    to_block_style_yaml(msg.uncertainty_vel, out, indentation + 2);
  }

  // member: vel_beam1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_beam1: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_beam1, out);
    out << "\n";
  }

  // member: vel_beam2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_beam2: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_beam2, out);
    out << "\n";
  }

  // member: vel_beam3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_beam3: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_beam3, out);
    out << "\n";
  }

  // member: uncertainty_beam1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "uncertainty_beam1: ";
    rosidl_generator_traits::value_to_yaml(msg.uncertainty_beam1, out);
    out << "\n";
  }

  // member: uncertainty_beam2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "uncertainty_beam2: ";
    rosidl_generator_traits::value_to_yaml(msg.uncertainty_beam2, out);
    out << "\n";
  }

  // member: uncertainty_beam3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "uncertainty_beam3: ";
    rosidl_generator_traits::value_to_yaml(msg.uncertainty_beam3, out);
    out << "\n";
  }

  // member: pressure
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pressure: ";
    rosidl_generator_traits::value_to_yaml(msg.pressure, out);
    out << "\n";
  }

  // member: temperature
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
    out << "\n";
  }

  // member: vel_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_valid, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DVL & msg, bool use_flow_style = false)
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
  const robot_interfaces::msg::DVL & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const robot_interfaces::msg::DVL & msg)
{
  return robot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<robot_interfaces::msg::DVL>()
{
  return "robot_interfaces::msg::DVL";
}

template<>
inline const char * name<robot_interfaces::msg::DVL>()
{
  return "robot_interfaces/msg/DVL";
}

template<>
struct has_fixed_size<robot_interfaces::msg::DVL>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Vector3>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<robot_interfaces::msg::DVL>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Vector3>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<robot_interfaces::msg::DVL>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_INTERFACES__MSG__DETAIL__DVL__TRAITS_HPP_
