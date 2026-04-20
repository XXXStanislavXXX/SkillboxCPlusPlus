@echo off
REM Script to build and run the HTML Editor

setlocal enabledelayedexpansion

REM Paths
set MINGW_PATH=C:\Program Files\JetBrains\CLion 2025.2.3\bin\mingw
set CMAKE_PATH=C:\Program Files\JetBrains\CLion 2025.2.3\bin\cmake\win\x64\bin
set QT_PATH=D:\Qt\6.10.2\mingw_64
set BUILD_DIR=%CD%\cmake-build-debug
set SOURCE_DIR=%CD%

REM Create build directory if it doesn't exist
if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"
cd /d "%BUILD_DIR%"

REM Configure CMake
echo Configuring CMake...
"%CMAKE_PATH%\cmake.exe" -G "MinGW Makefiles" ^
    -DCMAKE_BUILD_TYPE=Debug ^
    -DCMAKE_PREFIX_PATH=%QT_PATH%/lib/cmake ^
    -DCMAKE_C_COMPILER=%MINGW_PATH%/bin/gcc.exe ^
    -DCMAKE_CXX_COMPILER=%MINGW_PATH%/bin/g++.exe ^
    -DCMAKE_MAKE_PROGRAM=%MINGW_PATH%/bin/mingw32-make.exe ^
    "%SOURCE_DIR%"

if %ERRORLEVEL% NEQ 0 (
    echo CMake configuration failed!
    pause
    exit /b 1
)

REM Build the project
echo Building project...
"%MINGW_PATH%\bin\mingw32-make.exe"

if %ERRORLEVEL% NEQ 0 (
    echo Build failed!
    pause
    exit /b 1
)

echo.
echo Build successful!
echo Executable: %BUILD_DIR%\HTML_redactor.exe
pause

