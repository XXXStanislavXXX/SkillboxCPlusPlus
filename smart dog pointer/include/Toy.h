#ifndef TOY_H
#define TOY_H

#include <string>

class Toy {
public:
    Toy(const std::string& name);
    std::string getName();
    ~Toy();
private:
    std::string name_;
};

#endif