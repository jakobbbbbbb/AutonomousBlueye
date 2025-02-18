// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_interfaces:msg/YoloThreshChainPose.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__YOLO_THRESH_CHAIN_POSE__STRUCT_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__YOLO_THRESH_CHAIN_POSE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__msg__YoloThreshChainPose __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__msg__YoloThreshChainPose __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct YoloThreshChainPose_
{
  using Type = YoloThreshChainPose_<ContainerAllocator>;

  explicit YoloThreshChainPose_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mid_x = 0.0;
      this->mid_y = 0.0;
      this->angle_degrees = 0.0;
    }
  }

  explicit YoloThreshChainPose_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mid_x = 0.0;
      this->mid_y = 0.0;
      this->angle_degrees = 0.0;
    }
  }

  // field types and members
  using _mid_x_type =
    double;
  _mid_x_type mid_x;
  using _mid_y_type =
    double;
  _mid_y_type mid_y;
  using _angle_degrees_type =
    double;
  _angle_degrees_type angle_degrees;

  // setters for named parameter idiom
  Type & set__mid_x(
    const double & _arg)
  {
    this->mid_x = _arg;
    return *this;
  }
  Type & set__mid_y(
    const double & _arg)
  {
    this->mid_y = _arg;
    return *this;
  }
  Type & set__angle_degrees(
    const double & _arg)
  {
    this->angle_degrees = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::msg::YoloThreshChainPose_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::msg::YoloThreshChainPose_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::msg::YoloThreshChainPose_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::msg::YoloThreshChainPose_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::YoloThreshChainPose_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::YoloThreshChainPose_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::YoloThreshChainPose_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::YoloThreshChainPose_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::msg::YoloThreshChainPose_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::msg::YoloThreshChainPose_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__msg__YoloThreshChainPose
    std::shared_ptr<robot_interfaces::msg::YoloThreshChainPose_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__msg__YoloThreshChainPose
    std::shared_ptr<robot_interfaces::msg::YoloThreshChainPose_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const YoloThreshChainPose_ & other) const
  {
    if (this->mid_x != other.mid_x) {
      return false;
    }
    if (this->mid_y != other.mid_y) {
      return false;
    }
    if (this->angle_degrees != other.angle_degrees) {
      return false;
    }
    return true;
  }
  bool operator!=(const YoloThreshChainPose_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct YoloThreshChainPose_

// alias to use template instance with default allocator
using YoloThreshChainPose =
  robot_interfaces::msg::YoloThreshChainPose_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__YOLO_THRESH_CHAIN_POSE__STRUCT_HPP_
