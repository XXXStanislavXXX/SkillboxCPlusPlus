#ifndef SHAPE_H
#define SHAPE_H

#include <string>

struct BoundingBoxDimensions {
    double width;
    double height;
};

class Shape {
public:
    virtual ~Shape() = default;
    virtual double square() = 0;
    virtual BoundingBoxDimensions dimensions() = 0;
    virtual std::string type() = 0;
};

void printParams(Shape* shape);

#endif
