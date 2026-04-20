cmake_minimum_required(VERSION 3.15)
project(RailwayStationSimulation)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)

add_executable(Task2
        main.cpp
        src/train.cpp
        src/station.cpp
)
