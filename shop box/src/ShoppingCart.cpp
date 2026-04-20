#include "ShoppingCart.h"
#include <iostream>
#include <stdexcept>

ShoppingCart::ShoppingCart(Database& db) : database(db) {}

void ShoppingCart::add(const std::string& article, int quantity) {
    if (quantity <= 0) {
        throw std::invalid_argument("Quantity must be greater than 0");
    }

    if (!database.hasProduct(article)) {
        throw std::invalid_argument("Product not found");
    }

    int available = database.getQuantity(article);

    if (quantity > available) {
        throw std::runtime_error("Insufficient quantity available: "
                                + std::to_string(available) + " pc.");
    }

    database.updateQuantity(article, -quantity);
    cart[article] += quantity;

    std::cout << "Added " << quantity << " product pc. " << article
              << ". Added to cart: " << cart[article] << " pcs.\n";
}


void ShoppingCart::remove(const std::string& article, int quantity) {
    if (quantity <= 0) {
        throw std::invalid_argument("Quantity must be greater than 0");
    }

    auto it = cart.find(article);
    if (it == cart.end()) {
        throw std::invalid_argument("Product not found");
    }

    if (it->second < quantity) {
        throw std::runtime_error("Insufficient quantity available: "
                                + std::to_string(it->second) + " шт.");
    }

    database.updateQuantity(article, quantity);
    it->second -= quantity;

    std::cout << "Deleted " << quantity << " Product pcs " << article;

    if (it->second == 0) {
        cart.erase(it);
        std::cout << ". Product completely deleted\n";
    } else {
        std::cout << ". Left in cart: " << it->second << " pcs.\n";
    }
}

void ShoppingCart::displayCart() const {
    if (cart.empty()) {
        std::cout << "\nCart is emply\n";
        return;
    }

    std::cout << "\nIn cart:\n";
    for (const auto& [article, quantity] : cart) {
        std::cout << "Article: " << article << ", Quantity: " << quantity << "\n";
    }
}
