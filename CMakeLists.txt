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

add_executable(WALKER src/walker_node.cpp)
ament_target_dependencies(WALKER rclcpp sensor_msgs geometry_msgs std_msgs tf2 tf2_ros turtlebot3_gazebo)

install(TARGETS
  WALKER
  DESTINATION lib/${PROJECT_NAME}/
)

install(DIRECTORY
launch
DESTINATION share/${PROJECT_NAME}
)

ament_package()

if(BUILD_TESTING)
  find_package(ament_cmake_gtest REQUIRED)
  find_package(ament_lint_auto REQUIRED)

  # Add a gtest executable
  set(TESTFILES
    test/test_pub.cpp
    talker)
  ament_add_gtest(${PROJECT_NAME}_test ${TESTFILES})

  target_link_libraries(${PROJECT_NAME}_test "${cpp_typesupport_target}")
  ament_target_dependencies(${PROJECT_NAME}_test ${THIS_PACKAGE_INCLUDE_DEPENDS})
  INSTALL(TARGETS ${PROJECT_NAME}_test DESTINATION lib/${PROJECT_NAME})
endif()

ament_export_dependencies(${THIS_PACKAGE_INCLUDE_DEPENDS})
ament_package()
