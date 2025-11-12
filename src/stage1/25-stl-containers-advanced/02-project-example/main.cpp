// main.cpp
#include <iostream>
#include "user_manager.h"

int main() {
    UserManager manager;

    // 添加用户
    manager.addUser("小美", 25);
    manager.addUser("小丽", 30);
    manager.addUser("阿伟", 28);
    manager.addUser("小明", 22);

    // 设置用户在线状态
    manager.setUserOnline("小美", true);
    manager.setUserOnline("小丽", true);
    manager.setUserOnline("阿伟", false);

    // 显示所有用户
    manager.printAllUsers();

    // 显示在线用户
    manager.printOnlineUsers();

    // 查找用户
    User* user = manager.findUser("小美");
    if (user != nullptr) {
        std::cout << "\n找到用户: ";
        user->printInfo();
    }

    // 统计信息
    std::cout << "\n总用户数: " << manager.getTotalUsers() << std::endl;
    std::cout << "在线用户数: " << manager.getOnlineUsersCount() << std::endl;

    return 0;
}
