// 项目中的实际应用示例
#include <iostream>

int main() {
    std::cout << "=== QtLanChat 用户验证系统 ===" << std::endl;
    
    int correctPassword = 1234;
    int userInput;
    int attempts = 0;
    int maxAttempts = 3;
    
    // 密码验证循环
    while (attempts < maxAttempts) {
        std::cout << "请输入密码（剩余次数: " << (maxAttempts - attempts) << "）: ";
        userInput = 1234;  // 模拟用户输入
        
        if (userInput == correctPassword) {
            std::cout << "登录成功！" << std::endl;
            break;  // 密码正确，跳出循环
        } else {
            attempts++;
            std::cout << "密码错误！" << std::endl;
        }
    }
    
    if (attempts >= maxAttempts) {
        std::cout << "登录失败，已达到最大尝试次数！" << std::endl;
    }
    
    return 0;
}

