#include "http_request.h"
#include <iostream>

int main() {
    auto arguments = readArguments();

    std::string method = arguments["__method__"];
    std::string response;

    if (method == "post") {
        std::cout << "\nExecuting POST request...\n\n";
        response = executePostRequest(arguments);
    } else if (method == "get") {
        std::cout << "\nExecuting GET request...\n\n";
        response = executeGetRequest(arguments);
    }

    std::cout << "Server response:\n";
    std::cout << response << std::endl;

    return 0;
}
