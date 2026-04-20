cmake_minimum_required(VERSION 4.0)
project(Task_1)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)
add_executable(Task_1 main.cpp
        src/Dog.cpp
        src/SpecificTalents.cpp)
