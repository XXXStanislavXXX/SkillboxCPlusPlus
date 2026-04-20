#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h);
    double square() override;
    BoundingBoxDimensions dimensions() override;
    std::string type() override;
};

#endif
