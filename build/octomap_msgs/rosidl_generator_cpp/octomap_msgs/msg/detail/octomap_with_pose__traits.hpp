// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from octomap_msgs:msg/OctomapWithPose.idl
// generated code does not contain a copyright notice

#ifndef OCTOMAP_MSGS__MSG__DETAIL__OCTOMAP_WITH_POSE__TRAITS_HPP_
#define OCTOMAP_MSGS__MSG__DETAIL__OCTOMAP_WITH_POSE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "octomap_msgs/msg/detail/octomap_with_pose__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'origin'
#include "geometry_msgs/msg/detail/pose__traits.hpp"
// Member 'octomap'
#include "octomap_msgs/msg/detail/octomap__traits.hpp"

namespace octomap_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const OctomapWithPose & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: origin
  {
    out << "origin: ";
    to_flow_style_yaml(msg.origin, out);
    out << ", ";
  }

  // member: octomap
  {
    out << "octomap: ";
    to_flow_style_yaml(msg.octomap, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OctomapWithPose & msg,
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

  // member: origin
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "origin:\n";
    to_block_style_yaml(msg.origin, out, indentation + 2);
  }

  // member: octomap
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "octomap:\n";
    to_block_style_yaml(msg.octomap, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OctomapWithPose & msg, bool use_flow_style = false)
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

}  // namespace octomap_msgs

namespace rosidl_generator_traits
{

[[deprecated("use octomap_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const octomap_msgs::msg::OctomapWithPose & msg,
  std::ostream & out, size_t indentation = 0)
{
  octomap_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use octomap_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const octomap_msgs::msg::OctomapWithPose & msg)
{
  return octomap_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<octomap_msgs::msg::OctomapWithPose>()
{
  return "octomap_msgs::msg::OctomapWithPose";
}

template<>
inline const char * name<octomap_msgs::msg::OctomapWithPose>()
{
  return "octomap_msgs/msg/OctomapWithPose";
}

template<>
struct has_fixed_size<octomap_msgs::msg::OctomapWithPose>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose>::value && has_fixed_size<octomap_msgs::msg::Octomap>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<octomap_msgs::msg::OctomapWithPose>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose>::value && has_bounded_size<octomap_msgs::msg::Octomap>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<octomap_msgs::msg::OctomapWithPose>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OCTOMAP_MSGS__MSG__DETAIL__OCTOMAP_WITH_POSE__TRAITS_HPP_
