cmake_minimum_required(VERSION 3.14)
project(HttpRequests)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build static libs" FORCE)

FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 1.10.5)
FetchContent_MakeAvailable(cpr)

include_directories(include)

add_executable(HttpRequests main.cpp
        src/http_client.cpp)

target_link_libraries(HttpRequests PRIVATE cpr::cpr)
