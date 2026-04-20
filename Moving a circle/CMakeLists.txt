cmake_minimum_required(VERSION 4.1)
project(Moving_a_circle)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/Qt/6.10.2/mingw_64/lib/cmake")

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Quick
        Qml
        QmlModels
        REQUIRED)

qt_add_executable(Moving_a_circle src/main.cpp)

qt_add_qml_module(Moving_a_circle
        URI MovingCircle
        VERSION 1.0
        QML_FILES main.qml
)

# Копирование qt.conf
add_custom_command(TARGET Moving_a_circle POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_SOURCE_DIR}/qt.conf"
        "$<TARGET_FILE_DIR:Moving_a_circle>/qt.conf")

# Использование windeployqt для автоматического копирования зависимостей
if (WIN32)
    find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${CMAKE_PREFIX_PATH}/../../bin")
    if (WINDEPLOYQT_EXECUTABLE)
        add_custom_command(TARGET Moving_a_circle POST_BUILD
                COMMAND ${WINDEPLOYQT_EXECUTABLE}
                --qmldir "${CMAKE_SOURCE_DIR}"
                --no-compiler-runtime
                --no-system-d3d-compiler
                --no-translations
                "$<TARGET_FILE:Moving_a_circle>"
                COMMENT "Running windeployqt...")
    endif()
endif()

target_link_libraries(Moving_a_circle PRIVATE
        Qt::Core
        Qt::Gui
        Qt::Quick
        Qt::Qml
        Qt::QmlModels
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

    # Копирование platforms плагина
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()

    # Копирование основных Qt DLL
    foreach (QT_LIB Core Gui Widgets Quick Qml Network OpenGL QmlModels)
        if (EXISTS "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll")
            add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy
                    "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                    "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
        endif ()
    endforeach (QT_LIB)

    # Копирование дополнительных необходимых DLL
    set(ADDITIONAL_DLLS
        "libgcc_s_seh-1.dll"
        "libstdc++-6.dll"
        "libwinpthread-1.dll"
    )
    foreach (DLL_NAME ${ADDITIONAL_DLLS})
        if (EXISTS "${QT_INSTALL_PATH}/bin/${DLL_NAME}")
            add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy
                    "${QT_INSTALL_PATH}/bin/${DLL_NAME}"
                    "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
        endif ()
    endforeach ()

    # Копирование QML модулей
    set(QML_MODULES
        "QtQuick"
        "QtQml"
    )
    foreach (QML_MODULE ${QML_MODULES})
        if (EXISTS "${QT_INSTALL_PATH}/qml/${QML_MODULE}")
            add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_directory
                    "${QT_INSTALL_PATH}/qml/${QML_MODULE}"
                    "$<TARGET_FILE_DIR:${PROJECT_NAME}>/qml/${QML_MODULE}")
        endif ()
    endforeach ()
endif ()
