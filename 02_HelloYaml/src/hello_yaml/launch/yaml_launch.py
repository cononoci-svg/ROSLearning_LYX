import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
  config = os.path.join(
    get_package_share_directory('hello_yaml'),
    'config',
    'params.yaml'
  )
  return LaunchDescription([
    Node(
      package='hello_yaml',
      executable='yaml_pub_node',
      name='yaml_pub_node',
      parameters=[config]
    )
  ])