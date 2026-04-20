#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

#include <string>
#include <map>

// Reads arguments from user until "post" or "get" is entered
std::map<std::string, std::string> readArguments();

// Executes POST request with arguments
std::string executePostRequest(const std::map<std::string, std::string>& arguments);

// Executes GET request with arguments
std::string executeGetRequest(const std::map<std::string, std::string>& arguments);

// Builds URL parameter string
std::string buildUrlParams(const std::map<std::string, std::string>& arguments);

#endif // HTTP_REQUEST_H
