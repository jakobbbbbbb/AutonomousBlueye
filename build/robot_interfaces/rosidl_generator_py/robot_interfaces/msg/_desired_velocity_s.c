// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from robot_interfaces:msg/DesiredVelocity.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "robot_interfaces/msg/detail/desired_velocity__struct.h"
#include "robot_interfaces/msg/detail/desired_velocity__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool robot_interfaces__msg__desired_velocity__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[55];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("robot_interfaces.msg._desired_velocity.DesiredVelocity", full_classname_dest, 54) == 0);
  }
  robot_interfaces__msg__DesiredVelocity * ros_message = _ros_message;
  {  // surge
    PyObject * field = PyObject_GetAttrString(_pymsg, "surge");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->surge = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // sway
    PyObject * field = PyObject_GetAttrString(_pymsg, "sway");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->sway = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // heave
    PyObject * field = PyObject_GetAttrString(_pymsg, "heave");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->heave = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // yaw
    PyObject * field = PyObject_GetAttrString(_pymsg, "yaw");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->yaw = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * robot_interfaces__msg__desired_velocity__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of DesiredVelocity */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("robot_interfaces.msg._desired_velocity");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "DesiredVelocity");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  robot_interfaces__msg__DesiredVelocity * ros_message = (robot_interfaces__msg__DesiredVelocity *)raw_ros_message;
  {  // surge
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->surge);
    {
      int rc = PyObject_SetAttrString(_pymessage, "surge", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sway
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->sway);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sway", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // heave
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->heave);
    {
      int rc = PyObject_SetAttrString(_pymessage, "heave", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // yaw
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->yaw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "yaw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
