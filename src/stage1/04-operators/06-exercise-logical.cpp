#include <iostream>

int main() {
    bool condition1 = true;
    bool condition2 = false;
    
    std::cout << "=== 逻辑运算 ===" << std::endl;
    std::cout << "condition1 = " << condition1 << std::endl;
    std::cout << "condition2 = " << condition2 << std::endl;
    
    std::cout << "condition1 && condition2: " << (condition1 && condition2) << std::endl;
    std::cout << "condition1 || condition2: " << (condition1 || condition2) << std::endl;
    std::cout << "!condition1: " << (!condition1) << std::endl;
    
    return 0;
}

