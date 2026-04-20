#include "Dog.h"
#include "SpecificTalents.h"
#include <memory>

int main() {
    // Create a dog named Steve
    Dog dog1("Steve");

    // Add the ability to dance and swim
    dog1.add_talent(std::make_shared<Dancing>());
    dog1.add_talent(std::make_shared<Swimming>());

    // Show the dog's talents
    dog1.show_talents();

    return 0;
}
