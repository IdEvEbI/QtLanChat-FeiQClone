#include <iostream>
#include "math_utils.h"

int main() {
    int a = 10, b = 3;

    std::cout << a << " + " << b << " = " << MathUtils::add(a, b) << std::endl;
    std::cout << a << " - " << b << " = " << MathUtils::subtract(a, b) << std::endl;
    std::cout << a << " * " << b << " = " << MathUtils::multiply(a, b) << std::endl;
    std::cout << a << " / " << b << " = " << MathUtils::divide(a, b) << std::endl;

    return 0;
}

