// 现代 C++ 示例 - 分支结构基础
#include <iostream>
#include <string>

int main() {
    // 单分支 - if
    std::cout << "=== 单分支 if ===" << std::endl;
    int temp = 30;
    if (temp > 25) {
        std::cout << "今天很热，建议少穿点" << std::endl;
    }

    // 双分支 - if-else
    std::cout << "\n=== 双分支 if-else ===" << std::endl;
    int age = 18;
    if (age >= 18) {
        std::cout << "已成年" << std::endl;
    } else {
        std::cout << "未成年" << std::endl;
    }

    // 多分支 - if-else if-else
    std::cout << "\n=== 多分支 if-else if-else ===" << std::endl;
    int score = 85;
    if (score >= 90) {
        std::cout << "优秀" << std::endl;
    } else if (score >= 80) {
        std::cout << "良好" << std::endl;
    } else if (score >= 60) {
        std::cout << "及格" << std::endl;
    } else {
        std::cout << "不及格" << std::endl;
    }

    // 嵌套分支
    std::cout << "\n=== 嵌套分支 ===" << std::endl;
    bool isVip = true;
    int userAge = 20;
    if (userAge >= 18) {
        if (isVip) {
            std::cout << "成年VIP用户，可以访问所有功能" << std::endl;
        } else {
            std::cout << "成年普通用户，可以访问基本功能" << std::endl;
        }
    } else {
        std::cout << "未成年用户，访问受限" << std::endl;
    }

    // 三元运算符
    std::cout << "\n=== 三元运算符 ===" << std::endl;
    int a = 10;
    int b = 20;
    int maxValue = (a > b) ? a : b;  // 如果 a > b 返回 a，否则返回 b
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "最大值: " << maxValue << std::endl;

    std::string status = (userAge >= 18) ? "已成年" : "未成年";  // 字符串三元表达式
    std::cout << "状态: " << status << std::endl;

    return 0;
}

