cmake_minimum_required(VERSION 3.14)
project(html_fetcher)

set(CMAKE_CXX_STANDARD 17)

if(WIN32)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    set(BUILD_SHARED_LIBS OFF)
endif()

include(FetchContent)

FetchContent_Declare(cpr
        GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 1.10.5
)

set(CPR_FORCE_USE_SYSTEM_CURL OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(cpr)

include_directories(include)

add_executable(html_fetcher
        src/main.cpp
        src/html_parser.cpp
)

target_link_libraries(html_fetcher PRIVATE cpr::cpr)
