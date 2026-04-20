# Template-based Data Registry

A simple console registry implemented using C++ templates. Stores key-value pairs; keys may repeat. Supported key and value types: `int`, `double`, `std::string`.

1. How it works
    1. The project contains a template registry class and an entry point that parses commands from standard input.
    2. On startup the user selects the key type and value type (1 \- `int`, 2 \- `double`, 3 \- `std::string`), then enters commands.

1. Project structure
    1. `include/entry.h` \- definition of the key/value pair.
    2. `include/registry.h` \- template class `Registry` with methods `add`, `remove`, `find`, `printAll`.
    3. `src/main.cpp` \- command parsing and registry runner.
    4. `CMakeLists.txt` \- (optional) CMake build file.

1. Commands (from console)
    1. `add <key> <value>` \- add an element.
    2. `remove <key>` \- remove all elements with the specified key.
    3. `find <key>` \- print all values for the key.
    4. `print` \- print all key-value pairs.
    5. `exit` \- exit the program.

1. Usage examples
    1. Select types: enter `1` (key `int`), then `3` (value `std::string`).
    2. Commands:
        1. `add 1 hello`
        2. `add 1 world`
        3. `find 1` \- prints `hello` and `world`
        4. `print` \- prints all pairs
        5. `remove 1` \- deletes all entries with key `1`
        6. `exit`

1. Limitations and notes
    1. Input is tokenized by spaces using `operator>>`. String values cannot contain spaces (they are read as separate tokens).
    2. Numeric parsing is done with `std::stol` / `std::stod` with verification that the whole string was converted.
    3. Template implementations are located in header files to ensure instantiation when included.

1. Build and run (Windows, CLion or command line)
    1. Open the project in CLion and run the build configuration.
    2. Or use CMake in the terminal:
        1. `mkdir build`
        2. `cd build`
        3. `cmake ..`
        4. `cmake --build .`
        5. Run the produced executable from the `build` directory.

1. Notes
    1. The files are implemented in plain C++ and intended as an educational exercise for templates and containers.
