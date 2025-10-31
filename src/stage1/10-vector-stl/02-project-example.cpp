// 项目中的实际应用示例
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::cout << "=== QtLanChat 动态用户管理 ===" << std::endl;

    // 使用 vector 存储用户列表
    std::vector<std::string> users;

    // 添加用户
    std::cout << "\n用户上线..." << std::endl;
    users.push_back("张三");
    users.push_back("李四");
    users.push_back("王五");

    std::cout << "当前在线用户数: " << users.size() << std::endl;

    // 显示所有用户
    std::cout << "在线用户列表：" << std::endl;
    for (size_t i = 0; i < users.size(); i++) {
        std::cout << (i + 1) << ". " << users[i] << std::endl;
    }

    // 用户下线（简化为删除最后一个）
    std::cout << "\n王五下线了" << std::endl;
    users.pop_back();

    std::cout << "当前在线用户数: " << users.size() << std::endl;
    std::cout << "剩余用户：" << std::endl;
    for (size_t i = 0; i < users.size(); i++) {
        std::cout << (i + 1) << ". " << users[i] << std::endl;
    }

    return 0;
}

