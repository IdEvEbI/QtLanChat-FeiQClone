#include <iostream>

int main() {
    int a = 15;
    int b = 20;

    std::cout << "=== 比较运算 ===" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    
    std::cout << "a > b  : " << (a > b) << std::endl;
    std::cout << "a < b  : " << (a < b) << std::endl;
    std::cout << "a == b : " << (a == b) << std::endl;
    std::cout << "a != b : " << (a != b) << std::endl;
    
    return 0;
}

