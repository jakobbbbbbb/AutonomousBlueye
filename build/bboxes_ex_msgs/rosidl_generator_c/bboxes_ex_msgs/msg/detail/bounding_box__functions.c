// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from bboxes_ex_msgs:msg/BoundingBox.idl
// generated code does not contain a copyright notice
#include "bboxes_ex_msgs/msg/detail/bounding_box__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `class_id`
#include "rosidl_runtime_c/string_functions.h"

bool
bboxes_ex_msgs__msg__BoundingBox__init(bboxes_ex_msgs__msg__BoundingBox * msg)
{
  if (!msg) {
    return false;
  }
  // probability
  // xmin
  // ymin
  // xmax
  // ymax
  // id
  // img_width
  // img_height
  // center_dist
  // class_id
  if (!rosidl_runtime_c__String__init(&msg->class_id)) {
    bboxes_ex_msgs__msg__BoundingBox__fini(msg);
    return false;
  }
  // class_id_int
  return true;
}

void
bboxes_ex_msgs__msg__BoundingBox__fini(bboxes_ex_msgs__msg__BoundingBox * msg)
{
  if (!msg) {
    return;
  }
  // probability
  // xmin
  // ymin
  // xmax
  // ymax
  // id
  // img_width
  // img_height
  // center_dist
  // class_id
  rosidl_runtime_c__String__fini(&msg->class_id);
  // class_id_int
}

bool
bboxes_ex_msgs__msg__BoundingBox__are_equal(const bboxes_ex_msgs__msg__BoundingBox * lhs, const bboxes_ex_msgs__msg__BoundingBox * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // probability
  if (lhs->probability != rhs->probability) {
    return false;
  }
  // xmin
  if (lhs->xmin != rhs->xmin) {
    return false;
  }
  // ymin
  if (lhs->ymin != rhs->ymin) {
    return false;
  }
  // xmax
  if (lhs->xmax != rhs->xmax) {
    return false;
  }
  // ymax
  if (lhs->ymax != rhs->ymax) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // img_width
  if (lhs->img_width != rhs->img_width) {
    return false;
  }
  // img_height
  if (lhs->img_height != rhs->img_height) {
    return false;
  }
  // center_dist
  if (lhs->center_dist != rhs->center_dist) {
    return false;
  }
  // class_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->class_id), &(rhs->class_id)))
  {
    return false;
  }
  // class_id_int
  if (lhs->class_id_int != rhs->class_id_int) {
    return false;
  }
  return true;
}

bool
bboxes_ex_msgs__msg__BoundingBox__copy(
  const bboxes_ex_msgs__msg__BoundingBox * input,
  bboxes_ex_msgs__msg__BoundingBox * output)
{
  if (!input || !output) {
    return false;
  }
  // probability
  output->probability = input->probability;
  // xmin
  output->xmin = input->xmin;
  // ymin
  output->ymin = input->ymin;
  // xmax
  output->xmax = input->xmax;
  // ymax
  output->ymax = input->ymax;
  // id
  output->id = input->id;
  // img_width
  output->img_width = input->img_width;
  // img_height
  output->img_height = input->img_height;
  // center_dist
  output->center_dist = input->center_dist;
  // class_id
  if (!rosidl_runtime_c__String__copy(
      &(input->class_id), &(output->class_id)))
  {
    return false;
  }
  // class_id_int
  output->class_id_int = input->class_id_int;
  return true;
}

bboxes_ex_msgs__msg__BoundingBox *
bboxes_ex_msgs__msg__BoundingBox__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bboxes_ex_msgs__msg__BoundingBox * msg = (bboxes_ex_msgs__msg__BoundingBox *)allocator.allocate(sizeof(bboxes_ex_msgs__msg__BoundingBox), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(bboxes_ex_msgs__msg__BoundingBox));
  bool success = bboxes_ex_msgs__msg__BoundingBox__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
bboxes_ex_msgs__msg__BoundingBox__destroy(bboxes_ex_msgs__msg__BoundingBox * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    bboxes_ex_msgs__msg__BoundingBox__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
bboxes_ex_msgs__msg__BoundingBox__Sequence__init(bboxes_ex_msgs__msg__BoundingBox__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bboxes_ex_msgs__msg__BoundingBox * data = NULL;

  if (size) {
    data = (bboxes_ex_msgs__msg__BoundingBox *)allocator.zero_allocate(size, sizeof(bboxes_ex_msgs__msg__BoundingBox), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = bboxes_ex_msgs__msg__BoundingBox__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        bboxes_ex_msgs__msg__BoundingBox__fini(&data[i - 1]);
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
bboxes_ex_msgs__msg__BoundingBox__Sequence__fini(bboxes_ex_msgs__msg__BoundingBox__Sequence * array)
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
      bboxes_ex_msgs__msg__BoundingBox__fini(&array->data[i]);
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

bboxes_ex_msgs__msg__BoundingBox__Sequence *
bboxes_ex_msgs__msg__BoundingBox__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bboxes_ex_msgs__msg__BoundingBox__Sequence * array = (bboxes_ex_msgs__msg__BoundingBox__Sequence *)allocator.allocate(sizeof(bboxes_ex_msgs__msg__BoundingBox__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = bboxes_ex_msgs__msg__BoundingBox__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
bboxes_ex_msgs__msg__BoundingBox__Sequence__destroy(bboxes_ex_msgs__msg__BoundingBox__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    bboxes_ex_msgs__msg__BoundingBox__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
bboxes_ex_msgs__msg__BoundingBox__Sequence__are_equal(const bboxes_ex_msgs__msg__BoundingBox__Sequence * lhs, const bboxes_ex_msgs__msg__BoundingBox__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!bboxes_ex_msgs__msg__BoundingBox__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
bboxes_ex_msgs__msg__BoundingBox__Sequence__copy(
  const bboxes_ex_msgs__msg__BoundingBox__Sequence * input,
  bboxes_ex_msgs__msg__BoundingBox__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(bboxes_ex_msgs__msg__BoundingBox);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    bboxes_ex_msgs__msg__BoundingBox * data =
      (bboxes_ex_msgs__msg__BoundingBox *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!bboxes_ex_msgs__msg__BoundingBox__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          bboxes_ex_msgs__msg__BoundingBox__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!bboxes_ex_msgs__msg__BoundingBox__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
