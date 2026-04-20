#ifndef MOVIE_JSON_H
#define MOVIE_JSON_H

#include <string>
#include <vector>
#include <map>

struct ActorRole {
    std::string actor;
    std::string character;
};

struct Movie {
    std::string country;
    std::string release_date;
    std::string studio;
    std::vector<std::string> screenplay_authors;
    std::string director;
    std::vector<std::string> producers;
    std::vector<ActorRole> main_cast;
};

bool createMovieJson(const std::string& filename);
bool validateMovieJson(const std::string& filename);
bool createMoviesDatabase(const std::string& filename);
std::map<std::string, Movie> loadMoviesDatabase(const std::string& filename);
void searchActorByName(const std::map<std::string, Movie>& database, const std::string& actorName);

#endif
