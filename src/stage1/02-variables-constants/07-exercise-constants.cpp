// 练习 4：常量使用
#include <iostream>

int main() {
    // 系统配置常量
    const int MAX_USERS = 1000;
    const double TAX_RATE = 0.1;
    const std::string APP_NAME = "QtLanChat";

    // 使用常量进行计算
    int currentUsers = 150;
    double revenue = 5000.0;
    double tax = revenue * TAX_RATE;

    // 输出信息
    std::cout << "应用名称: " << APP_NAME << std::endl;
    std::cout << "最大用户数: " << MAX_USERS << std::endl;
    std::cout << "当前用户数: " << currentUsers << std::endl;
    std::cout << "收入: " << revenue << "元" << std::endl;
    std::cout << "税费: " << tax << "元" << std::endl;

    // 错误示例：不能修改常量
    // MAX_USERS = 2000;  // 编译错误！

    return 0;
}