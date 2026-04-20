# Phone Checker

A Qt-based application for validating mobile phone numbers in the format `+XXXXXXXXXXX` (plus sign followed by exactly 11 digits).

## Features

- **Real-time validation**: Phone number format is checked as you type
- **Visual feedback**: Color-coded indicator
  - **Green background**: Valid phone number format
  - **Red background**: Invalid format
- **User-friendly interface**: Simple input field with instruction label
- **Pattern-based validation**: Uses regular expressions to validate the format

## Project Structure

```
Phone Checker/
├── CMakeLists.txt          # CMake build configuration
├── main.cpp                # Application entry point
├── README.md               # This file
├── include/
│   └── PhoneChecker.h      # PhoneChecker class definition
└── src/
    └── PhoneChecker.cpp    # PhoneChecker class implementation
```

## Requirements

- Qt 6.10.2 or later
- CMake 4.1 or later
- C++20 compatible compiler (GCC, Clang, or MSVC)

## Building

### Using CMake:

```bash
cd "Phone Checker"
cmake -B cmake-build-debug
cmake --build cmake-build-debug
```

### Using CLion or other Qt IDE:

Simply open the project and build using the IDE's build system.

## Usage

1. Run the application:
   ```bash
   ./cmake-build-debug/Phone_Checker
   ```

2. Enter a phone number in the input field
3. The indicator will change color based on the validation:
   - Green: Valid format (e.g., `+79999999999`)
   - Red: Invalid format

## Phone Number Format

The application validates phone numbers matching this pattern:

- **Pattern**: `^\\+[0-9]{11}$`
- **Description**:
  - `^` - Start of string
  - `\\+` - Plus sign (escaped)
  - `[0-9]{11}` - Exactly 11 digits
  - `$` - End of string

### Valid Examples:
- `+79999999999`
- `+12125551234`
- `+38091234567`

### Invalid Examples:
- `79999999999` (missing plus sign)
- `+7999999999` (only 10 digits)
- `+799999999999` (12 digits)
- `+7999999999a` (contains non-digit character)