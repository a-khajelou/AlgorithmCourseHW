cmake_minimum_required(VERSION 3.3)
project(AlgorithmCourseHW)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp LinkedGraph.h ArrayGraph.h)
add_executable(AlgorithmCourseHW ${SOURCE_FILES})