#include "Database.h"
#include <iostream>
#include <stdexcept>

void Database::addProduct(const std::string& article, int quantity) {
    if (quantity < 0) {
        throw std::invalid_argument("Quantity cannot be negative");
    }
    products[article] = quantity;
}

bool Database::hasProduct(const std::string& article) const {
    return products.find(article) != products.end();
}

int Database::getQuantity(const std::string& article) const {
    auto it = products.find(article);
    if (it == products.end()) {
        throw std::runtime_error("Product not found");
    }
    return it->second;
}

void Database::displayProducts() const {
    std::cout << "\nProduct on storage:\n";
    for (const auto& [article, quantity] : products) {
        std::cout << "Article: " << article << ", Quantity: " << quantity << "\n";
    }
}

void Database::updateQuantity(const std::string& article, int delta) {
    auto it = products.find(article);
    if (it == products.end()) {
        throw std::runtime_error("Product not found");
    }

    int newQuantity = it->second + delta;
    if (newQuantity < 0) {
        throw std::runtime_error("Insufficient quantity");
    }

    it->second = newQuantity;
}

void Database::displayProductQuantity(const std::string& article) const {
    auto it = products.find(article);
    if (it == products.end()) {
        std::cout << "Product with article " << article << " not found\n";
        return;
    }
    std::cout << "Article: " << article << ", On storage: " << it->second << " pc.\n";
}
