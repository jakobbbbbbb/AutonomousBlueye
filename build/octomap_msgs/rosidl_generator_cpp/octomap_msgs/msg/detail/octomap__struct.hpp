// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from octomap_msgs:msg/Octomap.idl
// generated code does not contain a copyright notice

#ifndef OCTOMAP_MSGS__MSG__DETAIL__OCTOMAP__STRUCT_HPP_
#define OCTOMAP_MSGS__MSG__DETAIL__OCTOMAP__STRUCT_HPP_

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

#ifndef _WIN32
# define DEPRECATED__octomap_msgs__msg__Octomap __attribute__((deprecated))
#else
# define DEPRECATED__octomap_msgs__msg__Octomap __declspec(deprecated)
#endif

namespace octomap_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Octomap_
{
  using Type = Octomap_<ContainerAllocator>;

  explicit Octomap_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->binary = false;
      this->id = "";
      this->resolution = 0.0;
    }
  }

  explicit Octomap_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->binary = false;
      this->id = "";
      this->resolution = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _binary_type =
    bool;
  _binary_type binary;
  using _id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _id_type id;
  using _resolution_type =
    double;
  _resolution_type resolution;
  using _data_type =
    std::vector<int8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int8_t>>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__binary(
    const bool & _arg)
  {
    this->binary = _arg;
    return *this;
  }
  Type & set__id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__resolution(
    const double & _arg)
  {
    this->resolution = _arg;
    return *this;
  }
  Type & set__data(
    const std::vector<int8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int8_t>> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    octomap_msgs::msg::Octomap_<ContainerAllocator> *;
  using ConstRawPtr =
    const octomap_msgs::msg::Octomap_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<octomap_msgs::msg::Octomap_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<octomap_msgs::msg::Octomap_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      octomap_msgs::msg::Octomap_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<octomap_msgs::msg::Octomap_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      octomap_msgs::msg::Octomap_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<octomap_msgs::msg::Octomap_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<octomap_msgs::msg::Octomap_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<octomap_msgs::msg::Octomap_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__octomap_msgs__msg__Octomap
    std::shared_ptr<octomap_msgs::msg::Octomap_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__octomap_msgs__msg__Octomap
    std::shared_ptr<octomap_msgs::msg::Octomap_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Octomap_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->binary != other.binary) {
      return false;
    }
    if (this->id != other.id) {
      return false;
    }
    if (this->resolution != other.resolution) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const Octomap_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Octomap_

// alias to use template instance with default allocator
using Octomap =
  octomap_msgs::msg::Octomap_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace octomap_msgs

#endif  // OCTOMAP_MSGS__MSG__DETAIL__OCTOMAP__STRUCT_HPP_
