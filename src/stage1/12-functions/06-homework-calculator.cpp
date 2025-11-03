#include <iostream>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

double divide(int a, int b) {
    if (b == 0) {
        std::cout << "错误：除数不能为 0" << std::endl;
        return 0.0;
    }
    return static_cast<double>(a) / b;
}

int main() {
    int num1 = 10;
    int num2 = 3;

    std::cout << "=== 简单计算器 ===" << std::endl;
    std::cout << num1 << " + " << num2 << " = " << add(num1, num2) << std::endl;
    std::cout << num1 << " - " << num2 << " = " << subtract(num1, num2) << std::endl;
    std::cout << num1 << " * " << num2 << " = " << multiply(num1, num2) << std::endl;
    std::cout << num1 << " / " << num2 << " = " << divide(num1, num2) << std::endl;

    // 测试除零
    std::cout << "\n测试除零：" << std::endl;
    divide(10, 0);

    return 0;
}

