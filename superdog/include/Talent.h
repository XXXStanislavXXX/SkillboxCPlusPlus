#pragma once
#include <string>

// Abstract class for a talent
class Talent {
public:
    // Pure virtual function that makes the class abstract
    virtual std::string get_ability() const = 0;
    // Virtual destructor for correct deletion of objects via a base class pointer
    virtual ~Talent() = default;
};
