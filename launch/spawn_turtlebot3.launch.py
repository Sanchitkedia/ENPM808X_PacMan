import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    # Get the urdf file
    Number_of_Turtlebot3 = 12
    TURTLEBOT3_MODEL = os.environ['TURTLEBOT3_MODEL']
    model_folder = 'turtlebot3_' + TURTLEBOT3_MODEL
    urdf_path = os.path.join(
        get_package_share_directory('turtlebot3_gazebo'),
        'models',
        model_folder,
        'model.sdf'
    )

    ld = LaunchDescription()

    for i in range(Number_of_Turtlebot3):
        x_pose = str(i*0.5)
        y_pose = str(i*0.5)
        start_gazebo_ros_spawner_cmd = Node(
            package='gazebo_ros',
            executable='spawn_entity.py',
            arguments=[
                '-entity', 'Tb'+str(i),
                '-file', urdf_path,
                "-robot_namespace", 'tb'+str(i),
                '-x', x_pose,
                '-y', y_pose,
                '-z', '0.01'
            ],
            output='screen',
        )
        ld.add_action(start_gazebo_ros_spawner_cmd)
 

    return ld