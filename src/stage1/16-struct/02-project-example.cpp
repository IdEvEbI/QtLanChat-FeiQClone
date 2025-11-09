// 项目中的实际应用示例
#include <iostream>
#include <string>
#include <vector>

// 用户信息结构体
struct User {
    std::string name;
    int age;
    bool isOnline;
};

// 消息结构体
struct Message {
    std::string sender;      // 发送者
    std::string content;     // 消息内容
    int timestamp;           // 时间戳（简化）
};

// 函数 1：使用 const 引用传递结构体（只读，推荐）
void printUserInfo(const User& user) {
    std::cout << "=== 用户信息 ===" << std::endl;
    std::cout << "姓名: " << user.name << std::endl;
    std::cout << "年龄: " << user.age << std::endl;
    std::cout << "在线状态: " << (user.isOnline ? "在线" : "离线") << std::endl;
}

// 函数 2：使用非 const 引用修改结构体
void updateUserStatus(User& user, bool status) {
    user.isOnline = status;
    std::cout << user.name << " 的状态已更新为: " << (status ? "在线" : "离线") << std::endl;
}

// 函数 3：使用 const 引用传递消息（只读）
void printMessage(const Message& msg) {
    std::cout << "[" << msg.sender << "]: " << msg.content << std::endl;
}

// 函数 4：管理用户列表
void manageUserList() {
    std::vector<User> users;

    // 添加用户
    users.push_back({"张三", 25, true});
    users.push_back({"李四", 30, false});
    users.push_back({"王五", 28, true});

    // 遍历并打印用户信息
    std::cout << "\n=== 用户列表 ===" << std::endl;
    for (const auto& user : users) {
        printUserInfo(user);
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "=== QtLanChat 结构体应用 ===" << std::endl;

    // 创建用户
    User user1 = {"张三", 25, true};
    printUserInfo(user1);

    // 更新用户状态
    updateUserStatus(user1, false);
    printUserInfo(user1);

    // 创建消息
    Message msg1 = {"张三", "你好，大家好！", 1234567890};
    printMessage(msg1);

    // 管理用户列表
    manageUserList();

    return 0;
}
