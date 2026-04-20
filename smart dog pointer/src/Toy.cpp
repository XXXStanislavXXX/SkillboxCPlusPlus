#include "Toy.h"
#include <iostream>

Toy::Toy(const std::string& name) {
    name_ = name;
}

std::string Toy::getName() {
    return name_;
}

Toy::~Toy() {
    std::cout << "Toy " << name_ << " was dropped " << std::endl;
}
