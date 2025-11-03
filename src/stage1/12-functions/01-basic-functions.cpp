// 现代 C++ 示例 - 函数基础
#include <iostream>
#include <string>

// 示例 1：无参数、无返回值的函数
void greet() {
    std::cout << "Hello, World!" << std::endl;
}

// 示例 2：有参数、有返回值的函数
int add(int a, int b) {
    return a + b;
}

// 示例 3：计算两个数的最大值
int getMax(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// 示例 4：字符串处理函数
std::string formatMessage(std::string name, std::string message) {
    return name + ": " + message;
}

// 示例 5：无参数、有返回值的函数
int getTen() {
    return 10;
}

int main() {
    // 示例 1：调用无参数函数
    std::cout << "=== 无参数函数 ===" << std::endl;
    greet();
    greet();  // 可以重复调用

    // 示例 2：调用有参数函数
    std::cout << "\n=== 有参数函数 ===" << std::endl;
    int sum = add(5, 3);
    std::cout << "5 + 3 = " << sum << std::endl;

    int result = add(10, 20);
    std::cout << "10 + 20 = " << result << std::endl;

    // 示例 3：使用返回值
    std::cout << "\n=== 使用返回值 ===" << std::endl;
    int maximum = getMax(7, 12);
    std::cout << "getMax(7, 12) = " << maximum << std::endl;

    // 示例 4：字符串函数
    std::cout << "\n=== 字符串函数 ===" << std::endl;
    std::string formatted = formatMessage("张三", "你好");
    std::cout << formatted << std::endl;

    // 示例 5：直接使用返回值
    std::cout << "\n=== 直接使用返回值 ===" << std::endl;
    std::cout << "getTen() = " << getTen() << std::endl;

    return 0;
}

