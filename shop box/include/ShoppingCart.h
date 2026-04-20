#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include <map>
#include <string>
#include "Database.h"

class ShoppingCart {
private:
    std::map<std::string, int> cart;
    Database& database;

public:
    explicit ShoppingCart(Database& db);
    void add(const std::string& article, int quantity);
    void remove(const std::string& article, int quantity);
    void displayCart() const;
};

#endif
