#include "include/movie_json.h"
#include <iostream>

int main() {
  const std::string dbFilename = "data/movies_database.json";

  if (createMoviesDatabase(dbFilename)) {
    std::cout << "База данных создана: " << dbFilename << std::endl;
  }

  auto database = loadMoviesDatabase(dbFilename);

  std::string searchName;
  std::cout << "\nEnter search name/ second name: ";
  std::getline(std::cin, searchName);

  std::cout << "\nSearch results\n" << std::endl;
  searchActorByName(database, searchName);

  return 0;
}
