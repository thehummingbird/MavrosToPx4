cmake_minimum_required(VERSION 2.8.3)
project(tester)

## Compile as C++11, supported in ROS Kinetic and newer
 add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  mavros_msgs
  roscpp
  rosbag
  std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES tester
#  CATKIN_DEPENDS geometry_msgs mavros_msgs roscpp std_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


add_executable(MavrosToPx4_node src/MavrosToPx4_node.cpp)

add_dependencies(MavrosToPx4_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(MavrosToPx4_node
   ${catkin_LIBRARIES}
)

add_executable(vio_pub_node src/vio_pub_node.cpp)
add_dependencies(vio_pub_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(vio_pub_node
   ${catkin_LIBRARIES}
)

