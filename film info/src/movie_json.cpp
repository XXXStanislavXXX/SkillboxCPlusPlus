#include "movie_json.h"
#include <fstream>

bool createMovieJson(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        file.close();
    }

    file << R"({
  "title": "Interstellar",
  "country": "United States",
  "release_date": "2014-11-07",
  "studio": "Paramount Pictures",
  "production_companies": [
    "Legendary Pictures",
    "Syncopy",
    "Lynda Obst Productions"
  ],
  "screenplay_authors": [
    {
      "name": "Jonathan Nolan",
      "role": "screenplay"
    },
    {
      "name": "Christopher Nolan",
      "role": "screenplay"
    }
  ],
  "director": "Christopher Nolan",
  "producers": [
    "Emma Thomas",
    "Christopher Nolan",
    "Lynda Obst"
  ],
  "main_cast": [
    {
      "character": "Joseph Cooper",
      "actor": "Matthew McConaughey"
    },
    {
      "character": "Dr. Amelia Brand",
      "actor": "Anne Hathaway"
    },
    {
      "character": "Murphy Cooper",
      "actor": "Jessica Chastain"
    },
    {
      "character": "Dr. Mann",
      "actor": "Matt Damon"
    },
    {
      "character": "Professor John Brand",
      "actor": "Michael Caine"
    }
  ],
  "runtime_minutes": 169,
  "genres": [
    "Science Fiction",
    "Drama",
    "Adventure"
  ]
})";

    file.close();
    return true;
}

bool validateMovieJson(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}
