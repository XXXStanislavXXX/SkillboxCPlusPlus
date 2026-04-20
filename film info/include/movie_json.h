#ifndef MOVIE_JSON_H
#define MOVIE_JSON_H

#include <string>

/**
 * Creates a JSON file with movie details
 * @param filename path to the file to be created
 * @return true if successfully created, other false
 */
bool createMovieJson(const std::string& filename);

/**
 * Validates the JSON file for correct structure
 * @param filename path to the file to be validated
 * @return true if JSON valid, other false
 */
bool validateMovieJson(const std::string& filename);

#endif // MOVIE_JSON_H
