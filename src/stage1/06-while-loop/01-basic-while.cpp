// 现代 C++ 示例 - while 循环基础
#include <iostream>

int main() {
    // 示例 1：计数循环
    std::cout << "=== while 计数循环 ===" << std::endl;
    int count = 1;
    while (count <= 5) {
        std::cout << "计数: " << count << std::endl;
        count++;  // 重要：改变条件，避免无限循环
    }

    // 示例 2：用户输入循环
    std::cout << "\n=== while 用户输入循环 ===" << std::endl;
    int number;
    std::cout << "请输入一个正数（输入0退出）: ";
    std::cin >> number;
    
    while (number != 0) {
        std::cout << "你输入的数字是: " << number << std::endl;
        std::cout << "请输入下一个数字（输入0退出）: ";
        std::cin >> number;
    }
    std::cout << "循环已退出" << std::endl;

    // 示例 3：求和循环
    std::cout << "\n=== while 求和循环 ===" << std::endl;
    int sum = 0;
    int num = 1;
    while (num <= 10) {
        sum += num;
        num++;
    }
    std::cout << "1到10的和是: " << sum << std::endl;

    // 示例 4：条件循环（根据布尔值）
    std::cout << "\n=== while 条件循环 ===" << std::endl;
    bool isRunning = true;
    int value = 1;
    while (isRunning) {
        std::cout << value << " ";
        value++;
        if (value > 5) {
            isRunning = false;  // 改变条件，退出循环
        }
    }
    std::cout << std::endl;

    return 0;
}

