// user_manager.cpp
#include "user_manager.h"
#include <iostream>

void UserManager::addUser(const std::string& name, int age) {
    // 使用 emplace 方法添加用户（如果已存在，不会覆盖）
    users.emplace(name, User(name, age));
}

User* UserManager::findUser(const std::string& name) {
    auto it = users.find(name);
    if (it != users.end()) {
        return &(it->second);  // 返回用户对象的引用
    }
    return nullptr;  // 未找到
}

const User* UserManager::findUser(const std::string& name) const {
    auto it = users.find(name);
    if (it != users.end()) {
        return &(it->second);  // 返回用户对象的引用
    }
    return nullptr;  // 未找到
}

void UserManager::setUserOnline(const std::string& name, bool status) {
    User* user = findUser(name);
    if (user != nullptr) {
        user->setOnline(status);
        if (status) {
            onlineUsers.insert(name);  // 添加到在线用户集合
        } else {
            onlineUsers.erase(name);   // 从在线用户集合中移除
        }
    }
}

void UserManager::printAllUsers() const {
    std::cout << "=== All Users ===" << std::endl;
    for (const auto& pair : users) {
        pair.second.printInfo();
    }
}

void UserManager::printOnlineUsers() const {
    std::cout << "\n=== Online Users ===" << std::endl;
    for (const auto& name : onlineUsers) {
        const User* user = findUser(name);
        if (user != nullptr) {
            user->printInfo();
        }
    }
}

size_t UserManager::getTotalUsers() const {
    return users.size();
}

size_t UserManager::getOnlineUsersCount() const {
    return onlineUsers.size();
}
