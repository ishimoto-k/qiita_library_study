cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 14)

add_library(SharedAdd SHARED add.cpp)
add_library(SharedSub SHARED sub.cpp)

add_executable(main main.cpp)