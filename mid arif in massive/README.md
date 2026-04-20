# Average of array (template)

This project implements template functions to read an array of 8 scalar values and compute the arithmetic mean.

Files:
- `include/array_utils.h` - declarations
- `src/array_utils.cpp` - implementations + explicit instantiations
- `src/main.cpp` - example usage

Build (example with g++ on Windows/MinGW):
g++ -std=c++17 src/*.cpp -Iinclude -o average.exe

Run:
.\average.exe
