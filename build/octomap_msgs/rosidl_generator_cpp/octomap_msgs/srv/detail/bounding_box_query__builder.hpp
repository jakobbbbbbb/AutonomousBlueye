// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from octomap_msgs:srv/BoundingBoxQuery.idl
// generated code does not contain a copyright notice

#ifndef OCTOMAP_MSGS__SRV__DETAIL__BOUNDING_BOX_QUERY__BUILDER_HPP_
#define OCTOMAP_MSGS__SRV__DETAIL__BOUNDING_BOX_QUERY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "octomap_msgs/srv/detail/bounding_box_query__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace octomap_msgs
{

namespace srv
{

namespace builder
{

class Init_BoundingBoxQuery_Request_max
{
public:
  explicit Init_BoundingBoxQuery_Request_max(::octomap_msgs::srv::BoundingBoxQuery_Request & msg)
  : msg_(msg)
  {}
  ::octomap_msgs::srv::BoundingBoxQuery_Request max(::octomap_msgs::srv::BoundingBoxQuery_Request::_max_type arg)
  {
    msg_.max = std::move(arg);
    return std::move(msg_);
  }

private:
  ::octomap_msgs::srv::BoundingBoxQuery_Request msg_;
};

class Init_BoundingBoxQuery_Request_min
{
public:
  Init_BoundingBoxQuery_Request_min()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoundingBoxQuery_Request_max min(::octomap_msgs::srv::BoundingBoxQuery_Request::_min_type arg)
  {
    msg_.min = std::move(arg);
    return Init_BoundingBoxQuery_Request_max(msg_);
  }

private:
  ::octomap_msgs::srv::BoundingBoxQuery_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::octomap_msgs::srv::BoundingBoxQuery_Request>()
{
  return octomap_msgs::srv::builder::Init_BoundingBoxQuery_Request_min();
}

}  // namespace octomap_msgs


namespace octomap_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::octomap_msgs::srv::BoundingBoxQuery_Response>()
{
  return ::octomap_msgs::srv::BoundingBoxQuery_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace octomap_msgs

#endif  // OCTOMAP_MSGS__SRV__DETAIL__BOUNDING_BOX_QUERY__BUILDER_HPP_
