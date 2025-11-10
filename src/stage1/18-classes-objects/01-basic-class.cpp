// 现代 C++ 示例 - 类和对象基础
#include <iostream>
#include <string>

// 定义用户类
class User {
public:
    // 成员变量
    std::string name;
    int age;
    bool isOnline;

    // 成员函数：打印用户信息
    void printInfo() {
        std::cout << "=== 用户信息 ===" << std::endl;
        std::cout << "姓名: " << name << std::endl;
        std::cout << "年龄: " << age << std::endl;
        std::cout << "在线状态: " << (isOnline ? "在线" : "离线") << std::endl;
    }

    // 成员函数：设置在线状态
    void setOnline(bool status) {
        isOnline = status;
        std::cout << name << " 的状态已更新为: " << (status ? "在线" : "离线") << std::endl;
    }
};

int main() {
    // 创建对象
    User user1;

    // 设置成员变量
    user1.name = "张三";
    user1.age = 25;
    user1.isOnline = true;

    // 调用成员函数
    user1.printInfo();

    // 修改状态
    user1.setOnline(false);
    user1.printInfo();

    return 0;
}
