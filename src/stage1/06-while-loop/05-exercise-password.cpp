#include <iostream>
#include <string>

int main() {
    // 设置密码（实际项目中应加密存储）
    std::string correctPassword = "Hello2025~";
    std::string userPassword;
    int attempts = 0;
    int maxAttempts = 3;

    std::cout << "=== 密码验证系统 ===" << std::endl;

    while (attempts < maxAttempts) {
        std::cout << "请输入密码（剩余" << (maxAttempts - attempts) << "次机会）: ";
        std::cin >> userPassword;

        if (userPassword == correctPassword) {
            std::cout << "密码正确，欢迎！" << std::endl;
            break;  // 密码正确，退出循环
        } else {
            attempts++;
            std::cout << "密码错误，请重试" << std::endl;
        }
    }

    if (attempts >= maxAttempts) {
        std::cout << "密码错误次数过多，程序退出" << std::endl;
    }

    return 0;
}

