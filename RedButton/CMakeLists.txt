cmake_minimum_required(VERSION 4.1)
project(untitled)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/Qt/6.10.2/mingw_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Multimedia
        Network
        REQUIRED)

# Specify directory with header files
include_directories(${CMAKE_SOURCE_DIR}/include)

# List of source files
set(SOURCES
        src/main.cpp
        src/MainWindow.cpp
)

# List of header files
set(HEADERS
        include/MainWindow.h
)

add_executable(untitled ${SOURCES} ${HEADERS})
target_link_libraries(untitled
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Multimedia
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()

    # Copy multimedia plugins
    if (EXISTS "${QT_INSTALL_PATH}/plugins/multimedia")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/multimedia/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_directory
                "${QT_INSTALL_PATH}/plugins/multimedia"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/multimedia/")
    endif ()

    # Copy Qt DLLs (including Network which is required by Multimedia)
    foreach (QT_LIB Core Gui Widgets Multimedia Network)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)

    # Copy FFmpeg DLLs required by Qt Multimedia
    set(FFMPEG_LIBS avcodec-61 avformat-61 avutil-59 swresample-5 swscale-8)
    foreach (FFMPEG_LIB ${FFMPEG_LIBS})
        if (EXISTS "${QT_INSTALL_PATH}/bin/${FFMPEG_LIB}.dll")
            add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy
                    "${QT_INSTALL_PATH}/bin/${FFMPEG_LIB}.dll"
                    "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
        endif ()
    endforeach (FFMPEG_LIB)

    # Copy click.wav resource file
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            "${CMAKE_SOURCE_DIR}/resources/click.wav"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/click.wav")
endif ()
