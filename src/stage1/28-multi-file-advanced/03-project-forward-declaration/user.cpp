#include "user.h"
#include "message.h"  // 实现时需要完整定义
#include <iostream>

User::User(const std::string& name) : name(name), message(nullptr) {}

void User::setMessage(Message* msg) {
    message = msg;
}

void User::printInfo() const {
    std::cout << "用户: " << name;
    if (message) {
        std::cout << "，有消息";
    }
    std::cout << std::endl;
}

