// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from octomap_msgs:msg/OctomapWithPose.idl
// generated code does not contain a copyright notice
#include "octomap_msgs/msg/detail/octomap_with_pose__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `origin`
#include "geometry_msgs/msg/detail/pose__functions.h"
// Member `octomap`
#include "octomap_msgs/msg/detail/octomap__functions.h"

bool
octomap_msgs__msg__OctomapWithPose__init(octomap_msgs__msg__OctomapWithPose * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    octomap_msgs__msg__OctomapWithPose__fini(msg);
    return false;
  }
  // origin
  if (!geometry_msgs__msg__Pose__init(&msg->origin)) {
    octomap_msgs__msg__OctomapWithPose__fini(msg);
    return false;
  }
  // octomap
  if (!octomap_msgs__msg__Octomap__init(&msg->octomap)) {
    octomap_msgs__msg__OctomapWithPose__fini(msg);
    return false;
  }
  return true;
}

void
octomap_msgs__msg__OctomapWithPose__fini(octomap_msgs__msg__OctomapWithPose * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // origin
  geometry_msgs__msg__Pose__fini(&msg->origin);
  // octomap
  octomap_msgs__msg__Octomap__fini(&msg->octomap);
}

bool
octomap_msgs__msg__OctomapWithPose__are_equal(const octomap_msgs__msg__OctomapWithPose * lhs, const octomap_msgs__msg__OctomapWithPose * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // origin
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->origin), &(rhs->origin)))
  {
    return false;
  }
  // octomap
  if (!octomap_msgs__msg__Octomap__are_equal(
      &(lhs->octomap), &(rhs->octomap)))
  {
    return false;
  }
  return true;
}

bool
octomap_msgs__msg__OctomapWithPose__copy(
  const octomap_msgs__msg__OctomapWithPose * input,
  octomap_msgs__msg__OctomapWithPose * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // origin
  if (!geometry_msgs__msg__Pose__copy(
      &(input->origin), &(output->origin)))
  {
    return false;
  }
  // octomap
  if (!octomap_msgs__msg__Octomap__copy(
      &(input->octomap), &(output->octomap)))
  {
    return false;
  }
  return true;
}

octomap_msgs__msg__OctomapWithPose *
octomap_msgs__msg__OctomapWithPose__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  octomap_msgs__msg__OctomapWithPose * msg = (octomap_msgs__msg__OctomapWithPose *)allocator.allocate(sizeof(octomap_msgs__msg__OctomapWithPose), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(octomap_msgs__msg__OctomapWithPose));
  bool success = octomap_msgs__msg__OctomapWithPose__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
octomap_msgs__msg__OctomapWithPose__destroy(octomap_msgs__msg__OctomapWithPose * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    octomap_msgs__msg__OctomapWithPose__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
octomap_msgs__msg__OctomapWithPose__Sequence__init(octomap_msgs__msg__OctomapWithPose__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  octomap_msgs__msg__OctomapWithPose * data = NULL;

  if (size) {
    data = (octomap_msgs__msg__OctomapWithPose *)allocator.zero_allocate(size, sizeof(octomap_msgs__msg__OctomapWithPose), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = octomap_msgs__msg__OctomapWithPose__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        octomap_msgs__msg__OctomapWithPose__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
octomap_msgs__msg__OctomapWithPose__Sequence__fini(octomap_msgs__msg__OctomapWithPose__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      octomap_msgs__msg__OctomapWithPose__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

octomap_msgs__msg__OctomapWithPose__Sequence *
octomap_msgs__msg__OctomapWithPose__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  octomap_msgs__msg__OctomapWithPose__Sequence * array = (octomap_msgs__msg__OctomapWithPose__Sequence *)allocator.allocate(sizeof(octomap_msgs__msg__OctomapWithPose__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = octomap_msgs__msg__OctomapWithPose__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
octomap_msgs__msg__OctomapWithPose__Sequence__destroy(octomap_msgs__msg__OctomapWithPose__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    octomap_msgs__msg__OctomapWithPose__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
octomap_msgs__msg__OctomapWithPose__Sequence__are_equal(const octomap_msgs__msg__OctomapWithPose__Sequence * lhs, const octomap_msgs__msg__OctomapWithPose__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!octomap_msgs__msg__OctomapWithPose__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
octomap_msgs__msg__OctomapWithPose__Sequence__copy(
  const octomap_msgs__msg__OctomapWithPose__Sequence * input,
  octomap_msgs__msg__OctomapWithPose__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(octomap_msgs__msg__OctomapWithPose);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    octomap_msgs__msg__OctomapWithPose * data =
      (octomap_msgs__msg__OctomapWithPose *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!octomap_msgs__msg__OctomapWithPose__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          octomap_msgs__msg__OctomapWithPose__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!octomap_msgs__msg__OctomapWithPose__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
