# CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project(Task2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(Task2
        src/main.cpp
        src/shared_ptr_toy.cpp
        src/toy.cpp
)
