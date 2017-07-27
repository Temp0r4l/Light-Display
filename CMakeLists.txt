cmake_minimum_required(VERSION 2.8.3)
project(rgb_light_display)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  cv_bridge
  image_transport
)

catkin_package(
  CATKIN_DEPENDS roscpp rospy std_msgs cv_bridge image_transport
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(rgb_light_node src/rgb_light_display.cpp)
target_link_libraries(rgb_light_node ${catkin_LIBRARIES})
