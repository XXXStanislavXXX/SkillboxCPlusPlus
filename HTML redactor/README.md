# HTML Editor

A professional real-time HTML editor with live preview built in C++ using Qt6.

## Overview

HTML Editor is a lightweight, user-friendly desktop application that provides a split-window interface for editing HTML code and viewing the rendered result in real-time. Changes in the editor are instantly reflected in the preview panel, making it perfect for rapid HTML development and learning.

## Features

✅ **Real-time HTML Preview** - See changes instantly as you type
✅ **Split-window Interface** - Edit on the left, preview on the right
✅ **Professional UI** - Clean, intuitive, and responsive design
✅ **Fast Performance** - Lightweight and responsive application
✅ **No File Restrictions** - Edit any HTML content
✅ **Auto-formatting** - Proper spacing and indentation support
✅ **Equal Panel Sizing** - Both panels take equal horizontal space

## Quick Start

### Installation

1. **Install Qt 6.10.2 MinGW**
   - Download from https://www.qt.io/download
   - Choose MinGW 64-bit variant
   - Note the installation path (default: `D:/Qt/6.10.2/mingw_64`)

2. **Install CMake**
   - Version 3.16 or later
   - Download from https://cmake.org/download/

3. **Clone the Project**
   ```bash
   git clone <repository-url>
   cd "HTML redactor"
   ```

### Building

**Method 1: Using the Build Script (Windows)**
```bash
build.bat
```

**Method 2: Using CLion**
1. Open the project folder
2. Press `Ctrl+F9` to build
3. Press `Shift+F10` to run

**Method 3: Command Line**
```bash
mkdir cmake-build-debug
cd cmake-build-debug
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
mingw32-make
```

### Running the Application

**Method 1: Run Script**
```bash
run.bat
```

**Method 2: Direct Execution**
```bash
cmake-build-debug\HTML_redactor.exe
```

**Method 3: From CLion**
- Press `Shift+F10`

## Usage

### Basic Workflow

1. **Start the Application**
   - Launch `HTML_redactor.exe`

2. **Type HTML Code**
   - Enter HTML code in the left panel
   - Use standard HTML syntax

3. **View the Result**
   - The right panel displays the rendered HTML
   - Updates happen in real-time

### Example HTML

```html
<html>
<head>
    <title>My Page</title>
</head>
<body>
    <h1>Welcome!</h1>
    <p>This is a test page</p>
</body>
</html>
```

### Common HTML Tags

```html
<h1> to <h6>   - Headings
<p>             - Paragraph
<strong>        - Bold text
<em>            - Italic text
<br>            - Line break
<img>           - Image
<a>             - Link
<ul>, <li>      - Unordered list
<ol>, <li>      - Ordered list
<div>           - Container
<span>          - Inline container
<table>         - Table
<form>          - Form
```

## System Requirements

| Component | Version | Required |
|-----------|---------|----------|
| Windows | 10/11 | ✅ Yes |
| Qt | 6.10.2 MinGW | ✅ Yes |
| CMake | 3.16+ | ✅ Yes |
| Compiler | GCC 11.0+ (MinGW) | ✅ Yes |
| RAM | 2GB | ✅ Minimum |
| Disk Space | 500MB | ✅ Available |

## Project Structure

```
HTML redactor/
├── include/
│   └── HTMLEditor.h              Class declaration with full documentation
│
├── src/
│   ├── HTMLEditor.cpp            Class implementation
│   └── main.cpp                  Application entry point
│
├── CMakeLists.txt                Build configuration
├── Makefile                      Alternative build method
├── build.bat                     Windows build script
├── run.bat                       Windows run script
│
└── cmake-build-debug/            Build output directory
    ├── HTML_redactor.exe         Executable file
    ├── Qt6Core.dll               Qt Core library
    ├── Qt6Gui.dll                Qt GUI library
    ├── Qt6Widgets.dll            Qt Widgets library
    └── platforms/qwindows.dll    Windows platform plugin
```

## Architecture

### Class Hierarchy

```
QMainWindow
    ↓
HTMLEditor
```

### Main Components

**HTMLEditor Class**
- Inherits from `QMainWindow`
- Manages the main window and UI layout
- Handles HTML preview updates

**UI Layout**
- `QPlainTextEdit` (left panel) - For HTML code editing
- `QTextBrowser` (right panel) - For HTML preview
- `QHBoxLayout` - Horizontal layout with equal sizing

**Signal/Slot Mechanism**
- `textChanged()` signal from editor
- `updatePreview()` slot for browser update
- Real-time synchronization

