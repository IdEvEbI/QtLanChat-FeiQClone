// 项目中的实际应用示例
#include <iostream>
#include <string>
#include <vector>

// 用户类
class User {
public:
    std::string name;
    int age;
    bool isOnline;

    // 构造函数
    User(const std::string& userName, int userAge) {
        name = userName;
        age = userAge;
        isOnline = false;
    }

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

// 消息类
class Message {
public:
    std::string sender;
    std::string content;
    int timestamp;

    // 构造函数
    Message(const std::string& from, const std::string& msg) {
        sender = from;
        content = msg;
        timestamp = 1234567890;  // 简化时间戳
    }

    // 成员函数：打印消息
    void printMessage() {
        std::cout << "[" << sender << "]: " << content << std::endl;
    }
};

// 用户管理类
class UserManager {
private:
    std::vector<User> users;

public:
    // 成员函数：添加用户
    void addUser(const std::string& name, int age) {
        users.push_back(User(name, age));
        std::cout << "添加用户: " << name << std::endl;
    }

    // 成员函数：显示所有用户
    void printAllUsers() {
        std::cout << "\n=== 用户列表 ===" << std::endl;
        for (size_t i = 0; i < users.size(); i++) {
            users[i].printInfo();
            std::cout << std::endl;
        }
    }
};

int main() {
    std::cout << "=== QtLanChat 类和对象应用 ===" << std::endl;

    // 创建用户对象
    User user1("张三", 25);
    user1.setOnline(true);
    user1.printInfo();

    // 创建消息对象
    Message msg1("张三", "你好，大家好！");
    msg1.printMessage();

    // 使用用户管理类
    UserManager manager;
    manager.addUser("李四", 30);
    manager.addUser("王五", 28);
    manager.printAllUsers();

    return 0;
}
