cmake_minimum_required(VERSION 3.16)
project(HTML_redactor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/Qt/6.10.2/mingw_64/lib/cmake")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# Add include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Source files
set(SOURCES
    src/main.cpp
    src/HTMLEditor.cpp
)

# Header files
set(HEADERS
    include/HTMLEditor.h
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Link Qt6 libraries
target_link_libraries(${PROJECT_NAME}
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

# Copy necessary DLL files to build directory on Windows
if(WIN32)
    set(QT_BIN_DIR "D:/Qt/6.10.2/mingw_64/bin")

    # Copy main DLL files
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${QT_BIN_DIR}/Qt6Core.dll"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/Qt6Core.dll"
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${QT_BIN_DIR}/Qt6Gui.dll"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/Qt6Gui.dll"
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${QT_BIN_DIR}/Qt6Widgets.dll"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/Qt6Widgets.dll"
    )

    # Copy platform plugin
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/platforms"
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${QT_BIN_DIR}/../plugins/platforms/qwindows.dll"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/platforms/qwindows.dll"
    )
endif()







