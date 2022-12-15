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
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(nav_msgs REQUIRED)

include_directories(include)

add_executable(x_pubsub src/main.cpp)
ament_target_dependencies(x_pubsub tf2 tf2_ros rclcpp std_msgs sensor_msgs geometry_msgs nav_msgs turtlebot3_gazebo)
add_library(library src/pubsub.cpp src/master.cpp src/trajectory.cpp)
target_include_directories(library PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
ament_target_dependencies(library tf2 tf2_ros rclcpp std_msgs sensor_msgs geometry_msgs nav_msgs turtlebot3_gazebo)


target_link_directories(x_pubsub PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(x_pubsub library)

install(TARGETS
  x_pubsub
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY
launch
DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_cmake_gtest REQUIRED)
  find_package(ament_lint_auto REQUIRED)

  # the following lines skip linters
  set(ament_cmake_cppcheck_FOUND TRUE)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  set(ament_cmake_flake8_FOUND TRUE)
  set(ament_cmake_uncrustify_FOUND TRUE)
  set(ament_cmake_xmllint_FOUND TRUE)
  set(ament_cmake_lint_cmake_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()

  ament_lint_auto_find_test_dependencies()
  set(TESTFILES
    test/main.cpp
    test/test.cpp
    test/pubsub_test.cpp
    )
  ament_add_gtest(test_${PROJECT_NAME} ${TESTFILES})
  ament_target_dependencies(test_${PROJECT_NAME} tf2 tf2_ros rclcpp std_msgs sensor_msgs geometry_msgs nav_msgs turtlebot3_gazebo)

  install(TARGETS
    test_${PROJECT_NAME}
    DESTINATION lib/${PROJECT_NAME})
endif()

ament_package()
