cmake_minimum_required(VERSION 3.8)
project(hello_ros)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(hello_ros_msgs REQUIRED)

add_executable(hello_ros_pub_node src/hello_ros_pub_node.cpp)
ament_target_dependencies(hello_ros_pub_node rclcpp std_msgs hello_ros_msgs)

add_executable(hello_ros_sub_node src/hello_ros_sub_node.cpp)
ament_target_dependencies(hello_ros_sub_node rclcpp std_msgs hello_ros_msgs)

install(TARGETS hello_ros_pub_node hello_ros_sub_node
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch DESTINATION share/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()