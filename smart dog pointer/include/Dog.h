#ifndef DOG_H
#define DOG_H

#include <memory>
#include "Toy.h"

class Dog {
public:
    void getToy(std::shared_ptr<Toy> toy);
    void dropToy();
private:
    std::shared_ptr<Toy> toy_;
};

#endif
