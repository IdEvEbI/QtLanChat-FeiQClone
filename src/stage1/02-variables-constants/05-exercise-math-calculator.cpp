// 练习 2：简单数学计算
#include <iostream>

int main() {
    // 定义变量
    int a = 15;
    int b = 3;

    // 计算结果
    int sum = a + b;
    int diff = a - b;
    int product = a * b;
    int quotient = a / b;

    // 输出结果
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "加法: " << a << " + " << b << " = " << sum << std::endl;
    std::cout << "减法: " << a << " - " << b << " = " << diff << std::endl;
    std::cout << "乘法: " << a << " * " << b << " = " << product << std::endl;
    std::cout << "除法: " << a << " / " << b << " = " << quotient << std::endl;

    return 0;
}