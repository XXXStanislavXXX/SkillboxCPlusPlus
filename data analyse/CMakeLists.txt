cmake_minimum_required(VERSION 3.10)
project(Task1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# Fetch nlohmann/json library
include(FetchContent)
FetchContent_Declare(
        json
        URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)
FetchContent_MakeAvailable(json)

add_executable(Task1
        main.cpp
        src/movie_json.cpp
)

# Link nlohmann/json library
target_link_libraries(Task1 PRIVATE nlohmann_json::nlohmann_json)

# Create data directory in build folder
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/data)

# Set output directory for the executable
set_target_properties(Task1 PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)
