cmake_minimum_required(VERSION 2.0)
project(rgb)
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(rgb2 rgb2.cpp)
target_link_libraries(rgb2 ${OpenCV_LIBS})


