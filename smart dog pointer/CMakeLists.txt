cmake_minimum_required(VERSION 3.20)
project(Task1)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(Task1
        main.cpp
        src/Toy.cpp
        src/Dog.cpp
)
