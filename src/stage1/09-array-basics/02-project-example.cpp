#include <iostream>
#include <string>

int main() {
    std::cout << "=== QtLanChat 用户管理系统 ===" << std::endl;

    // 用户列表（假设最多 10 个用户）
    std::string users[10];
    int userCount = 0;

    // 添加用户
    std::cout << "\n正在添加用户..." << std::endl;
    users[0] = "张三";
    users[1] = "李四";
    users[2] = "王五";
    userCount = 3;

    std::cout << "当前在线用户数: " << userCount << std::endl;

    // 遍历并显示所有用户
    std::cout << "\n在线用户列表：" << std::endl;
    for (int i = 0; i < userCount; i++) {
        std::cout << (i + 1) << ". " << users[i] << std::endl;
    }

    // 添加新用户
    std::cout << "\n添加新用户: 赵六" << std::endl;
    users[userCount] = "赵六";  // 添加到下一个位置
    userCount++;                 // 用户数加 1

    std::cout << "更新后的用户列表：" << std::endl;
    for (int i = 0; i < userCount; i++) {
        std::cout << (i + 1) << ". " << users[i] << std::endl;
    }

    return 0;
}
