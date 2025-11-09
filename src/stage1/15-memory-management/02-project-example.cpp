// 项目中的实际应用示例
#include <iostream>
#include <memory>
#include <vector>
#include <string>

// 用户信息结构（简化版）
struct User {
    std::string name;
    int age;
    bool isOnline;
};

// 使用智能指针管理用户对象
void createUser() {
    // 使用 unique_ptr 创建用户（推荐）
    std::unique_ptr<User> user = std::make_unique<User>();
    user->name = "张三";
    user->age = 25;
    user->isOnline = true;

    std::cout << "创建用户: " << user->name << std::endl;
    // 函数结束时，user 自动销毁，内存自动释放
}

// 使用智能指针管理用户数组
void manageUserList() {
    std::vector<std::unique_ptr<User>> users;

    // 动态添加用户
    users.push_back(std::make_unique<User>());
    users.back()->name = "李四";
    users.back()->age = 30;

    users.push_back(std::make_unique<User>());
    users.back()->name = "王五";
    users.back()->age = 28;

    std::cout << "用户列表：" << std::endl;
    for (const auto& user : users) {
        std::cout << "- " << user->name << " (" << user->age << "岁)" << std::endl;
    }
    // 函数结束时，所有 unique_ptr 自动销毁，内存自动释放
}

// 使用 shared_ptr 共享用户对象
void shareUser() {
    std::shared_ptr<User> user = std::make_shared<User>();
    user->name = "赵六";
    user->age = 32;

    // 多个地方可以共享同一个用户对象
    std::shared_ptr<User> userCopy = user;
    std::cout << "原始引用计数: " << user.use_count() << std::endl;  // 输出: 2

    // 使用共享的用户对象
    std::cout << "用户名: " << userCopy->name << std::endl;
    // 当所有 shared_ptr 都销毁时，内存自动释放
}

int main() {
    std::cout << "=== QtLanChat 内存管理应用 ===" << std::endl;

    createUser();
    std::cout << std::endl;

    manageUserList();
    std::cout << std::endl;

    shareUser();

    return 0;
}
