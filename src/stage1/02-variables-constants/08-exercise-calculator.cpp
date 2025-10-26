// 练习 5：综合计算器应用
#include <iostream>
#include <iomanip>

int main() {
    // 计算精度常量
    const int PRECISION = 2;

    // 操作数变量
    double num1 = 10.5;
    double num2 = 3.2;

    // 计算结果
    double sum = num1 + num2;
    double diff = num1 - num2;
    double product = num1 * num2;
    double quotient = num1 / num2;

    // 设置输出精度
    std::cout << std::fixed << std::setprecision(PRECISION);

    // 输出结果
    std::cout << "=== 简单计算器 ===" << std::endl;
    std::cout << "操作数1: " << num1 << std::endl;
    std::cout << "操作数2: " << num2 << std::endl;
    std::cout << "加法: " << num1 << " + " << num2 << " = " << sum << std::endl;
    std::cout << "减法: " << num1 << " - " << num2 << " = " << diff << std::endl;
    std::cout << "乘法: " << num1 << " * " << num2 << " = " << product << std::endl;
    std::cout << "除法: " << num1 << " / " << num2 << " = " << quotient << std::endl;

    return 0;
}