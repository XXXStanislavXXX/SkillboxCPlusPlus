cmake_minimum_required(VERSION 4.0)
project(Task4)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)
add_executable(Task4
        src/main.cpp
        src/array_utils.cpp)
