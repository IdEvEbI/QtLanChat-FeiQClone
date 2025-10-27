// 现代 C++ 示例 - for 循环基础
#include <iostream>

int main() {
    // 示例 1：简单计数循环
    std::cout << "=== for 简单计数循环 ===" << std::endl;
    for (int i = 1; i <= 5; i++) {
        std::cout << "计数: " << i << std::endl;
    }

    // 示例 2：倒序循环
    std::cout << "\n=== for 倒序循环 ===" << std::endl;
    for (int i = 5; i >= 1; i--) {
        std::cout << "倒计时: " << i << std::endl;
    }

    // 示例 3：字符串打印
    std::cout << "\n=== for 字符串打印 ===" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "Hello ";
    }
    std::cout << std::endl;

    // 示例 4：跳跃式循环（步长为2）
    std::cout << "\n=== for 跳跃式循环（步长2）===" << std::endl;
    for (int i = 0; i <= 10; i += 2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // 示例 5：求和循环
    std::cout << "\n=== for 求和循环 ===" << std::endl;
    int sum = 0;
    for (int i = 1; i <= 10; i++) {
        sum += i;
    }
    std::cout << "1到10的和是: " << sum << std::endl;

    // 示例 6：嵌套循环（3x3 乘法表）
    std::cout << "\n=== for 嵌套循环（3x3 乘法表）===" << std::endl;
    for (int i = 1; i <= 3; i++) {       // 外层循环：行
        for (int j = 1; j <= 3; j++) {   // 内层循环：列
            std::cout << i << " x " << j << " = " << (i * j) << "\t";
        }
        std::cout << std::endl;  // 换行
    }

    return 0;
}

