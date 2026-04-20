# Red Button Application

A simple Qt6 desktop application featuring an interactive red button with sound feedback.

## 📋 Description

Red Button is an educational C++ project using the Qt6 framework. The application demonstrates:
- Creating a user interface with QMainWindow
- Working with Qt signals and slots
- Playing sound files using Qt Multimedia
- Styling components using Qt stylesheets (QSS)

## 🏗️ Project Structure

```
RedButton/
├── include/
│   └── MainWindow.h           # Main window class declaration
├── src/
│   ├── main.cpp               # Application entry point
│   └── MainWindow.cpp         # Main window implementation
├── resources/
│   └── click.wav              # Sound file for playback
├── cmake-build-debug/         # Build directory (automatic)
├── CMakeLists.txt             # CMake configuration
└── README.md                  # This file
```

## 🛠️ Requirements

- **C++** version 20 or higher
- **Qt 6** (tested on Qt 6.10.2)
- **CMake** version 4.1 or higher
- **Compiler**: MinGW 64 (project uses `mingw_64`)
- **OS**: Cross-platform (Windows, Linux, macOS)

### Qt Dependencies

- Qt6::Core
- Qt6::Gui
- Qt6::Widgets
- Qt6::Multimedia

## 🔧 Build and Run

### Using CLion (JetBrains)

1. Open the project in CLion
2. Make sure the Qt path is correct in `CMakeLists.txt`:
   ```cmake
   set(CMAKE_PREFIX_PATH "D:/Qt/6.10.2/mingw_64/lib/cmake")
   ```
3. Go to **Build** → **Build Project**
4. Run the application via **Run** or Shift+F10

### From Command Line

```bash
# Navigate to the project directory
cd RedButton

# Create a build directory
mkdir build
cd build

# Run CMake
cmake ..

# Build the project
cmake --build .

# Run the application
.\untitled.exe
```

## 📝 Usage

1. Run the application
2. Click the red "Click me!" button
3. Hear the sound effect (from `click.wav`)
4. The text on screen will change to "Button clicked!"

## 🎨 Features

- **Red button** - styled using Qt stylesheets (QSS)
- **Dynamic path** - the application automatically finds `click.wav` in its directory
- **QMediaPlayer** - uses Qt Multimedia for cross-platform audio playback
- **Replayable sound** - sound restarts from the beginning on each click

## 📚 Architecture

### MainWindow.h
Defines the `MainWindow` class with:
- Member variables: `QLabel`, `QPushButton`, `QMediaPlayer`, `QAudioOutput`
- Methods:
  - `MainWindow()` - constructor
  - `setupUI()` - initializes the user interface
  - `connectSignals()` - connects signals to slots
  - `onButtonClicked()` - slot for handling button clicks

### MainWindow.cpp
Implements the functionality:
- Creating a layout with label and button
- Setting styles via QSS
- Playing sound on button click using Qt Multimedia (`QMediaPlayer`)
- Initializing `QMediaPlayer` and `QAudioOutput` in the constructor

### main.cpp
Application entry point:
- Creates a `QApplication` object
- Creates and displays the main window
- Runs the event loop

## 🔊 Sound Playback

The application uses Qt Multimedia framework for cross-platform audio playback:
```cpp
// Initialize in constructor
player = new QMediaPlayer(this);
audioOutput = new QAudioOutput(this);
player->setAudioOutput(audioOutput);
player->setSource(QUrl::fromLocalFile(soundFile));

// Play on button click
player->setPosition(0); // Reset to beginning
player->play();