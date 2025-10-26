#include <iostream>

int main() {
    int number = -5;

    if (number > 0) {
        std::cout << "正数" << std::endl;
    } else if (number < 0) {
        std::cout << "负数" << std::endl;
    } else {
        std::cout << "零" << std::endl;
    }

    return 0;
}

