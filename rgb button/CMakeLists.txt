cmake_minimum_required(VERSION 3.16)
project(Task1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(Qt6_DIR "D:\\Qt\\6.7.0\\mingw_64\\lib\\cmake\\Qt6")
set(CMAKE_PREFIX_PATH "D:\\Qt\\6.7.0\\mingw_64")

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

add_executable(${PROJECT_NAME}
        main.cpp
        include/ColorfulCircle.h
        src/ColorfulCircle.cpp
        buttons.qrc
)

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_link_libraries(${PROJECT_NAME}
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
)
