// 项目中的实际应用示例
#include <iostream>
#include <string>
#include <vector>

// 用户信息结构（简化版）
struct User {
    std::string name;
    int age;
    bool isOnline;
};

// 函数 1：使用 const 引用传递大对象（避免复制，只读）
void printUserInfo(const User& user) {
    std::cout << "用户名: " << user.name << std::endl;
    std::cout << "年龄: " << user.age << std::endl;
    std::cout << "在线状态: " << (user.isOnline ? "在线" : "离线") << std::endl;
}

// 函数 2：使用非 const 引用修改参数
void updateUserStatus(User& user, bool status) {
    user.isOnline = status;
    std::cout << user.name << " 的状态已更新为: " << (status ? "在线" : "离线") << std::endl;
}

// 函数 3：使用 const 引用传递字符串（避免复制）
void processMessage(const std::string& message) {
    std::cout << "处理消息: " << message << std::endl;
}

// 函数 4：交换两个用户的状态（使用引用）
void swapUserStatus(User& user1, User& user2) {
    bool temp = user1.isOnline;
    user1.isOnline = user2.isOnline;
    user2.isOnline = temp;
}

// 函数 5：使用 const 引用传递容器（避免复制整个容器）
void printUserList(const std::vector<User>& users) {
    std::cout << "用户列表：" << std::endl;
    for (const User& user : users) {  // 使用引用遍历，避免复制
        printUserInfo(user);
    }
}

// 函数 6：查找用户，返回引用（避免复制）
User& findUserByName(std::vector<User>& users, const std::string& name) {
    for (User& user : users) {  // 使用引用遍历
        if (user.name == name) {
            return user;  // 返回元素的引用
        }
    }
    // 未找到时返回第一个元素（简化处理）
    return users[0];
}

int main() {
    std::cout << "=== QtLanChat 引用应用 ===" << std::endl;

    // 创建用户
    User user1 = {"张三", 25, true};
    User user2 = {"李四", 30, false};

    // 使用 const 引用传递（避免复制）
    std::cout << "\n用户信息：" << std::endl;
    printUserInfo(user1);
    printUserInfo(user2);

    // 使用非 const 引用修改参数
    std::cout << "\n更新状态：" << std::endl;
    updateUserStatus(user1, false);
    updateUserStatus(user2, true);

    // 使用 const 引用传递字符串
    std::cout << "\n处理消息：" << std::endl;
    std::string message = "这是一条很长的消息内容...";
    processMessage(message);  // 不复制，只传递引用

    // 使用引用交换状态
    std::cout << "\n交换状态：" << std::endl;
    std::cout << "交换前：" << std::endl;
    std::cout << "user1 状态: " << (user1.isOnline ? "在线" : "离线") << std::endl;
    std::cout << "user2 状态: " << (user2.isOnline ? "在线" : "离线") << std::endl;
    swapUserStatus(user1, user2);
    std::cout << "交换后：" << std::endl;
    std::cout << "user1 状态: " << (user1.isOnline ? "在线" : "离线") << std::endl;
    std::cout << "user2 状态: " << (user2.isOnline ? "在线" : "离线") << std::endl;

    // 使用 const 引用传递容器
    std::cout << "\n用户列表：" << std::endl;
    std::vector<User> users = {user1, user2, {"王五", 28, true}};
    printUserList(users);  // 不复制整个容器

    // 使用引用查找和修改用户
    std::cout << "\n查找和修改用户：" << std::endl;
    User& found = findUserByName(users, "李四");  // 返回引用
    found.age = 31;  // 通过引用修改
    printUserInfo(found);

    return 0;
}
