#include <iostream>
#include <memory>
#include "Dog.h"
#include "Toy.h"

int main() {
    auto toy = std::make_shared<Toy>("Ball");

    Dog dog1, dog2;

    dog1.getToy(toy);  // Dog gets the toy
    dog1.getToy(toy);  // "I already have this toy"
    dog2.getToy(toy);  // "Another dog is playing with this toy"

    dog1.dropToy();    // Dog drops the toy
    dog2.getToy(toy);  // Dog 2 gets the toy
    dog2.dropToy();    // Dog 2 drops the toy
    dog1.dropToy();    // "Nothing to drop"

    return 0;
}
