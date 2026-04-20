#pragma once
#include <string>
#include <iostream>

class toy {
public:
    explicit toy(const std::string& name) : name_(name) {}
    ~toy() {
        std::cout << "Toy " << name_ << " was dropped" << std::endl;
    }
    const std::string& getName() const { return name_; }
private:
    std::string name_;
};
