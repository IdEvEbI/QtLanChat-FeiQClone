#include <iostream>

int main() {
    std::cout << "=== 类型转换示例 ===" << std::endl;

    // 隐式转换
    int a = 10;
    double b = a;  // int 转 double
    std::cout << "隐式转换: int(" << a << ") -> double(" << b << ")" << std::endl;

    // 显式转换 - 测试不同转换方式
    double pi = 3.14159;
    int truncated = (int)pi;                    // C风格转换
    std::cout << "原始值: " << pi << std::endl;
    std::cout << "C风格转换（截断）: " << truncated << std::endl;

    // 字符转换
    char grade = 'A';
    int ascii = (int)grade;
    std::cout << "字符 '" << grade << "' 的ASCII码: " << ascii << std::endl;

    return 0;
}

