// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from octomap_msgs:msg/Octomap.idl
// generated code does not contain a copyright notice

#ifndef OCTOMAP_MSGS__MSG__DETAIL__OCTOMAP__TRAITS_HPP_
#define OCTOMAP_MSGS__MSG__DETAIL__OCTOMAP__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "octomap_msgs/msg/detail/octomap__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace octomap_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Octomap & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: binary
  {
    out << "binary: ";
    rosidl_generator_traits::value_to_yaml(msg.binary, out);
    out << ", ";
  }

  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: resolution
  {
    out << "resolution: ";
    rosidl_generator_traits::value_to_yaml(msg.resolution, out);
    out << ", ";
  }

  // member: data
  {
    if (msg.data.size() == 0) {
      out << "data: []";
    } else {
      out << "data: [";
      size_t pending_items = msg.data.size();
      for (auto item : msg.data) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Octomap & msg,
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

  // member: binary
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "binary: ";
    rosidl_generator_traits::value_to_yaml(msg.binary, out);
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

  // member: resolution
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "resolution: ";
    rosidl_generator_traits::value_to_yaml(msg.resolution, out);
    out << "\n";
  }

  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.data.size() == 0) {
      out << "data: []\n";
    } else {
      out << "data:\n";
      for (auto item : msg.data) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Octomap & msg, bool use_flow_style = false)
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
  const octomap_msgs::msg::Octomap & msg,
  std::ostream & out, size_t indentation = 0)
{
  octomap_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use octomap_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const octomap_msgs::msg::Octomap & msg)
{
  return octomap_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<octomap_msgs::msg::Octomap>()
{
  return "octomap_msgs::msg::Octomap";
}

template<>
inline const char * name<octomap_msgs::msg::Octomap>()
{
  return "octomap_msgs/msg/Octomap";
}

template<>
struct has_fixed_size<octomap_msgs::msg::Octomap>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<octomap_msgs::msg::Octomap>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<octomap_msgs::msg::Octomap>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OCTOMAP_MSGS__MSG__DETAIL__OCTOMAP__TRAITS_HPP_
