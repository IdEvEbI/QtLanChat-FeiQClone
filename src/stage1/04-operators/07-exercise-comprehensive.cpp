#include <iostream>

int main() {
    std::cout << "=== 综合练习：简单计算器 ===" << std::endl;

    int num1 = 15;
    int num2 = 3;

    // 算术运算
    int sum = num1 + num2;
    int product = num1 * num2;
    
    std::cout << "num1 = " << num1 << ", num2 = " << num2 << std::endl;
    std::cout << "sum = " << sum << ", product = " << product << std::endl;
    
    // 比较运算
    bool isSumGreater = (sum > product);
    std::cout << "sum > product: " << isSumGreater << std::endl;
    
    // 逻辑运算
    bool complex = (num1 > 10) && (num2 < 5);
    std::cout << "(num1 > 10) && (num2 < 5): " << complex << std::endl;
    
    return 0;
}

