# generated from rosidl_generator_py/resource/_idl.py.em
# with input from bboxes_ex_msgs:msg/BoundingBox.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_BoundingBox(type):
    """Metaclass of message 'BoundingBox'."""

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
            module = import_type_support('bboxes_ex_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'bboxes_ex_msgs.msg.BoundingBox')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__bounding_box
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__bounding_box
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__bounding_box
            cls._TYPE_SUPPORT = module.type_support_msg__msg__bounding_box
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__bounding_box

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class BoundingBox(metaclass=Metaclass_BoundingBox):
    """Message class 'BoundingBox'."""

    __slots__ = [
        '_probability',
        '_xmin',
        '_ymin',
        '_xmax',
        '_ymax',
        '_id',
        '_img_width',
        '_img_height',
        '_center_dist',
        '_class_id',
        '_class_id_int',
    ]

    _fields_and_field_types = {
        'probability': 'float',
        'xmin': 'uint16',
        'ymin': 'uint16',
        'xmax': 'uint16',
        'ymax': 'uint16',
        'id': 'uint16',
        'img_width': 'uint16',
        'img_height': 'uint16',
        'center_dist': 'int32',
        'class_id': 'string',
        'class_id_int': 'uint16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.probability = kwargs.get('probability', float())
        self.xmin = kwargs.get('xmin', int())
        self.ymin = kwargs.get('ymin', int())
        self.xmax = kwargs.get('xmax', int())
        self.ymax = kwargs.get('ymax', int())
        self.id = kwargs.get('id', int())
        self.img_width = kwargs.get('img_width', int())
        self.img_height = kwargs.get('img_height', int())
        self.center_dist = kwargs.get('center_dist', int())
        self.class_id = kwargs.get('class_id', str())
        self.class_id_int = kwargs.get('class_id_int', int())

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
        if self.probability != other.probability:
            return False
        if self.xmin != other.xmin:
            return False
        if self.ymin != other.ymin:
            return False
        if self.xmax != other.xmax:
            return False
        if self.ymax != other.ymax:
            return False
        if self.id != other.id:
            return False
        if self.img_width != other.img_width:
            return False
        if self.img_height != other.img_height:
            return False
        if self.center_dist != other.center_dist:
            return False
        if self.class_id != other.class_id:
            return False
        if self.class_id_int != other.class_id_int:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def probability(self):
        """Message field 'probability'."""
        return self._probability

    @probability.setter
    def probability(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'probability' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'probability' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._probability = value

    @builtins.property
    def xmin(self):
        """Message field 'xmin'."""
        return self._xmin

    @xmin.setter
    def xmin(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'xmin' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'xmin' field must be an unsigned integer in [0, 65535]"
        self._xmin = value

    @builtins.property
    def ymin(self):
        """Message field 'ymin'."""
        return self._ymin

    @ymin.setter
    def ymin(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ymin' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'ymin' field must be an unsigned integer in [0, 65535]"
        self._ymin = value

    @builtins.property
    def xmax(self):
        """Message field 'xmax'."""
        return self._xmax

    @xmax.setter
    def xmax(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'xmax' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'xmax' field must be an unsigned integer in [0, 65535]"
        self._xmax = value

    @builtins.property
    def ymax(self):
        """Message field 'ymax'."""
        return self._ymax

    @ymax.setter
    def ymax(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ymax' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'ymax' field must be an unsigned integer in [0, 65535]"
        self._ymax = value

    @builtins.property  # noqa: A003
    def id(self):  # noqa: A003
        """Message field 'id'."""
        return self._id

    @id.setter  # noqa: A003
    def id(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'id' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'id' field must be an unsigned integer in [0, 65535]"
        self._id = value

    @builtins.property
    def img_width(self):
        """Message field 'img_width'."""
        return self._img_width

    @img_width.setter
    def img_width(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'img_width' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'img_width' field must be an unsigned integer in [0, 65535]"
        self._img_width = value

    @builtins.property
    def img_height(self):
        """Message field 'img_height'."""
        return self._img_height

    @img_height.setter
    def img_height(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'img_height' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'img_height' field must be an unsigned integer in [0, 65535]"
        self._img_height = value

    @builtins.property
    def center_dist(self):
        """Message field 'center_dist'."""
        return self._center_dist

    @center_dist.setter
    def center_dist(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'center_dist' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'center_dist' field must be an integer in [-2147483648, 2147483647]"
        self._center_dist = value

    @builtins.property
    def class_id(self):
        """Message field 'class_id'."""
        return self._class_id

    @class_id.setter
    def class_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'class_id' field must be of type 'str'"
        self._class_id = value

    @builtins.property
    def class_id_int(self):
        """Message field 'class_id_int'."""
        return self._class_id_int

    @class_id_int.setter
    def class_id_int(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'class_id_int' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'class_id_int' field must be an unsigned integer in [0, 65535]"
        self._class_id_int = value
