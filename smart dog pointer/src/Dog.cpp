#include "Dog.h"
#include <iostream>

void Dog::getToy(std::shared_ptr<Toy> toy) {
    if (toy_ && toy_.get() == toy.get()) {
        std::cout << "I already have this toy" << std::endl;
        return;
    }

    // use_count включает: 1) владелец снаружи, 2) параметр функции
    // Если > 2, значит игрушка у другой собаки
    if (toy.use_count() > 2) {
        std::cout << "Another dog is playing with this toy" << std::endl;
        return;
    }

    toy_ = toy;
}

void Dog::dropToy() {
    if (!toy_) {
        std::cout << "Nothing to drop" << std::endl;
        return;
    }
    toy_.reset();
}
