#include "http_request.h"
#include <cpr/cpr.h>
#include <iostream>
#include <vector>

std::map<std::string, std::string> readArguments() {
    std::map<std::string, std::string> arguments;
    std::string key, value;

    std::cout << "Enter arguments (name and value).\n";
    std::cout << "To finish, enter 'post' or 'get' as the name.\n";

    while (true) {
        std::cout << "Argument name: ";
        std::cin >> key;

        if (key == "post" || key == "get") {
            arguments["__method__"] = key;
            break;
        }

        std::cout << "Argument value: ";
        std::cin >> value;

        arguments[key] = value;
    }

    return arguments;
}

std::string executePostRequest(const std::map<std::string, std::string>& arguments) {
    std::vector<cpr::Pair> pairs;

    for (auto it = arguments.begin(); it != arguments.end(); ++it) {
        if (it->first != "__method__") {
            pairs.push_back(cpr::Pair(std::string(it->first), std::string(it->second)));
        }
    }

    cpr::Response response = cpr::Post(
        cpr::Url{"https://httpbin.org/post"},
        cpr::Payload(pairs.begin(), pairs.end())
    );

    return response.text;
}

std::string executeGetRequest(const std::map<std::string, std::string>& arguments) {
    std::string url = "https://httpbin.org/get";
    std::string params = buildUrlParams(arguments);

    if (!params.empty()) {
        url += "?" + params;
    }

    cpr::Response response = cpr::Get(cpr::Url{url});

    return response.text;
}

std::string buildUrlParams(const std::map<std::string, std::string>& arguments) {
    std::string params;
    bool first = true;

    for (auto it = arguments.begin(); it != arguments.end(); ++it) {
        if (it->first != "__method__") {
            if (!first) {
                params += "&";
            }
            params += it->first + "=" + it->second;
            first = false;
        }
    }

    return params;
}
