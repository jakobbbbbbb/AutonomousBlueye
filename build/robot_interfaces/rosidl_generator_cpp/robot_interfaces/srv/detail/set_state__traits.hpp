// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_interfaces:srv/SetState.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__SET_STATE__TRAITS_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__SET_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_interfaces/srv/detail/set_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robot_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetState_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: state
  {
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetState_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetState_Request & msg, bool use_flow_style = false)
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

}  // namespace robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robot_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_interfaces::srv::SetState_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_interfaces::srv::SetState_Request & msg)
{
  return robot_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_interfaces::srv::SetState_Request>()
{
  return "robot_interfaces::srv::SetState_Request";
}

template<>
inline const char * name<robot_interfaces::srv::SetState_Request>()
{
  return "robot_interfaces/srv/SetState_Request";
}

template<>
struct has_fixed_size<robot_interfaces::srv::SetState_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robot_interfaces::srv::SetState_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robot_interfaces::srv::SetState_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace robot_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetState_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetState_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetState_Response & msg, bool use_flow_style = false)
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

}  // namespace robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robot_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_interfaces::srv::SetState_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_interfaces::srv::SetState_Response & msg)
{
  return robot_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_interfaces::srv::SetState_Response>()
{
  return "robot_interfaces::srv::SetState_Response";
}

template<>
inline const char * name<robot_interfaces::srv::SetState_Response>()
{
  return "robot_interfaces/srv/SetState_Response";
}

template<>
struct has_fixed_size<robot_interfaces::srv::SetState_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robot_interfaces::srv::SetState_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robot_interfaces::srv::SetState_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<robot_interfaces::srv::SetState>()
{
  return "robot_interfaces::srv::SetState";
}

template<>
inline const char * name<robot_interfaces::srv::SetState>()
{
  return "robot_interfaces/srv/SetState";
}

template<>
struct has_fixed_size<robot_interfaces::srv::SetState>
  : std::integral_constant<
    bool,
    has_fixed_size<robot_interfaces::srv::SetState_Request>::value &&
    has_fixed_size<robot_interfaces::srv::SetState_Response>::value
  >
{
};

template<>
struct has_bounded_size<robot_interfaces::srv::SetState>
  : std::integral_constant<
    bool,
    has_bounded_size<robot_interfaces::srv::SetState_Request>::value &&
    has_bounded_size<robot_interfaces::srv::SetState_Response>::value
  >
{
};

template<>
struct is_service<robot_interfaces::srv::SetState>
  : std::true_type
{
};

template<>
struct is_service_request<robot_interfaces::srv::SetState_Request>
  : std::true_type
{
};

template<>
struct is_service_response<robot_interfaces::srv::SetState_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_INTERFACES__SRV__DETAIL__SET_STATE__TRAITS_HPP_
