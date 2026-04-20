#include "Dog.h"
#include <iostream>

// Constructor implementation
Dog::Dog(const std::string& name) : name(name) {}

// Method to add a talent to the vector of talents
void Dog::add_talent(const std::shared_ptr<Talent>& talent) {
    talents.push_back(talent);
}

// Method to display all the dog's talents
void Dog::show_talents() const {
    std::cout << "This is " << name << " and it has some talents:" << std::endl;
    for (const auto& talent : talents) {
        std::cout << "\tIt can \"" << talent->get_ability() << "\"" << std::endl;
    }
}
