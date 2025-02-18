// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_interfaces:srv/AddWaypoint.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__ADD_WAYPOINT__STRUCT_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__ADD_WAYPOINT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__srv__AddWaypoint_Request __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__srv__AddWaypoint_Request __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct AddWaypoint_Request_
{
  using Type = AddWaypoint_Request_<ContainerAllocator>;

  explicit AddWaypoint_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
      this->position = 0ll;
    }
  }

  explicit AddWaypoint_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
      this->position = 0ll;
    }
  }

  // field types and members
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;
  using _z_type =
    float;
  _z_type z;
  using _position_type =
    int64_t;
  _position_type position;

  // setters for named parameter idiom
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const float & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__position(
    const int64_t & _arg)
  {
    this->position = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::srv::AddWaypoint_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::srv::AddWaypoint_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::srv::AddWaypoint_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::srv::AddWaypoint_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::AddWaypoint_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::AddWaypoint_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::AddWaypoint_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::AddWaypoint_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::srv::AddWaypoint_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::srv::AddWaypoint_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__srv__AddWaypoint_Request
    std::shared_ptr<robot_interfaces::srv::AddWaypoint_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__srv__AddWaypoint_Request
    std::shared_ptr<robot_interfaces::srv::AddWaypoint_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AddWaypoint_Request_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    return true;
  }
  bool operator!=(const AddWaypoint_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AddWaypoint_Request_

// alias to use template instance with default allocator
using AddWaypoint_Request =
  robot_interfaces::srv::AddWaypoint_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robot_interfaces


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__srv__AddWaypoint_Response __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__srv__AddWaypoint_Response __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct AddWaypoint_Response_
{
  using Type = AddWaypoint_Response_<ContainerAllocator>;

  explicit AddWaypoint_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit AddWaypoint_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    robot_interfaces::srv::AddWaypoint_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::srv::AddWaypoint_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::srv::AddWaypoint_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::srv::AddWaypoint_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::AddWaypoint_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::AddWaypoint_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::AddWaypoint_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::AddWaypoint_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::srv::AddWaypoint_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::srv::AddWaypoint_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__srv__AddWaypoint_Response
    std::shared_ptr<robot_interfaces::srv::AddWaypoint_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__srv__AddWaypoint_Response
    std::shared_ptr<robot_interfaces::srv::AddWaypoint_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AddWaypoint_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    return true;
  }
  bool operator!=(const AddWaypoint_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AddWaypoint_Response_

// alias to use template instance with default allocator
using AddWaypoint_Response =
  robot_interfaces::srv::AddWaypoint_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robot_interfaces

namespace robot_interfaces
{

namespace srv
{

struct AddWaypoint
{
  using Request = robot_interfaces::srv::AddWaypoint_Request;
  using Response = robot_interfaces::srv::AddWaypoint_Response;
};

}  // namespace srv

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__SRV__DETAIL__ADD_WAYPOINT__STRUCT_HPP_
