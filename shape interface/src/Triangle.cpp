#include "../include/Triangle.h"
#include <cmath>

Triangle::Triangle(double sideA, double sideB, double sideC) 
    : a(sideA), b(sideB), c(sideC) {}

double Triangle::square() {
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

BoundingBoxDimensions Triangle::dimensions() {
    double p = (a + b + c) / 2.0;
    double radius = (a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c)));
    double side = 2 * radius;
    return {side, side};
}

std::string Triangle::type() {
    return "Triangle";
}
