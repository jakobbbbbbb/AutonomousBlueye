// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_interfaces:msg/YoloBox.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__YOLO_BOX__STRUCT_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__YOLO_BOX__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__msg__YoloBox __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__msg__YoloBox __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct YoloBox_
{
  using Type = YoloBox_<ContainerAllocator>;

  explicit YoloBox_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cls = "";
      this->confidence = 0.0;
      this->x_min = 0.0;
      this->y_min = 0.0;
      this->x_max = 0.0;
      this->y_max = 0.0;
    }
  }

  explicit YoloBox_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : cls(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cls = "";
      this->confidence = 0.0;
      this->x_min = 0.0;
      this->y_min = 0.0;
      this->x_max = 0.0;
      this->y_max = 0.0;
    }
  }

  // field types and members
  using _cls_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _cls_type cls;
  using _confidence_type =
    double;
  _confidence_type confidence;
  using _x_min_type =
    double;
  _x_min_type x_min;
  using _y_min_type =
    double;
  _y_min_type y_min;
  using _x_max_type =
    double;
  _x_max_type x_max;
  using _y_max_type =
    double;
  _y_max_type y_max;

  // setters for named parameter idiom
  Type & set__cls(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->cls = _arg;
    return *this;
  }
  Type & set__confidence(
    const double & _arg)
  {
    this->confidence = _arg;
    return *this;
  }
  Type & set__x_min(
    const double & _arg)
  {
    this->x_min = _arg;
    return *this;
  }
  Type & set__y_min(
    const double & _arg)
  {
    this->y_min = _arg;
    return *this;
  }
  Type & set__x_max(
    const double & _arg)
  {
    this->x_max = _arg;
    return *this;
  }
  Type & set__y_max(
    const double & _arg)
  {
    this->y_max = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::msg::YoloBox_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::msg::YoloBox_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::msg::YoloBox_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::msg::YoloBox_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::YoloBox_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::YoloBox_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::YoloBox_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::YoloBox_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::msg::YoloBox_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::msg::YoloBox_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__msg__YoloBox
    std::shared_ptr<robot_interfaces::msg::YoloBox_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__msg__YoloBox
    std::shared_ptr<robot_interfaces::msg::YoloBox_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const YoloBox_ & other) const
  {
    if (this->cls != other.cls) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    if (this->x_min != other.x_min) {
      return false;
    }
    if (this->y_min != other.y_min) {
      return false;
    }
    if (this->x_max != other.x_max) {
      return false;
    }
    if (this->y_max != other.y_max) {
      return false;
    }
    return true;
  }
  bool operator!=(const YoloBox_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct YoloBox_

// alias to use template instance with default allocator
using YoloBox =
  robot_interfaces::msg::YoloBox_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__YOLO_BOX__STRUCT_HPP_
