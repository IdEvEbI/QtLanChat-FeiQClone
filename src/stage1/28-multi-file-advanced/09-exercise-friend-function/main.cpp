#include <iostream>
#include "rectangle.h"

int main() {
    Rectangle r1(3.0, 4.0);
    Rectangle r2(5.0, 6.0);

    std::cout << "矩形 1 面积: " << r1.getArea() << std::endl;
    std::cout << "矩形 2 面积: " << r2.getArea() << std::endl;
    std::cout << "总面积: " << calculateTotalArea(r1, r2) << std::endl;

    return 0;
}

