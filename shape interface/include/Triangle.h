#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
private:
    double a, b, c;
public:
    Triangle(double sideA, double sideB, double sideC);
    double square() override;
    BoundingBoxDimensions dimensions() override;
    std::string type() override;
};

#endif
