// 现代 C++ 示例 - 变量和常量基础
#include <iostream>
#include <string>

int main() {
    // 变量声明和初始化
    int age = 25;
    double height = 1.75;
    std::string name = "张三";

    // 常量定义
    const double PI = 3.14159;
    const int MAX_USERS = 100;

    // 输出变量值
    std::cout << "姓名: " << name << std::endl;
    std::cout << "年龄: " << age << std::endl;
    std::cout << "身高: " << height << "米" << std::endl;
    std::cout << "圆周率: " << PI << std::endl;
    std::cout << "最大用户数: " << MAX_USERS << std::endl;

    return 0;
}
