// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robot_interfaces:msg/DVL.idl
// generated code does not contain a copyright notice
#include "robot_interfaces/msg/detail/dvl__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `vel_body`
// Member `uncertainty_vel`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
robot_interfaces__msg__DVL__init(robot_interfaces__msg__DVL * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    robot_interfaces__msg__DVL__fini(msg);
    return false;
  }
  // vel_body
  if (!geometry_msgs__msg__Vector3__init(&msg->vel_body)) {
    robot_interfaces__msg__DVL__fini(msg);
    return false;
  }
  // uncertainty_vel
  if (!geometry_msgs__msg__Vector3__init(&msg->uncertainty_vel)) {
    robot_interfaces__msg__DVL__fini(msg);
    return false;
  }
  // vel_beam1
  // vel_beam2
  // vel_beam3
  // uncertainty_beam1
  // uncertainty_beam2
  // uncertainty_beam3
  // pressure
  // temperature
  // vel_valid
  return true;
}

void
robot_interfaces__msg__DVL__fini(robot_interfaces__msg__DVL * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // vel_body
  geometry_msgs__msg__Vector3__fini(&msg->vel_body);
  // uncertainty_vel
  geometry_msgs__msg__Vector3__fini(&msg->uncertainty_vel);
  // vel_beam1
  // vel_beam2
  // vel_beam3
  // uncertainty_beam1
  // uncertainty_beam2
  // uncertainty_beam3
  // pressure
  // temperature
  // vel_valid
}

bool
robot_interfaces__msg__DVL__are_equal(const robot_interfaces__msg__DVL * lhs, const robot_interfaces__msg__DVL * rhs)
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
  // vel_body
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->vel_body), &(rhs->vel_body)))
  {
    return false;
  }
  // uncertainty_vel
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->uncertainty_vel), &(rhs->uncertainty_vel)))
  {
    return false;
  }
  // vel_beam1
  if (lhs->vel_beam1 != rhs->vel_beam1) {
    return false;
  }
  // vel_beam2
  if (lhs->vel_beam2 != rhs->vel_beam2) {
    return false;
  }
  // vel_beam3
  if (lhs->vel_beam3 != rhs->vel_beam3) {
    return false;
  }
  // uncertainty_beam1
  if (lhs->uncertainty_beam1 != rhs->uncertainty_beam1) {
    return false;
  }
  // uncertainty_beam2
  if (lhs->uncertainty_beam2 != rhs->uncertainty_beam2) {
    return false;
  }
  // uncertainty_beam3
  if (lhs->uncertainty_beam3 != rhs->uncertainty_beam3) {
    return false;
  }
  // pressure
  if (lhs->pressure != rhs->pressure) {
    return false;
  }
  // temperature
  if (lhs->temperature != rhs->temperature) {
    return false;
  }
  // vel_valid
  if (lhs->vel_valid != rhs->vel_valid) {
    return false;
  }
  return true;
}

bool
robot_interfaces__msg__DVL__copy(
  const robot_interfaces__msg__DVL * input,
  robot_interfaces__msg__DVL * output)
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
  // vel_body
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->vel_body), &(output->vel_body)))
  {
    return false;
  }
  // uncertainty_vel
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->uncertainty_vel), &(output->uncertainty_vel)))
  {
    return false;
  }
  // vel_beam1
  output->vel_beam1 = input->vel_beam1;
  // vel_beam2
  output->vel_beam2 = input->vel_beam2;
  // vel_beam3
  output->vel_beam3 = input->vel_beam3;
  // uncertainty_beam1
  output->uncertainty_beam1 = input->uncertainty_beam1;
  // uncertainty_beam2
  output->uncertainty_beam2 = input->uncertainty_beam2;
  // uncertainty_beam3
  output->uncertainty_beam3 = input->uncertainty_beam3;
  // pressure
  output->pressure = input->pressure;
  // temperature
  output->temperature = input->temperature;
  // vel_valid
  output->vel_valid = input->vel_valid;
  return true;
}

robot_interfaces__msg__DVL *
robot_interfaces__msg__DVL__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_interfaces__msg__DVL * msg = (robot_interfaces__msg__DVL *)allocator.allocate(sizeof(robot_interfaces__msg__DVL), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robot_interfaces__msg__DVL));
  bool success = robot_interfaces__msg__DVL__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robot_interfaces__msg__DVL__destroy(robot_interfaces__msg__DVL * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robot_interfaces__msg__DVL__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robot_interfaces__msg__DVL__Sequence__init(robot_interfaces__msg__DVL__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_interfaces__msg__DVL * data = NULL;

  if (size) {
    data = (robot_interfaces__msg__DVL *)allocator.zero_allocate(size, sizeof(robot_interfaces__msg__DVL), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robot_interfaces__msg__DVL__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robot_interfaces__msg__DVL__fini(&data[i - 1]);
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
robot_interfaces__msg__DVL__Sequence__fini(robot_interfaces__msg__DVL__Sequence * array)
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
      robot_interfaces__msg__DVL__fini(&array->data[i]);
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

robot_interfaces__msg__DVL__Sequence *
robot_interfaces__msg__DVL__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_interfaces__msg__DVL__Sequence * array = (robot_interfaces__msg__DVL__Sequence *)allocator.allocate(sizeof(robot_interfaces__msg__DVL__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robot_interfaces__msg__DVL__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robot_interfaces__msg__DVL__Sequence__destroy(robot_interfaces__msg__DVL__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robot_interfaces__msg__DVL__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robot_interfaces__msg__DVL__Sequence__are_equal(const robot_interfaces__msg__DVL__Sequence * lhs, const robot_interfaces__msg__DVL__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robot_interfaces__msg__DVL__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robot_interfaces__msg__DVL__Sequence__copy(
  const robot_interfaces__msg__DVL__Sequence * input,
  robot_interfaces__msg__DVL__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robot_interfaces__msg__DVL);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robot_interfaces__msg__DVL * data =
      (robot_interfaces__msg__DVL *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robot_interfaces__msg__DVL__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robot_interfaces__msg__DVL__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robot_interfaces__msg__DVL__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
