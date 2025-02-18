// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_interfaces:msg/YoloChainPose.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__YOLO_CHAIN_POSE__STRUCT_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__YOLO_CHAIN_POSE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__msg__YoloChainPose __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__msg__YoloChainPose __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct YoloChainPose_
{
  using Type = YoloChainPose_<ContainerAllocator>;

  explicit YoloChainPose_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit YoloChainPose_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _data_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__data(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::msg::YoloChainPose_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::msg::YoloChainPose_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::msg::YoloChainPose_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::msg::YoloChainPose_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::YoloChainPose_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::YoloChainPose_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::YoloChainPose_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::YoloChainPose_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::msg::YoloChainPose_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::msg::YoloChainPose_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__msg__YoloChainPose
    std::shared_ptr<robot_interfaces::msg::YoloChainPose_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__msg__YoloChainPose
    std::shared_ptr<robot_interfaces::msg::YoloChainPose_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const YoloChainPose_ & other) const
  {
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const YoloChainPose_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct YoloChainPose_

// alias to use template instance with default allocator
using YoloChainPose =
  robot_interfaces::msg::YoloChainPose_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__YOLO_CHAIN_POSE__STRUCT_HPP_
