// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from bboxes_ex_msgs:msg/BoundingBox.idl
// generated code does not contain a copyright notice

#ifndef BBOXES_EX_MSGS__MSG__DETAIL__BOUNDING_BOX__STRUCT_HPP_
#define BBOXES_EX_MSGS__MSG__DETAIL__BOUNDING_BOX__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__bboxes_ex_msgs__msg__BoundingBox __attribute__((deprecated))
#else
# define DEPRECATED__bboxes_ex_msgs__msg__BoundingBox __declspec(deprecated)
#endif

namespace bboxes_ex_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BoundingBox_
{
  using Type = BoundingBox_<ContainerAllocator>;

  explicit BoundingBox_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->probability = 0.0f;
      this->xmin = 0;
      this->ymin = 0;
      this->xmax = 0;
      this->ymax = 0;
      this->id = 0;
      this->img_width = 0;
      this->img_height = 0;
      this->center_dist = 0l;
      this->class_id = "";
      this->class_id_int = 0;
    }
  }

  explicit BoundingBox_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : class_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->probability = 0.0f;
      this->xmin = 0;
      this->ymin = 0;
      this->xmax = 0;
      this->ymax = 0;
      this->id = 0;
      this->img_width = 0;
      this->img_height = 0;
      this->center_dist = 0l;
      this->class_id = "";
      this->class_id_int = 0;
    }
  }

  // field types and members
  using _probability_type =
    float;
  _probability_type probability;
  using _xmin_type =
    uint16_t;
  _xmin_type xmin;
  using _ymin_type =
    uint16_t;
  _ymin_type ymin;
  using _xmax_type =
    uint16_t;
  _xmax_type xmax;
  using _ymax_type =
    uint16_t;
  _ymax_type ymax;
  using _id_type =
    uint16_t;
  _id_type id;
  using _img_width_type =
    uint16_t;
  _img_width_type img_width;
  using _img_height_type =
    uint16_t;
  _img_height_type img_height;
  using _center_dist_type =
    int32_t;
  _center_dist_type center_dist;
  using _class_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _class_id_type class_id;
  using _class_id_int_type =
    uint16_t;
  _class_id_int_type class_id_int;

  // setters for named parameter idiom
  Type & set__probability(
    const float & _arg)
  {
    this->probability = _arg;
    return *this;
  }
  Type & set__xmin(
    const uint16_t & _arg)
  {
    this->xmin = _arg;
    return *this;
  }
  Type & set__ymin(
    const uint16_t & _arg)
  {
    this->ymin = _arg;
    return *this;
  }
  Type & set__xmax(
    const uint16_t & _arg)
  {
    this->xmax = _arg;
    return *this;
  }
  Type & set__ymax(
    const uint16_t & _arg)
  {
    this->ymax = _arg;
    return *this;
  }
  Type & set__id(
    const uint16_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__img_width(
    const uint16_t & _arg)
  {
    this->img_width = _arg;
    return *this;
  }
  Type & set__img_height(
    const uint16_t & _arg)
  {
    this->img_height = _arg;
    return *this;
  }
  Type & set__center_dist(
    const int32_t & _arg)
  {
    this->center_dist = _arg;
    return *this;
  }
  Type & set__class_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->class_id = _arg;
    return *this;
  }
  Type & set__class_id_int(
    const uint16_t & _arg)
  {
    this->class_id_int = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    bboxes_ex_msgs::msg::BoundingBox_<ContainerAllocator> *;
  using ConstRawPtr =
    const bboxes_ex_msgs::msg::BoundingBox_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<bboxes_ex_msgs::msg::BoundingBox_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<bboxes_ex_msgs::msg::BoundingBox_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      bboxes_ex_msgs::msg::BoundingBox_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<bboxes_ex_msgs::msg::BoundingBox_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      bboxes_ex_msgs::msg::BoundingBox_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<bboxes_ex_msgs::msg::BoundingBox_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<bboxes_ex_msgs::msg::BoundingBox_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<bboxes_ex_msgs::msg::BoundingBox_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__bboxes_ex_msgs__msg__BoundingBox
    std::shared_ptr<bboxes_ex_msgs::msg::BoundingBox_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__bboxes_ex_msgs__msg__BoundingBox
    std::shared_ptr<bboxes_ex_msgs::msg::BoundingBox_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BoundingBox_ & other) const
  {
    if (this->probability != other.probability) {
      return false;
    }
    if (this->xmin != other.xmin) {
      return false;
    }
    if (this->ymin != other.ymin) {
      return false;
    }
    if (this->xmax != other.xmax) {
      return false;
    }
    if (this->ymax != other.ymax) {
      return false;
    }
    if (this->id != other.id) {
      return false;
    }
    if (this->img_width != other.img_width) {
      return false;
    }
    if (this->img_height != other.img_height) {
      return false;
    }
    if (this->center_dist != other.center_dist) {
      return false;
    }
    if (this->class_id != other.class_id) {
      return false;
    }
    if (this->class_id_int != other.class_id_int) {
      return false;
    }
    return true;
  }
  bool operator!=(const BoundingBox_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BoundingBox_

// alias to use template instance with default allocator
using BoundingBox =
  bboxes_ex_msgs::msg::BoundingBox_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace bboxes_ex_msgs

#endif  // BBOXES_EX_MSGS__MSG__DETAIL__BOUNDING_BOX__STRUCT_HPP_
