// user_manager.h
#pragma once

#include "user.h"
#include <map>
#include <set>
#include <string>

class UserManager {
private:
    // 使用 map 存储用户名到用户对象的映射
    std::map<std::string, User> users;
    // 使用 set 存储在线用户名（自动去重）
    std::set<std::string> onlineUsers;

public:
    void addUser(const std::string& name, int age);
    User* findUser(const std::string& name);
    const User* findUser(const std::string& name) const;
    void setUserOnline(const std::string& name, bool status);
    void printAllUsers() const;
    void printOnlineUsers() const;
    size_t getTotalUsers() const;
    size_t getOnlineUsersCount() const;
};
