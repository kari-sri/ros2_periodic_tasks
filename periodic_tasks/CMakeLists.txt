cmake_minimum_required(VERSION 3.5)
project(periodic_tasks)

# Find packages
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# Add the executable
add_executable(periodic_task_node src/periodic_task_node.cpp)

# Specify dependencies for the executable
ament_target_dependencies(periodic_task_node rclcpp std_msgs)

# Install the executable
install(TARGETS
  periodic_task_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()

