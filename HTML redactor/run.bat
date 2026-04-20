@echo off
REM Script to run the HTML Editor with proper environment variables

setlocal

REM Set PATH for Qt and MinGW libraries
set PATH=D:\Qt\6.10.2\mingw_64\bin;C:\Program Files\JetBrains\CLion 2025.2.3\bin\mingw\bin;%PATH%

REM Change to the build directory
cd /d "%~dp0cmake-build-debug"

REM Run the application
echo.
echo ===== Running HTML Editor =====
echo.

HTML_redactor.exe

REM Show error code if application exits with error
if %ERRORLEVEL% NEQ 0 (
    echo.
    echo Application exited with error code: %ERRORLEVEL%
    echo Error code in hex: 0x%=ExitCode:~-8%
    pause
)

