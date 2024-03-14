from setuptools import find_packages, setup

package_name = 'experimental'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='nikolai',
    maintainer_email='nikolarn@stud.ntnu.no',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            #'Image_test = experimental.Image_test:main',
            #'blueye_image_yolo = experimental.blueye_image_yolo:main',
            'Video_to_topic = experimental.Video_to_topic:main',
            'control_test = experimental.control_test:main',
        ],
    },
)
