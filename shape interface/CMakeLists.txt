cmake_minimum_required(VERSION 4.0)
project(Task_2)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)
add_executable(Task_2 main.cpp
        src/Shape.cpp
        src/Circle.cpp
        src/Rectangle.cpp
        src/Triangle.cpp)
