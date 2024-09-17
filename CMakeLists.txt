cmake_minimum_required(VERSION 3.29)
project(blackboard CXX)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)
include_directories("src")
include_directories("include")

add_executable(blackboard
    src/main.cpp)