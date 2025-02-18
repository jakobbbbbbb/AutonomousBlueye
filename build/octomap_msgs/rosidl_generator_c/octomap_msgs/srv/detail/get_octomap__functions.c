// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from octomap_msgs:srv/GetOctomap.idl
// generated code does not contain a copyright notice
#include "octomap_msgs/srv/detail/get_octomap__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
octomap_msgs__srv__GetOctomap_Request__init(octomap_msgs__srv__GetOctomap_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
octomap_msgs__srv__GetOctomap_Request__fini(octomap_msgs__srv__GetOctomap_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
octomap_msgs__srv__GetOctomap_Request__are_equal(const octomap_msgs__srv__GetOctomap_Request * lhs, const octomap_msgs__srv__GetOctomap_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
octomap_msgs__srv__GetOctomap_Request__copy(
  const octomap_msgs__srv__GetOctomap_Request * input,
  octomap_msgs__srv__GetOctomap_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

octomap_msgs__srv__GetOctomap_Request *
octomap_msgs__srv__GetOctomap_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  octomap_msgs__srv__GetOctomap_Request * msg = (octomap_msgs__srv__GetOctomap_Request *)allocator.allocate(sizeof(octomap_msgs__srv__GetOctomap_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(octomap_msgs__srv__GetOctomap_Request));
  bool success = octomap_msgs__srv__GetOctomap_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
octomap_msgs__srv__GetOctomap_Request__destroy(octomap_msgs__srv__GetOctomap_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    octomap_msgs__srv__GetOctomap_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
octomap_msgs__srv__GetOctomap_Request__Sequence__init(octomap_msgs__srv__GetOctomap_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  octomap_msgs__srv__GetOctomap_Request * data = NULL;

  if (size) {
    data = (octomap_msgs__srv__GetOctomap_Request *)allocator.zero_allocate(size, sizeof(octomap_msgs__srv__GetOctomap_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = octomap_msgs__srv__GetOctomap_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        octomap_msgs__srv__GetOctomap_Request__fini(&data[i - 1]);
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
octomap_msgs__srv__GetOctomap_Request__Sequence__fini(octomap_msgs__srv__GetOctomap_Request__Sequence * array)
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
      octomap_msgs__srv__GetOctomap_Request__fini(&array->data[i]);
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

octomap_msgs__srv__GetOctomap_Request__Sequence *
octomap_msgs__srv__GetOctomap_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  octomap_msgs__srv__GetOctomap_Request__Sequence * array = (octomap_msgs__srv__GetOctomap_Request__Sequence *)allocator.allocate(sizeof(octomap_msgs__srv__GetOctomap_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = octomap_msgs__srv__GetOctomap_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
octomap_msgs__srv__GetOctomap_Request__Sequence__destroy(octomap_msgs__srv__GetOctomap_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    octomap_msgs__srv__GetOctomap_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
octomap_msgs__srv__GetOctomap_Request__Sequence__are_equal(const octomap_msgs__srv__GetOctomap_Request__Sequence * lhs, const octomap_msgs__srv__GetOctomap_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!octomap_msgs__srv__GetOctomap_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
octomap_msgs__srv__GetOctomap_Request__Sequence__copy(
  const octomap_msgs__srv__GetOctomap_Request__Sequence * input,
  octomap_msgs__srv__GetOctomap_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(octomap_msgs__srv__GetOctomap_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    octomap_msgs__srv__GetOctomap_Request * data =
      (octomap_msgs__srv__GetOctomap_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!octomap_msgs__srv__GetOctomap_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          octomap_msgs__srv__GetOctomap_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!octomap_msgs__srv__GetOctomap_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `map`
#include "octomap_msgs/msg/detail/octomap__functions.h"

bool
octomap_msgs__srv__GetOctomap_Response__init(octomap_msgs__srv__GetOctomap_Response * msg)
{
  if (!msg) {
    return false;
  }
  // map
  if (!octomap_msgs__msg__Octomap__init(&msg->map)) {
    octomap_msgs__srv__GetOctomap_Response__fini(msg);
    return false;
  }
  return true;
}

void
octomap_msgs__srv__GetOctomap_Response__fini(octomap_msgs__srv__GetOctomap_Response * msg)
{
  if (!msg) {
    return;
  }
  // map
  octomap_msgs__msg__Octomap__fini(&msg->map);
}

bool
octomap_msgs__srv__GetOctomap_Response__are_equal(const octomap_msgs__srv__GetOctomap_Response * lhs, const octomap_msgs__srv__GetOctomap_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // map
  if (!octomap_msgs__msg__Octomap__are_equal(
      &(lhs->map), &(rhs->map)))
  {
    return false;
  }
  return true;
}

bool
octomap_msgs__srv__GetOctomap_Response__copy(
  const octomap_msgs__srv__GetOctomap_Response * input,
  octomap_msgs__srv__GetOctomap_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // map
  if (!octomap_msgs__msg__Octomap__copy(
      &(input->map), &(output->map)))
  {
    return false;
  }
  return true;
}

octomap_msgs__srv__GetOctomap_Response *
octomap_msgs__srv__GetOctomap_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  octomap_msgs__srv__GetOctomap_Response * msg = (octomap_msgs__srv__GetOctomap_Response *)allocator.allocate(sizeof(octomap_msgs__srv__GetOctomap_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(octomap_msgs__srv__GetOctomap_Response));
  bool success = octomap_msgs__srv__GetOctomap_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
octomap_msgs__srv__GetOctomap_Response__destroy(octomap_msgs__srv__GetOctomap_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    octomap_msgs__srv__GetOctomap_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
octomap_msgs__srv__GetOctomap_Response__Sequence__init(octomap_msgs__srv__GetOctomap_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  octomap_msgs__srv__GetOctomap_Response * data = NULL;

  if (size) {
    data = (octomap_msgs__srv__GetOctomap_Response *)allocator.zero_allocate(size, sizeof(octomap_msgs__srv__GetOctomap_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = octomap_msgs__srv__GetOctomap_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        octomap_msgs__srv__GetOctomap_Response__fini(&data[i - 1]);
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
octomap_msgs__srv__GetOctomap_Response__Sequence__fini(octomap_msgs__srv__GetOctomap_Response__Sequence * array)
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
      octomap_msgs__srv__GetOctomap_Response__fini(&array->data[i]);
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

octomap_msgs__srv__GetOctomap_Response__Sequence *
octomap_msgs__srv__GetOctomap_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  octomap_msgs__srv__GetOctomap_Response__Sequence * array = (octomap_msgs__srv__GetOctomap_Response__Sequence *)allocator.allocate(sizeof(octomap_msgs__srv__GetOctomap_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = octomap_msgs__srv__GetOctomap_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
octomap_msgs__srv__GetOctomap_Response__Sequence__destroy(octomap_msgs__srv__GetOctomap_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    octomap_msgs__srv__GetOctomap_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
octomap_msgs__srv__GetOctomap_Response__Sequence__are_equal(const octomap_msgs__srv__GetOctomap_Response__Sequence * lhs, const octomap_msgs__srv__GetOctomap_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!octomap_msgs__srv__GetOctomap_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
octomap_msgs__srv__GetOctomap_Response__Sequence__copy(
  const octomap_msgs__srv__GetOctomap_Response__Sequence * input,
  octomap_msgs__srv__GetOctomap_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(octomap_msgs__srv__GetOctomap_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    octomap_msgs__srv__GetOctomap_Response * data =
      (octomap_msgs__srv__GetOctomap_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!octomap_msgs__srv__GetOctomap_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          octomap_msgs__srv__GetOctomap_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!octomap_msgs__srv__GetOctomap_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
