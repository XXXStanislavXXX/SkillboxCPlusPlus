#include "http_client.h"
#include <cpr/cpr.h>
#include <iostream>
#include <limits>

void executeGetRequest() {
    auto response = cpr::Get(cpr::Url{"https://httpbin.org/get"});
    std::cout << "Status code: " << response.status_code << std::endl;
    std::cout << "Response:\n" << response.text << std::endl;
}

void executePostRequest() {
    std::string body;
    std::cout << "Enter request body (e.g., key=value or JSON): ";
    std::getline(std::cin, body);

    std::string contentType;
    std::cout << "Enter Content-Type (press Enter for 'application/x-www-form-urlencoded'): ";
    std::getline(std::cin, contentType);
    if (contentType.empty()) {
        contentType = "application/x-www-form-urlencoded";
    }

    auto response = cpr::Post(
        cpr::Url{"https://httpbin.org/post"},
        cpr::Body{body},
        cpr::Header{{"Content-Type", contentType}}
    );
    std::cout << "Status code: " << response.status_code << std::endl;
    std::cout << "Response:\n" << response.text << std::endl;
}

void executePutRequest() {
    std::string body;
    std::cout << "Enter request body: ";
    std::getline(std::cin, body);

    auto response = cpr::Put(
        cpr::Url{"https://httpbin.org/put"},
        cpr::Body{body}
    );
    std::cout << "Status code: " << response.status_code << std::endl;
    std::cout << "Response:\n" << response.text << std::endl;
}

void executeDeleteRequest() {
    auto response = cpr::Delete(cpr::Url{"https://httpbin.org/delete"});
    std::cout << "Status code: " << response.status_code << std::endl;
    std::cout << "Response:\n" << response.text << std::endl;
}

void executePatchRequest() {
    std::string body;
    std::cout << "Enter request body: ";
    std::getline(std::cin, body);

    auto response = cpr::Patch(
        cpr::Url{"https://httpbin.org/patch"},
        cpr::Body{body}
    );
    std::cout << "Status code: " << response.status_code << std::endl;
    std::cout << "Response:\n" << response.text << std::endl;
}
