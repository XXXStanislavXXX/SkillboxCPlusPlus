#include "../include/Rectangle.h"

Rectangle::Rectangle(double w, double h) : width(w), height(h) {}

double Rectangle::square() {
    return width * height;
}

BoundingBoxDimensions Rectangle::dimensions() {
    return {width, height};
}

std::string Rectangle::type() {
    return "Rectangle";
}
