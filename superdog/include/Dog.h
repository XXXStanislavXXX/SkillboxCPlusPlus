#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Talent.h"

class Dog {
private:
    std::string name;
    std::vector<std::shared_ptr<Talent>> talents;

public:
    // Constructor
    Dog(const std::string& name);

    // Method to add a talent
    void add_talent(const std::shared_ptr<Talent>& talent);

    // Method to show all talents
    void show_talents() const;
};
