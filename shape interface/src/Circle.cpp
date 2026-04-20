#include "../include/Circle.h"
#include <cmath>

Circle::Circle(double r) : radius(r) {}

double Circle::square() {
    return M_PI * radius * radius;
}

BoundingBoxDimensions Circle::dimensions() {
    double diameter = 2 * radius;
    return {diameter, diameter};
}

std::string Circle::type() {
    return "Circle";
}
