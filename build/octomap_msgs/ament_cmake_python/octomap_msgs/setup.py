from setuptools import find_packages
from setuptools import setup

setup(
    name='octomap_msgs',
    version='2.0.0',
    packages=find_packages(
        include=('octomap_msgs', 'octomap_msgs.*')),
)
