# generated from rosidl_generator_py/resource/_idl.py.em
# with input from octomap_msgs:srv/GetOctomap.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GetOctomap_Request(type):
    """Metaclass of message 'GetOctomap_Request'."""

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
            module = import_type_support('octomap_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'octomap_msgs.srv.GetOctomap_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_octomap__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_octomap__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_octomap__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_octomap__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_octomap__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetOctomap_Request(metaclass=Metaclass_GetOctomap_Request):
    """Message class 'GetOctomap_Request'."""

    __slots__ = [
    ]

    _fields_and_field_types = {
    }

    SLOT_TYPES = (
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))

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
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)


# Import statements for member types

import builtins  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_GetOctomap_Response(type):
    """Metaclass of message 'GetOctomap_Response'."""

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
            module = import_type_support('octomap_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'octomap_msgs.srv.GetOctomap_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_octomap__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_octomap__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_octomap__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_octomap__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_octomap__response

            from octomap_msgs.msg import Octomap
            if Octomap.__class__._TYPE_SUPPORT is None:
                Octomap.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetOctomap_Response(metaclass=Metaclass_GetOctomap_Response):
    """Message class 'GetOctomap_Response'."""

    __slots__ = [
        '_map',
    ]

    _fields_and_field_types = {
        'map': 'octomap_msgs/Octomap',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['octomap_msgs', 'msg'], 'Octomap'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from octomap_msgs.msg import Octomap
        self.map = kwargs.get('map', Octomap())

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
        if self.map != other.map:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property  # noqa: A003
    def map(self):  # noqa: A003
        """Message field 'map'."""
        return self._map

    @map.setter  # noqa: A003
    def map(self, value):  # noqa: A003
        if __debug__:
            from octomap_msgs.msg import Octomap
            assert \
                isinstance(value, Octomap), \
                "The 'map' field must be a sub message of type 'Octomap'"
        self._map = value


class Metaclass_GetOctomap(type):
    """Metaclass of service 'GetOctomap'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('octomap_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'octomap_msgs.srv.GetOctomap')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__get_octomap

            from octomap_msgs.srv import _get_octomap
            if _get_octomap.Metaclass_GetOctomap_Request._TYPE_SUPPORT is None:
                _get_octomap.Metaclass_GetOctomap_Request.__import_type_support__()
            if _get_octomap.Metaclass_GetOctomap_Response._TYPE_SUPPORT is None:
                _get_octomap.Metaclass_GetOctomap_Response.__import_type_support__()


class GetOctomap(metaclass=Metaclass_GetOctomap):
    from octomap_msgs.srv._get_octomap import GetOctomap_Request as Request
    from octomap_msgs.srv._get_octomap import GetOctomap_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
