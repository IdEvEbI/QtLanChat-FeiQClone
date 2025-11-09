// 项目中的实际应用示例
#include <iostream>
#include <string>

// 用户状态枚举
enum UserStatus {
    Online,
    Offline,
    Away,
    Busy
};

// 消息类型枚举
enum MessageType {
    Text,
    Image,
    File,
    System
};

// 用户信息结构体
struct User {
    std::string name;
    int age;
    UserStatus status;  // 使用枚举类型
};

// 消息结构体
struct Message {
    std::string sender;
    std::string content;
    MessageType type;  // 使用枚举类型
};

// 函数 1：使用 switch 处理用户状态
void printUserStatus(const User& user) {
    std::cout << "=== 用户信息 ===" << std::endl;
    std::cout << "姓名: " << user.name << std::endl;
    std::cout << "年龄: " << user.age << std::endl;
    std::cout << "状态: ";

    switch (user.status) {
        case UserStatus::Online:
            std::cout << "在线" << std::endl;
            break;
        case UserStatus::Offline:
            std::cout << "离线" << std::endl;
            break;
        case UserStatus::Away:
            std::cout << "离开" << std::endl;
            break;
        case UserStatus::Busy:
            std::cout << "忙碌" << std::endl;
            break;
    }
}

// 函数 2：使用 switch 处理消息类型
void processMessage(const Message& msg) {
    switch (msg.type) {
        case MessageType::Text:
            std::cout << "[文本消息] " << msg.sender << ": " << msg.content << std::endl;
            break;
        case MessageType::Image:
            std::cout << "[图片消息] " << msg.sender << " 发送了一张图片: " << msg.content << std::endl;
            break;
        case MessageType::File:
            std::cout << "[文件消息] " << msg.sender << " 发送了一个文件: " << msg.content << std::endl;
            break;
        case MessageType::System:
            std::cout << "[系统消息] " << msg.content << std::endl;
            break;
    }
}

// 函数 3：更新用户状态
void updateUserStatus(User& user, UserStatus newStatus) {
    user.status = newStatus;
    std::cout << user.name << " 的状态已更新" << std::endl;
    printUserStatus(user);
}

int main() {
    std::cout << "=== QtLanChat 枚举类型应用 ===" << std::endl;

    // 创建用户
    User user1 = {"张三", 25, UserStatus::Online};
    printUserStatus(user1);

    // 更新用户状态
    updateUserStatus(user1, UserStatus::Busy);

    // 创建消息
    Message msg1 = {"张三", "你好，大家好！", MessageType::Text};
    Message msg2 = {"李四", "/path/to/image.jpg", MessageType::Image};
    Message msg3 = {"系统", "系统维护中...", MessageType::System};

    // 处理消息
    std::cout << "\n=== 消息处理 ===" << std::endl;
    processMessage(msg1);
    processMessage(msg2);
    processMessage(msg3);

    return 0;
}
