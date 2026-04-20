#include "http_client.h"
#include <iostream>
#include <limits>
#include <string>

int main() {
    std::cout << "HTTP Client\n";
    std::cout << "Available commands: get, post, put, delete, patch, exit\n";

    while (true) {
        std::cout << "\nEnter command: ";
        std::string command;
        std::cin >> command;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (command == "exit") {
            std::cout << "Exiting...\n";
            break;
        }
        else if (command == "get") {
            executeGetRequest();
        }
        else if (command == "post") {
            executePostRequest();
        }
        else if (command == "put") {
            executePutRequest();
        }
        else if (command == "delete") {
            executeDeleteRequest();
        }
        else if (command == "patch") {
            executePatchRequest();
        }
        else {
            std::cout << "Unknown command. Try: get, post, put, delete, patch, exit\n";
        }
    }

    return 0;
}
