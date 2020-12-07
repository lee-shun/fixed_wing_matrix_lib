cmake_minimum_required(VERSION 2.8)
project(matrix CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# "If enabled provides support for << operator (as used with std::cout)"
include_directories(${CMAKE_SOURCE_DIR}/matrix/)
add_definitions(-DSUPPORT_STDIOSTREAM)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable (test test/test_Matrix_lee.cpp)
