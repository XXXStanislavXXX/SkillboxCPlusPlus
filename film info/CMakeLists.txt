cmake_minimum_required(VERSION 3.10)
project(Task1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(Task1
        main.cpp
        src/movie_json.cpp
)

# create data directory in build folder
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/data)

# set output directory for the executable
set_target_properties(Task1 PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)
