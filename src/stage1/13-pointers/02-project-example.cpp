// 项目中的实际应用示例
#include <iostream>
#include <string>

// 用户信息结构（简化版）
struct User {
    std::string name;
    int age;
    bool isOnline;
};

// 函数 1：使用指针处理可选参数
void sendMessage(const std::string& sender, const std::string& content, User* recipient = nullptr) {
    std::cout << "[" << sender << "]: " << content << std::endl;
    if (recipient != nullptr) {  // 检查指针是否为空
        std::cout << "发送给: " << recipient->name << std::endl;
    } else {
        std::cout << "（广播消息）" << std::endl;
    }
}

// 函数 2：在数组中查找用户，返回指针
User* findUser(User users[], int size, const std::string& name) {
    for (int i = 0; i < size; i++) {
        if (users[i].name == name) {
            return &users[i];  // 返回指向用户的指针
        }
    }
    return nullptr;  // 未找到，返回空指针
}

// 函数 3：使用指针修改用户状态
void updateUserStatusByPointer(User* user, bool status) {
    if (user != nullptr) {  // 安全检查
        user->isOnline = status;
        std::cout << user->name << " 的状态已更新为: " << (status ? "在线" : "离线") << std::endl;
    }
}

int main() {
    std::cout << "=== QtLanChat 指针应用 ===" << std::endl;

    // 创建用户数组
    User users[3] = {
        {"张三", 25, true},
        {"李四", 30, false},
        {"王五", 28, true}
    };

    // 使用指针处理可选参数
    std::cout << "\n发送消息：" << std::endl;
    sendMessage("系统", "欢迎使用 QtLanChat", &users[0]);  // 发送给特定用户
    sendMessage("系统", "系统公告");  // 广播消息（recipient 为空指针）

    // 使用指针查找用户
    std::cout << "\n查找用户：" << std::endl;
    User* found = findUser(users, 3, "李四");
    if (found != nullptr) {
        std::cout << "找到用户: " << found->name << "，年龄: " << found->age << std::endl;
    } else {
        std::cout << "未找到用户" << std::endl;
    }

    // 使用指针修改用户状态
    std::cout << "\n更新状态：" << std::endl;
    updateUserStatusByPointer(found, true);

    return 0;
}




