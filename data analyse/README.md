# Task 1: Movie Information from Cinema Portal

## Description

This project creates a JSON database with detailed information about movies and provides search functionality for actors. The database includes five Christopher Nolan films with complete cast information.

## Project Structure

Task1/ ├── include/ │
       └── movie_json.h # Header file with function declarations 
       ├── src/ 
       │ 
       └── movie_json.cpp # Implementation of JSON functions 
       ├── data/ 
       │ 
       └── movies_database.json # JSON database (auto-generated) 
       ├── CMakeLists.txt # CMake build configuration 
       ├── main.cpp # Main program file 
       └── README.md # This file

## Requirements

- CMake 3.10 or higher
- C++20 compatible compiler
- CLion 2025.2.4 (recommended)
- nlohmann/json library (auto-downloaded via FetchContent)

### Movie Structure

Each movie contains:

- **country** — country of production
- **release_date** — release date (YYYY-MM-DD format)
- **studio** — production studio
- **screenplay_authors** — screenplay writers (array)
- **director** — director name
- **producers** — producers (array)
- **main_cast** — main actors with their roles (array of objects)
       - **actor** — actor's full name
       - **character** — character name

## Database

The JSON database includes five movies:

1. **Interstellar** (2014)
2. **Inception** (2010)
3. **The Dark Knight** (2008)
4. **The Prestige** (2006)
5. **Dunkirk** (2017)

## Functions

### `createMovieJson(const std::string& filename)`

Creates a single movie JSON file.

**Parameters:**
- `filename` — path to save the file

**Returns:** `true` on success, `false` otherwise

### `validateMovieJson(const std::string& filename)`

Validates JSON file structure and required fields.

**Parameters:**
- `filename` — path to file for validation

**Returns:** `true` if valid, `false` otherwise

### `createMoviesDatabase(const std::string& filename)`

Creates the complete movies database with five films.

**Parameters:**
- `filename` — path to save the database

**Returns:** `true` on success, `false` otherwise

### `loadMoviesDatabase(const std::string& filename)`

Loads and parses the movies database from JSON file.

**Parameters:**
- `filename` — path to database file

**Returns:** `std::map<std::string, Movie>` with movie titles as keys

### `searchActorByName(const std::map<std::string, Movie>& database, const std::string& actorName)`

Searches for an actor by name (or surname) and displays all movies they appeared in with their roles.

**Parameters:**
- `database` — loaded movies database
- `actorName` — actor's name or surname to search (case-insensitive)

**Output:** Prints movie title, actor name, and role for each match

## Build Instructions

1. Open the project in CLion
2. CLion will automatically configure CMake
3. Build the project (Ctrl+F9)
4. Run the executable

Or using command line:

```bash
mkdir build
cd build
cmake ..
cmake --build .
./Task1

## Usage example

Database created: data/movies_database.json

Enter actor name or surname to search: Hardy

Search results:

Movie: Inception
Actor: Tom Hardy
Role: Eames
---
Movie: Dunkirk
Actor: Tom Hardy
Role: Farrier
---

## Features

✅ Valid JSON structure
✅ Five movies database
✅ Actor search by name/surname
✅ Case-insensitive search
✅ Automatic nlohmann/json library integration
✅ Complete cast information with roles

## JSON Structure Example

{
  "Movie Title": {
    "country": "USA",
    "release_date": "YYYY-MM-DD",
    "studio": "Studio Name",
    "screenplay_authors": ["Author1", "Author2"],
    "director": "Director Name",
    "producers": ["Producer1", "Producer2"],
    "main_cast": [
      {
        "actor": "Actor Full Name",
        "character": "Character Name"
      }
    ]
  }
}
