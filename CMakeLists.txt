cmake_minimum_required(VERSION 3.13)  # CMake version check
project(combineVectors)               # Create project
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

include_directories(src)
include_directories(tst)

add_subdirectory(src)
add_subdirectory(tst)
