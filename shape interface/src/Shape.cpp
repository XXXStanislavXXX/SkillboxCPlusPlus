#include "../include/Shape.h"
#include <iostream>

void printParams(Shape* shape) {
    std::cout << "Type: " << shape->type() << std::endl;
    std::cout << "Square: " << shape->square() << std::endl;
    BoundingBoxDimensions dim = shape->dimensions();
    std::cout << "Width: " << dim.width << std::endl;
    std::cout << "Height: " << dim.height << std::endl;
}
