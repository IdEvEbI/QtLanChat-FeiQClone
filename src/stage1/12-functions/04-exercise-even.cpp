#include <iostream>

bool isEven(int number) {
    return number % 2 == 0;
}

int main() {
    std::cout << "5 是偶数吗? " << (isEven(5) ? "是" : "否") << std::endl;
    std::cout << "8 是偶数吗? " << (isEven(8) ? "是" : "否") << std::endl;
    return 0;
}

