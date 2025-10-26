// 练习 1：个人信息存储
#include <iostream>
#include <string>

int main() {
    // 个人信息变量
    std::string name = "小美";
    int age = 19;
    double height = 1.68;

    // 数学常量
    const double PI = 3.14159;
    const double E = 2.71828;

    // 输出信息
    std::cout << "=== 个人信息 ===" << std::endl;
    std::cout << "姓名: " << name << std::endl;
    std::cout << "年龄: " << age << "岁" << std::endl;
    std::cout << "身高: " << height << "米" << std::endl;
    std::cout << "圆周率: " << PI << std::endl;
    std::cout << "自然常数: " << E << std::endl;

    return 0;
}