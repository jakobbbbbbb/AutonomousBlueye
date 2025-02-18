# generated from rosidl_generator_py/resource/_idl.py.em
# with input from robot_interfaces:msg/DVL.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DVL(type):
    """Metaclass of message 'DVL'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('robot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robot_interfaces.msg.DVL')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__dvl
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__dvl
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__dvl
            cls._TYPE_SUPPORT = module.type_support_msg__msg__dvl
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__dvl

            from geometry_msgs.msg import Vector3
            if Vector3.__class__._TYPE_SUPPORT is None:
                Vector3.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DVL(metaclass=Metaclass_DVL):
    """Message class 'DVL'."""

    __slots__ = [
        '_header',
        '_vel_body',
        '_uncertainty_vel',
        '_vel_beam1',
        '_vel_beam2',
        '_vel_beam3',
        '_uncertainty_beam1',
        '_uncertainty_beam2',
        '_uncertainty_beam3',
        '_pressure',
        '_temperature',
        '_vel_valid',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'vel_body': 'geometry_msgs/Vector3',
        'uncertainty_vel': 'geometry_msgs/Vector3',
        'vel_beam1': 'double',
        'vel_beam2': 'double',
        'vel_beam3': 'double',
        'uncertainty_beam1': 'double',
        'uncertainty_beam2': 'double',
        'uncertainty_beam3': 'double',
        'pressure': 'double',
        'temperature': 'double',
        'vel_valid': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        from geometry_msgs.msg import Vector3
        self.vel_body = kwargs.get('vel_body', Vector3())
        from geometry_msgs.msg import Vector3
        self.uncertainty_vel = kwargs.get('uncertainty_vel', Vector3())
        self.vel_beam1 = kwargs.get('vel_beam1', float())
        self.vel_beam2 = kwargs.get('vel_beam2', float())
        self.vel_beam3 = kwargs.get('vel_beam3', float())
        self.uncertainty_beam1 = kwargs.get('uncertainty_beam1', float())
        self.uncertainty_beam2 = kwargs.get('uncertainty_beam2', float())
        self.uncertainty_beam3 = kwargs.get('uncertainty_beam3', float())
        self.pressure = kwargs.get('pressure', float())
        self.temperature = kwargs.get('temperature', float())
        self.vel_valid = kwargs.get('vel_valid', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.vel_body != other.vel_body:
            return False
        if self.uncertainty_vel != other.uncertainty_vel:
            return False
        if self.vel_beam1 != other.vel_beam1:
            return False
        if self.vel_beam2 != other.vel_beam2:
            return False
        if self.vel_beam3 != other.vel_beam3:
            return False
        if self.uncertainty_beam1 != other.uncertainty_beam1:
            return False
        if self.uncertainty_beam2 != other.uncertainty_beam2:
            return False
        if self.uncertainty_beam3 != other.uncertainty_beam3:
            return False
        if self.pressure != other.pressure:
            return False
        if self.temperature != other.temperature:
            return False
        if self.vel_valid != other.vel_valid:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def vel_body(self):
        """Message field 'vel_body'."""
        return self._vel_body

    @vel_body.setter
    def vel_body(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'vel_body' field must be a sub message of type 'Vector3'"
        self._vel_body = value

    @builtins.property
    def uncertainty_vel(self):
        """Message field 'uncertainty_vel'."""
        return self._uncertainty_vel

    @uncertainty_vel.setter
    def uncertainty_vel(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'uncertainty_vel' field must be a sub message of type 'Vector3'"
        self._uncertainty_vel = value

    @builtins.property
    def vel_beam1(self):
        """Message field 'vel_beam1'."""
        return self._vel_beam1

    @vel_beam1.setter
    def vel_beam1(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vel_beam1' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'vel_beam1' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._vel_beam1 = value

    @builtins.property
    def vel_beam2(self):
        """Message field 'vel_beam2'."""
        return self._vel_beam2

    @vel_beam2.setter
    def vel_beam2(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vel_beam2' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'vel_beam2' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._vel_beam2 = value

    @builtins.property
    def vel_beam3(self):
        """Message field 'vel_beam3'."""
        return self._vel_beam3

    @vel_beam3.setter
    def vel_beam3(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vel_beam3' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'vel_beam3' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._vel_beam3 = value

    @builtins.property
    def uncertainty_beam1(self):
        """Message field 'uncertainty_beam1'."""
        return self._uncertainty_beam1

    @uncertainty_beam1.setter
    def uncertainty_beam1(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'uncertainty_beam1' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'uncertainty_beam1' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._uncertainty_beam1 = value

    @builtins.property
    def uncertainty_beam2(self):
        """Message field 'uncertainty_beam2'."""
        return self._uncertainty_beam2

    @uncertainty_beam2.setter
    def uncertainty_beam2(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'uncertainty_beam2' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'uncertainty_beam2' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._uncertainty_beam2 = value

    @builtins.property
    def uncertainty_beam3(self):
        """Message field 'uncertainty_beam3'."""
        return self._uncertainty_beam3

    @uncertainty_beam3.setter
    def uncertainty_beam3(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'uncertainty_beam3' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'uncertainty_beam3' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._uncertainty_beam3 = value

    @builtins.property
    def pressure(self):
        """Message field 'pressure'."""
        return self._pressure

    @pressure.setter
    def pressure(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pressure' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'pressure' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._pressure = value

    @builtins.property
    def temperature(self):
        """Message field 'temperature'."""
        return self._temperature

    @temperature.setter
    def temperature(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'temperature' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'temperature' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._temperature = value

    @builtins.property
    def vel_valid(self):
        """Message field 'vel_valid'."""
        return self._vel_valid

    @vel_valid.setter
    def vel_valid(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'vel_valid' field must be of type 'bool'"
        self._vel_valid = value
