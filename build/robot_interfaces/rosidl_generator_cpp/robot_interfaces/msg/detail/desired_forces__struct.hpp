// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_interfaces:msg/DesiredForces.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__DESIRED_FORCES__STRUCT_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__DESIRED_FORCES__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__msg__DesiredForces __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__msg__DesiredForces __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DesiredForces_
{
  using Type = DesiredForces_<ContainerAllocator>;

  explicit DesiredForces_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->surge = 0.0f;
      this->sway = 0.0f;
      this->heave = 0.0f;
      this->roll = 0.0f;
      this->pitch = 0.0f;
      this->yaw = 0.0f;
    }
  }

  explicit DesiredForces_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->surge = 0.0f;
      this->sway = 0.0f;
      this->heave = 0.0f;
      this->roll = 0.0f;
      this->pitch = 0.0f;
      this->yaw = 0.0f;
    }
  }

  // field types and members
  using _surge_type =
    float;
  _surge_type surge;
  using _sway_type =
    float;
  _sway_type sway;
  using _heave_type =
    float;
  _heave_type heave;
  using _roll_type =
    float;
  _roll_type roll;
  using _pitch_type =
    float;
  _pitch_type pitch;
  using _yaw_type =
    float;
  _yaw_type yaw;

  // setters for named parameter idiom
  Type & set__surge(
    const float & _arg)
  {
    this->surge = _arg;
    return *this;
  }
  Type & set__sway(
    const float & _arg)
  {
    this->sway = _arg;
    return *this;
  }
  Type & set__heave(
    const float & _arg)
  {
    this->heave = _arg;
    return *this;
  }
  Type & set__roll(
    const float & _arg)
  {
    this->roll = _arg;
    return *this;
  }
  Type & set__pitch(
    const float & _arg)
  {
    this->pitch = _arg;
    return *this;
  }
  Type & set__yaw(
    const float & _arg)
  {
    this->yaw = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::msg::DesiredForces_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::msg::DesiredForces_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::msg::DesiredForces_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::msg::DesiredForces_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::DesiredForces_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::DesiredForces_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::DesiredForces_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::DesiredForces_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::msg::DesiredForces_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::msg::DesiredForces_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__msg__DesiredForces
    std::shared_ptr<robot_interfaces::msg::DesiredForces_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__msg__DesiredForces
    std::shared_ptr<robot_interfaces::msg::DesiredForces_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DesiredForces_ & other) const
  {
    if (this->surge != other.surge) {
      return false;
    }
    if (this->sway != other.sway) {
      return false;
    }
    if (this->heave != other.heave) {
      return false;
    }
    if (this->roll != other.roll) {
      return false;
    }
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    return true;
  }
  bool operator!=(const DesiredForces_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DesiredForces_

// alias to use template instance with default allocator
using DesiredForces =
  robot_interfaces::msg::DesiredForces_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__DESIRED_FORCES__STRUCT_HPP_
