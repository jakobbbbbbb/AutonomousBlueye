from setuptools import find_packages, setup

package_name = 'control'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools', 'pytest'],
    zip_safe=True,
    maintainer='nikolai',
    maintainer_email='nikolarn@stud.ntnu.no',
    description='TODO: Package description',
    license='TODO: License declaration',
    entry_points={
        'console_scripts': [
            'control = control.control:main',
            'control_test = control.control_test:main',
            'desired_velocity = control.desired_velocity:main',
            'desired_velocity_test = control.desired_velocity_test:main',
            'desired_velocity_spiral_surge = control.desired_velocity_spiral_surge:main',
            'desired_velocity_compass = control.desired_velocity_compass:main',
            'desired_velocity_switch = control.desired_velocity_switch:main',
        ],
    },
)
