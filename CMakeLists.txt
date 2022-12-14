cmake_minimum_required(VERSION 3.8)
project(ENPM808X_PacMan)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(turtlebot3_gazebo REQUIRED)

add_executable(x_pubsub src/pubsub.cpp)
ament_target_dependencies(x_pubsub rclcpp sensor_msgs geometry_msgs std_msgs tf2 tf2_ros turtlebot3_gazebo)

install(TARGETS
  x_pubsub
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY
launch
DESTINATION share/${PROJECT_NAME}
)

ament_package()
