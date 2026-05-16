from launch import LaunchDescription
from launch_ros.actions import Node
import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    pkg_dir = get_package_share_directory("training_pkg")
    yaml_path = os.path.join(pkg_dir,"params","params.yaml")

    talker = Node(
        package="training_pkg",
        executable="talker",
        parameters=[yaml_path]
    )
    listener = Node(
        package="training_pkg",
        executable="listener" 
    )
    return LaunchDescription([talker,listener])
