#pragma once
#include "Talent.h"

// Swimming talent
class Swimming : public Talent {
public:
    std::string get_ability() const override;
};

// Dancing talent
class Dancing : public Talent {
public:
    std::string get_ability() const override;
};

// Counting talent
class Counting : public Talent {
public:
    std::string get_ability() const override;
};
