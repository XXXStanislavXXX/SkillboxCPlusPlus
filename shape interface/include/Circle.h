#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
private:
    double radius;
public:
    explicit Circle(double r);
    double square() override;
    BoundingBoxDimensions dimensions() override;
    std::string type() override;
};

#endif
