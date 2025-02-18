// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_interfaces:srv/SetState.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__SET_STATE__STRUCT_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__SET_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__srv__SetState_Request __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__srv__SetState_Request __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetState_Request_
{
  using Type = SetState_Request_<ContainerAllocator>;

  explicit SetState_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = false;
    }
  }

  explicit SetState_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = false;
    }
  }

  // field types and members
  using _state_type =
    bool;
  _state_type state;

  // setters for named parameter idiom
  Type & set__state(
    const bool & _arg)
  {
    this->state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::srv::SetState_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::srv::SetState_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::srv::SetState_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::srv::SetState_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::SetState_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::SetState_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::SetState_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::SetState_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::srv::SetState_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::srv::SetState_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__srv__SetState_Request
    std::shared_ptr<robot_interfaces::srv::SetState_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__srv__SetState_Request
    std::shared_ptr<robot_interfaces::srv::SetState_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetState_Request_ & other) const
  {
    if (this->state != other.state) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetState_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetState_Request_

// alias to use template instance with default allocator
using SetState_Request =
  robot_interfaces::srv::SetState_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robot_interfaces


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__srv__SetState_Response __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__srv__SetState_Response __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetState_Response_
{
  using Type = SetState_Response_<ContainerAllocator>;

  explicit SetState_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit SetState_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    robot_interfaces::srv::SetState_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::srv::SetState_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::srv::SetState_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::srv::SetState_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::SetState_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::SetState_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::SetState_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::SetState_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::srv::SetState_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::srv::SetState_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__srv__SetState_Response
    std::shared_ptr<robot_interfaces::srv::SetState_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__srv__SetState_Response
    std::shared_ptr<robot_interfaces::srv::SetState_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetState_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetState_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetState_Response_

// alias to use template instance with default allocator
using SetState_Response =
  robot_interfaces::srv::SetState_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robot_interfaces

namespace robot_interfaces
{

namespace srv
{

struct SetState
{
  using Request = robot_interfaces::srv::SetState_Request;
  using Response = robot_interfaces::srv::SetState_Response;
};

}  // namespace srv

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__SRV__DETAIL__SET_STATE__STRUCT_HPP_
