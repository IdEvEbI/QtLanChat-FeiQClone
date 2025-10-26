// 现代 C++ 示例 - 运算符基础
#include <iostream>

int main() {
    // 算术运算符
    int a = 10, b = 3;
    std::cout << "=== 算术运算符 ===" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "a - b = " << (a - b) << std::endl;
    std::cout << "a * b = " << (a * b) << std::endl;
    std::cout << "a / b = " << (a / b) << std::endl;
    std::cout << "a % b = " << (a % b) << std::endl;

    // 赋值运算符
    int c = 5;
    std::cout << "\n=== 赋值运算符 ===" << std::endl;
    std::cout << "原始 c = " << c << std::endl;
    c += 3;  // c = c + 3
    std::cout << "c += 3, c = " << c << std::endl;
    c *= 2;  // c = c * 2
    std::cout << "c *= 2, c = " << c << std::endl;

    // 比较运算符
    std::cout << "\n=== 比较运算符 ===" << std::endl;
    bool result1 = (a > b);
    bool result2 = (a == b);
    std::cout << "a > b  : " << result1 << std::endl;
    std::cout << "a == b : " << result2 << std::endl;

    // 逻辑运算符
    std::cout << "\n=== 逻辑运算符 ===" << std::endl;
    bool x = true, y = false;
    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "x && y = " << (x && y) << std::endl;
    std::cout << "x || y = " << (x || y) << std::endl;
    std::cout << "!x = " << (!x) << std::endl;

    return 0;
}

