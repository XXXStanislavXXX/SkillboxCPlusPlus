#include <iostream>
#include "include/Circle.h"
#include "include/Rectangle.h"
#include "include/Triangle.h"

int main() {
    std::cout << "Choose a figure (Triangle, Circle, Rectangle):" << std::endl;
    std::string figure;
    std::cin >> figure;

    if (figure == "Triangle") {
        std::cout << "Enter size of side A, B, C: ";
        int a, b, c;
        std::cin >> a >> b >> c;
        Triangle t(a, b, c);
        printParams(&t);
        std::cout << std::endl;
    }

    if (figure == "Circle") {
        std::cout << "Enter radious ";
        int r;
        std::cin >> r;
        Circle c(r);
        printParams(&c);
        std::cout << std::endl;
    }

    if (figure == "Rectangle") {

        std::cout << "Enter width and hight w, h: ";
        int w, h;
        std::cin >> w >> h;
        Rectangle r(w, h);
        printParams(&r);
    }

    return 0;
}