// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from octomap_msgs:srv/GetOctomap.idl
// generated code does not contain a copyright notice

#ifndef OCTOMAP_MSGS__SRV__DETAIL__GET_OCTOMAP__TRAITS_HPP_
#define OCTOMAP_MSGS__SRV__DETAIL__GET_OCTOMAP__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "octomap_msgs/srv/detail/get_octomap__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace octomap_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetOctomap_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetOctomap_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetOctomap_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace octomap_msgs

namespace rosidl_generator_traits
{

[[deprecated("use octomap_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const octomap_msgs::srv::GetOctomap_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  octomap_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use octomap_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const octomap_msgs::srv::GetOctomap_Request & msg)
{
  return octomap_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<octomap_msgs::srv::GetOctomap_Request>()
{
  return "octomap_msgs::srv::GetOctomap_Request";
}

template<>
inline const char * name<octomap_msgs::srv::GetOctomap_Request>()
{
  return "octomap_msgs/srv/GetOctomap_Request";
}

template<>
struct has_fixed_size<octomap_msgs::srv::GetOctomap_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<octomap_msgs::srv::GetOctomap_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<octomap_msgs::srv::GetOctomap_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'map'
#include "octomap_msgs/msg/detail/octomap__traits.hpp"

namespace octomap_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetOctomap_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: map
  {
    out << "map: ";
    to_flow_style_yaml(msg.map, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetOctomap_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: map
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "map:\n";
    to_block_style_yaml(msg.map, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetOctomap_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace octomap_msgs

namespace rosidl_generator_traits
{

[[deprecated("use octomap_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const octomap_msgs::srv::GetOctomap_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  octomap_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use octomap_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const octomap_msgs::srv::GetOctomap_Response & msg)
{
  return octomap_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<octomap_msgs::srv::GetOctomap_Response>()
{
  return "octomap_msgs::srv::GetOctomap_Response";
}

template<>
inline const char * name<octomap_msgs::srv::GetOctomap_Response>()
{
  return "octomap_msgs/srv/GetOctomap_Response";
}

template<>
struct has_fixed_size<octomap_msgs::srv::GetOctomap_Response>
  : std::integral_constant<bool, has_fixed_size<octomap_msgs::msg::Octomap>::value> {};

template<>
struct has_bounded_size<octomap_msgs::srv::GetOctomap_Response>
  : std::integral_constant<bool, has_bounded_size<octomap_msgs::msg::Octomap>::value> {};

template<>
struct is_message<octomap_msgs::srv::GetOctomap_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<octomap_msgs::srv::GetOctomap>()
{
  return "octomap_msgs::srv::GetOctomap";
}

template<>
inline const char * name<octomap_msgs::srv::GetOctomap>()
{
  return "octomap_msgs/srv/GetOctomap";
}

template<>
struct has_fixed_size<octomap_msgs::srv::GetOctomap>
  : std::integral_constant<
    bool,
    has_fixed_size<octomap_msgs::srv::GetOctomap_Request>::value &&
    has_fixed_size<octomap_msgs::srv::GetOctomap_Response>::value
  >
{
};

template<>
struct has_bounded_size<octomap_msgs::srv::GetOctomap>
  : std::integral_constant<
    bool,
    has_bounded_size<octomap_msgs::srv::GetOctomap_Request>::value &&
    has_bounded_size<octomap_msgs::srv::GetOctomap_Response>::value
  >
{
};

template<>
struct is_service<octomap_msgs::srv::GetOctomap>
  : std::true_type
{
};

template<>
struct is_service_request<octomap_msgs::srv::GetOctomap_Request>
  : std::true_type
{
};

template<>
struct is_service_response<octomap_msgs::srv::GetOctomap_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // OCTOMAP_MSGS__SRV__DETAIL__GET_OCTOMAP__TRAITS_HPP_
