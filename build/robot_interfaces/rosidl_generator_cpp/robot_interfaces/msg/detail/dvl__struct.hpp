// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_interfaces:msg/DVL.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__DVL__STRUCT_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__DVL__STRUCT_HPP_

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
// Member 'vel_body'
// Member 'uncertainty_vel'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robot_interfaces__msg__DVL __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__msg__DVL __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DVL_
{
  using Type = DVL_<ContainerAllocator>;

  explicit DVL_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    vel_body(_init),
    uncertainty_vel(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->vel_beam1 = 0.0;
      this->vel_beam2 = 0.0;
      this->vel_beam3 = 0.0;
      this->uncertainty_beam1 = 0.0;
      this->uncertainty_beam2 = 0.0;
      this->uncertainty_beam3 = 0.0;
      this->pressure = 0.0;
      this->temperature = 0.0;
      this->vel_valid = false;
    }
  }

  explicit DVL_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    vel_body(_alloc, _init),
    uncertainty_vel(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->vel_beam1 = 0.0;
      this->vel_beam2 = 0.0;
      this->vel_beam3 = 0.0;
      this->uncertainty_beam1 = 0.0;
      this->uncertainty_beam2 = 0.0;
      this->uncertainty_beam3 = 0.0;
      this->pressure = 0.0;
      this->temperature = 0.0;
      this->vel_valid = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _vel_body_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _vel_body_type vel_body;
  using _uncertainty_vel_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _uncertainty_vel_type uncertainty_vel;
  using _vel_beam1_type =
    double;
  _vel_beam1_type vel_beam1;
  using _vel_beam2_type =
    double;
  _vel_beam2_type vel_beam2;
  using _vel_beam3_type =
    double;
  _vel_beam3_type vel_beam3;
  using _uncertainty_beam1_type =
    double;
  _uncertainty_beam1_type uncertainty_beam1;
  using _uncertainty_beam2_type =
    double;
  _uncertainty_beam2_type uncertainty_beam2;
  using _uncertainty_beam3_type =
    double;
  _uncertainty_beam3_type uncertainty_beam3;
  using _pressure_type =
    double;
  _pressure_type pressure;
  using _temperature_type =
    double;
  _temperature_type temperature;
  using _vel_valid_type =
    bool;
  _vel_valid_type vel_valid;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__vel_body(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->vel_body = _arg;
    return *this;
  }
  Type & set__uncertainty_vel(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->uncertainty_vel = _arg;
    return *this;
  }
  Type & set__vel_beam1(
    const double & _arg)
  {
    this->vel_beam1 = _arg;
    return *this;
  }
  Type & set__vel_beam2(
    const double & _arg)
  {
    this->vel_beam2 = _arg;
    return *this;
  }
  Type & set__vel_beam3(
    const double & _arg)
  {
    this->vel_beam3 = _arg;
    return *this;
  }
  Type & set__uncertainty_beam1(
    const double & _arg)
  {
    this->uncertainty_beam1 = _arg;
    return *this;
  }
  Type & set__uncertainty_beam2(
    const double & _arg)
  {
    this->uncertainty_beam2 = _arg;
    return *this;
  }
  Type & set__uncertainty_beam3(
    const double & _arg)
  {
    this->uncertainty_beam3 = _arg;
    return *this;
  }
  Type & set__pressure(
    const double & _arg)
  {
    this->pressure = _arg;
    return *this;
  }
  Type & set__temperature(
    const double & _arg)
  {
    this->temperature = _arg;
    return *this;
  }
  Type & set__vel_valid(
    const bool & _arg)
  {
    this->vel_valid = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::msg::DVL_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::msg::DVL_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::msg::DVL_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::msg::DVL_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::DVL_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::DVL_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::DVL_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::DVL_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::msg::DVL_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::msg::DVL_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__msg__DVL
    std::shared_ptr<robot_interfaces::msg::DVL_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__msg__DVL
    std::shared_ptr<robot_interfaces::msg::DVL_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DVL_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->vel_body != other.vel_body) {
      return false;
    }
    if (this->uncertainty_vel != other.uncertainty_vel) {
      return false;
    }
    if (this->vel_beam1 != other.vel_beam1) {
      return false;
    }
    if (this->vel_beam2 != other.vel_beam2) {
      return false;
    }
    if (this->vel_beam3 != other.vel_beam3) {
      return false;
    }
    if (this->uncertainty_beam1 != other.uncertainty_beam1) {
      return false;
    }
    if (this->uncertainty_beam2 != other.uncertainty_beam2) {
      return false;
    }
    if (this->uncertainty_beam3 != other.uncertainty_beam3) {
      return false;
    }
    if (this->pressure != other.pressure) {
      return false;
    }
    if (this->temperature != other.temperature) {
      return false;
    }
    if (this->vel_valid != other.vel_valid) {
      return false;
    }
    return true;
  }
  bool operator!=(const DVL_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DVL_

// alias to use template instance with default allocator
using DVL =
  robot_interfaces::msg::DVL_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__DVL__STRUCT_HPP_
