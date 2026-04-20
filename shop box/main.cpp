#include <iostream>
#include <string>
#include "Database.h"
#include "ShoppingCart.h"

int main() {
    Database db;

    int productCount;
    std::cout << "Enter product quantity: ";
    std::cin >> productCount;

    for (int i = 0; i < productCount; ++i) {
        std::string article;
        int quantity;
        std::cout << "Product article: ";
        std::cin >> article;
        std::cout << "Quantity: ";
        std::cin >> quantity;

        try {
            db.addProduct(article, quantity);
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
            --i;
        }
    }

    db.displayProducts();
    ShoppingCart cart(db);

    std::string command;
    while (true) {
        std::cout << "\nEnter command (add/remove/show/stock/exit): ";
        std::cin >> command;

        if (command == "exit") break;

        if (command == "show") {
            cart.displayCart();
            continue;
        }

        if (command == "stock") {
            std::cout << "Enter article or * for all: ";
            std::string article;
            std::cin >> article;
            if (article == "*") {
                db.displayProducts();
            } else {
                db.displayProductQuantity(article);
            }
            continue;
        }

        std::string article;
        int quantity;
        std::cout << "Article: ";
        std::cin >> article;
        std::cout << "Quantity: ";
        std::cin >> quantity;

        try {
            if (command == "add") {
                cart.add(article, quantity);
            } else if (command == "remove") {
                cart.remove(article, quantity);
            } else {
                std::cout << "Command unnown\n";
            }
        } catch (const std::invalid_argument& e) {
            std::cerr << "Enter error: " << e.what() << "\n";
        } catch (const std::runtime_error& e) {
            std::cerr << "Runtime Error: " << e.what() << "\n";
        }
    }


    return 0;
}
