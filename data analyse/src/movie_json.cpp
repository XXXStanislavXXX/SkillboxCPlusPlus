#include "../include/movie_json.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <algorithm>

using json = nlohmann::json;

bool createMovieJson(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    json j = {
        {"country", "USA"},
        {"release_date", "2014-11-07"},
        {"studio", "Paramount Pictures"},
        {"screenplay_authors", {"Jonathan Nolan", "Christopher Nolan"}},
        {"director", "Christopher Nolan"},
        {"producers", {"Emma Thomas", "Christopher Nolan", "Lynda Obst"}},
        {"main_cast", {
            {{"actor", "Matthew McConaughey"}, {"character", "Cooper"}},
            {{"actor", "Anne Hathaway"}, {"character", "Brand"}},
            {{"actor", "Jessica Chastain"}, {"character", "Murph"}}
        }}
    };

    file << j.dump(2);
    file.close();
    return true;
}

bool validateMovieJson(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    try {
        json j;
        file >> j;

        // Check required fields
        if (!j.contains("country") || !j.contains("release_date") ||
            !j.contains("studio") || !j.contains("director") ||
            !j.contains("main_cast")) {
            return false;
        }

        file.close();
        return true;
    } catch (json::exception&) {
        file.close();
        return false;
    }
}

bool createMoviesDatabase(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    json database = {
        {"Interstellar", {
            {"country", "USA"},
            {"release_date", "2014-11-07"},
            {"studio", "Paramount Pictures"},
            {"screenplay_authors", {"Jonathan Nolan", "Christopher Nolan"}},
            {"director", "Christopher Nolan"},
            {"producers", {"Emma Thomas", "Christopher Nolan", "Lynda Obst"}},
            {"main_cast", {
                {{"actor", "Matthew McConaughey"}, {"character", "Cooper"}},
                {{"actor", "Anne Hathaway"}, {"character", "Brand"}},
                {{"actor", "Jessica Chastain"}, {"character", "Murph"}}
            }}
        }},
        {"Inception", {
            {"country", "USA"},
            {"release_date", "2010-07-16"},
            {"studio", "Warner Bros"},
            {"screenplay_authors", {"Christopher Nolan"}},
            {"director", "Christopher Nolan"},
            {"producers", {"Emma Thomas", "Christopher Nolan"}},
            {"main_cast", {
                {{"actor", "Leonardo DiCaprio"}, {"character", "Cobb"}},
                {{"actor", "Marion Cotillard"}, {"character", "Mal"}},
                {{"actor", "Tom Hardy"}, {"character", "Eames"}}
            }}
        }},
        {"The Dark Knight", {
            {"country", "USA"},
            {"release_date", "2008-07-18"},
            {"studio", "Warner Bros"},
            {"screenplay_authors", {"Jonathan Nolan", "Christopher Nolan"}},
            {"director", "Christopher Nolan"},
            {"producers", {"Emma Thomas", "Christopher Nolan", "Charles Roven"}},
            {"main_cast", {
                {{"actor", "Christian Bale"}, {"character", "Bruce Wayne"}},
                {{"actor", "Heath Ledger"}, {"character", "Joker"}},
                {{"actor", "Aaron Eckhart"}, {"character", "Harvey Dent"}}
            }}
        }},
        {"The Prestige", {
            {"country", "USA"},
            {"release_date", "2006-10-20"},
            {"studio", "Touchstone Pictures"},
            {"screenplay_authors", {"Jonathan Nolan", "Christopher Nolan"}},
            {"director", "Christopher Nolan"},
            {"producers", {"Emma Thomas", "Aaron Ryder", "Christopher Nolan"}},
            {"main_cast", {
                {{"actor", "Christian Bale"}, {"character", "Alfred Borden"}},
                {{"actor", "Hugh Jackman"}, {"character", "Robert Angier"}},
                {{"actor", "Scarlett Johansson"}, {"character", "Olivia Wenscombe"}}
            }}
        }},
        {"Dunkirk", {
            {"country", "USA"},
            {"release_date", "2017-07-21"},
            {"studio", "Warner Bros"},
            {"screenplay_authors", {"Christopher Nolan"}},
            {"director", "Christopher Nolan"},
            {"producers", {"Emma Thomas", "Christopher Nolan"}},
            {"main_cast", {
                {{"actor", "Fionn Whitehead"}, {"character", "Tommy"}},
                {{"actor", "Tom Hardy"}, {"character", "Farrier"}},
                {{"actor", "Mark Rylance"}, {"character", "Mr. Dawson"}}
            }}
        }}
    };

    file << database.dump(2);
    file.close();
    return true;
}

std::map<std::string, Movie> loadMoviesDatabase(const std::string& filename) {
    std::map<std::string, Movie> database;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return database;
    }

    json j;
    try {
        file >> j;

        for (auto& [movieTitle, movieData] : j.items()) {
            Movie movie;
            movie.country = movieData["country"];
            movie.release_date = movieData["release_date"];
            movie.studio = movieData["studio"];
            movie.director = movieData["director"];

            for (auto& author : movieData["screenplay_authors"]) {
                movie.screenplay_authors.push_back(author);
            }

            for (auto& producer : movieData["producers"]) {
                movie.producers.push_back(producer);
            }

            for (auto& cast : movieData["main_cast"]) {
                ActorRole role;
                role.actor = cast["actor"];
                role.character = cast["character"];
                movie.main_cast.push_back(role);
            }

            database[movieTitle] = movie;
        }
    } catch (json::exception& e) {
        std::cerr << "JSON parsing error: " << e.what() << std::endl;
    }

    file.close();
    return database;
}

void searchActorByName(const std::map<std::string, Movie>& database, const std::string& actorName) {
    std::string lowerSearchName = actorName;
    std::transform(lowerSearchName.begin(), lowerSearchName.end(), lowerSearchName.begin(), ::tolower);

    bool found = false;

    for (const auto& [movieTitle, movie] : database) {
        for (const auto& role : movie.main_cast) {
            std::string lowerActorName = role.actor;
            std::transform(lowerActorName.begin(), lowerActorName.end(), lowerActorName.begin(), ::tolower);

            if (lowerActorName.find(lowerSearchName) != std::string::npos) {
                std::cout << "Movie: " << movieTitle << std::endl;
                std::cout << "Actor: " << role.actor << std::endl;
                std::cout << "Role: " << role.character << std::endl;
                std::cout << "---" << std::endl;
                found = true;
            }
        }
    }

    if (!found) {
        std::cout << "Actor not found in database." << std::endl;
    }
}
