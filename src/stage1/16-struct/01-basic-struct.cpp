// 现代 C++ 示例 - 结构体基础
#include <iostream>
#include <string>

// 定义用户信息结构体
struct User {
    std::string name;
    int age;
    bool isOnline;
};

int main() {
    // 声明结构体变量
    User user1;

    // 设置成员变量的值
    user1.name = "张三";
    user1.age = 25;
    user1.isOnline = true;

    // 访问并输出成员变量
    std::cout << "=== 用户信息 ===" << std::endl;
    std::cout << "姓名: " << user1.name << std::endl;
    std::cout << "年龄: " << user1.age << std::endl;
    std::cout << "在线状态: " << (user1.isOnline ? "在线" : "离线") << std::endl;

    // 创建另一个用户
    User user2;
    user2.name = "李四";
    user2.age = 30;
    user2.isOnline = false;

    std::cout << "\n=== 用户 2 信息 ===" << std::endl;
    std::cout << "姓名: " << user2.name << std::endl;
    std::cout << "年龄: " << user2.age << std::endl;
    std::cout << "在线状态: " << (user2.isOnline ? "在线" : "离线") << std::endl;

    return 0;
}
