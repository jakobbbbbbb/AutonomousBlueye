from setuptools import find_packages
from setuptools import setup

setup(
    name='bboxes_ex_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('bboxes_ex_msgs', 'bboxes_ex_msgs.*')),
)
