from setuptools import find_packages
from setuptools import setup

setup(
    name='pcl_msgs',
    version='1.0.0',
    packages=find_packages(
        include=('pcl_msgs', 'pcl_msgs.*')),
)
