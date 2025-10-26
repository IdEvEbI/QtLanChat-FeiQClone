#include <iostream>

int main() {
    int value = 10;
    
    std::cout << "=== 复合赋值运算 ===" << std::endl;
    std::cout << "初始值: " << value << std::endl;
    
    value += 5;  // value = value + 5
    std::cout << "value += 5: " << value << std::endl;
    
    value -= 3;  // value = value - 3
    std::cout << "value -= 3: " << value << std::endl;
    
    value *= 2;  // value = value * 2
    std::cout << "value *= 2: " << value << std::endl;
    
    value /= 3;  // value = value / 3
    std::cout << "value /= 3: " << value << std::endl;
    
    return 0;
}

