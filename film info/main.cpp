#include <iostream>
#include "include/movie_json.h"

int main() {
  const std::string filename = "data/movie.json";

  if (createMovieJson(filename)) {
    std::cout << "JSON successfully created: " << filename << std::endl;

    if (validateMovieJson(filename)) {
      std::cout << "JSON-valid" << std::endl;
    }
  } else {
    std::cerr << "Creation failure" << std::endl;
    return 1;
  }

  return 0;
}
