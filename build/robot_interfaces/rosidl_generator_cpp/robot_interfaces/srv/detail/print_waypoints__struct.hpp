// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_interfaces:srv/PrintWaypoints.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__PRINT_WAYPOINTS__STRUCT_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__PRINT_WAYPOINTS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__srv__PrintWaypoints_Request __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__srv__PrintWaypoints_Request __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PrintWaypoints_Request_
{
  using Type = PrintWaypoints_Request_<ContainerAllocator>;

  explicit PrintWaypoints_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->print = false;
    }
  }

  explicit PrintWaypoints_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->print = false;
    }
  }

  // field types and members
  using _print_type =
    bool;
  _print_type print;

  // setters for named parameter idiom
  Type & set__print(
    const bool & _arg)
  {
    this->print = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::srv::PrintWaypoints_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::srv::PrintWaypoints_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::srv::PrintWaypoints_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::srv::PrintWaypoints_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::PrintWaypoints_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::PrintWaypoints_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::PrintWaypoints_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::PrintWaypoints_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::srv::PrintWaypoints_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::srv::PrintWaypoints_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__srv__PrintWaypoints_Request
    std::shared_ptr<robot_interfaces::srv::PrintWaypoints_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__srv__PrintWaypoints_Request
    std::shared_ptr<robot_interfaces::srv::PrintWaypoints_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PrintWaypoints_Request_ & other) const
  {
    if (this->print != other.print) {
      return false;
    }
    return true;
  }
  bool operator!=(const PrintWaypoints_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PrintWaypoints_Request_

// alias to use template instance with default allocator
using PrintWaypoints_Request =
  robot_interfaces::srv::PrintWaypoints_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robot_interfaces


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__srv__PrintWaypoints_Response __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__srv__PrintWaypoints_Response __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PrintWaypoints_Response_
{
  using Type = PrintWaypoints_Response_<ContainerAllocator>;

  explicit PrintWaypoints_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit PrintWaypoints_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::srv::PrintWaypoints_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::srv::PrintWaypoints_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::srv::PrintWaypoints_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::srv::PrintWaypoints_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::PrintWaypoints_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::PrintWaypoints_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::PrintWaypoints_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::PrintWaypoints_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::srv::PrintWaypoints_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::srv::PrintWaypoints_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__srv__PrintWaypoints_Response
    std::shared_ptr<robot_interfaces::srv::PrintWaypoints_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__srv__PrintWaypoints_Response
    std::shared_ptr<robot_interfaces::srv::PrintWaypoints_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PrintWaypoints_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    return true;
  }
  bool operator!=(const PrintWaypoints_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PrintWaypoints_Response_

// alias to use template instance with default allocator
using PrintWaypoints_Response =
  robot_interfaces::srv::PrintWaypoints_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robot_interfaces

namespace robot_interfaces
{

namespace srv
{

struct PrintWaypoints
{
  using Request = robot_interfaces::srv::PrintWaypoints_Request;
  using Response = robot_interfaces::srv::PrintWaypoints_Response;
};

}  // namespace srv

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__SRV__DETAIL__PRINT_WAYPOINTS__STRUCT_HPP_
