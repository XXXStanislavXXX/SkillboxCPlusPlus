#ifndef DATABASE_H
#define DATABASE_H

#include <map>
#include <string>

class Database {
private:
    std::map<std::string, int> products;

public:
    void addProduct(const std::string& article, int quantity);
    bool hasProduct(const std::string& article) const;
    int getQuantity(const std::string& article) const;
    void displayProducts() const;
    void displayProductQuantity(const std::string& article) const;
    void updateQuantity(const std::string& article, int delta);

};

#endif
