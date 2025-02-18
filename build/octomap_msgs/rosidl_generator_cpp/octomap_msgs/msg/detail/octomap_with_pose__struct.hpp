// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from octomap_msgs:msg/OctomapWithPose.idl
// generated code does not contain a copyright notice

#ifndef OCTOMAP_MSGS__MSG__DETAIL__OCTOMAP_WITH_POSE__STRUCT_HPP_
#define OCTOMAP_MSGS__MSG__DETAIL__OCTOMAP_WITH_POSE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'origin'
#include "geometry_msgs/msg/detail/pose__struct.hpp"
// Member 'octomap'
#include "octomap_msgs/msg/detail/octomap__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__octomap_msgs__msg__OctomapWithPose __attribute__((deprecated))
#else
# define DEPRECATED__octomap_msgs__msg__OctomapWithPose __declspec(deprecated)
#endif

namespace octomap_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct OctomapWithPose_
{
  using Type = OctomapWithPose_<ContainerAllocator>;

  explicit OctomapWithPose_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    origin(_init),
    octomap(_init)
  {
    (void)_init;
  }

  explicit OctomapWithPose_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    origin(_alloc, _init),
    octomap(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _origin_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _origin_type origin;
  using _octomap_type =
    octomap_msgs::msg::Octomap_<ContainerAllocator>;
  _octomap_type octomap;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__origin(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->origin = _arg;
    return *this;
  }
  Type & set__octomap(
    const octomap_msgs::msg::Octomap_<ContainerAllocator> & _arg)
  {
    this->octomap = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    octomap_msgs::msg::OctomapWithPose_<ContainerAllocator> *;
  using ConstRawPtr =
    const octomap_msgs::msg::OctomapWithPose_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<octomap_msgs::msg::OctomapWithPose_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<octomap_msgs::msg::OctomapWithPose_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      octomap_msgs::msg::OctomapWithPose_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<octomap_msgs::msg::OctomapWithPose_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      octomap_msgs::msg::OctomapWithPose_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<octomap_msgs::msg::OctomapWithPose_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<octomap_msgs::msg::OctomapWithPose_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<octomap_msgs::msg::OctomapWithPose_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__octomap_msgs__msg__OctomapWithPose
    std::shared_ptr<octomap_msgs::msg::OctomapWithPose_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__octomap_msgs__msg__OctomapWithPose
    std::shared_ptr<octomap_msgs::msg::OctomapWithPose_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const OctomapWithPose_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->origin != other.origin) {
      return false;
    }
    if (this->octomap != other.octomap) {
      return false;
    }
    return true;
  }
  bool operator!=(const OctomapWithPose_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct OctomapWithPose_

// alias to use template instance with default allocator
using OctomapWithPose =
  octomap_msgs::msg::OctomapWithPose_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace octomap_msgs

#endif  // OCTOMAP_MSGS__MSG__DETAIL__OCTOMAP_WITH_POSE__STRUCT_HPP_
