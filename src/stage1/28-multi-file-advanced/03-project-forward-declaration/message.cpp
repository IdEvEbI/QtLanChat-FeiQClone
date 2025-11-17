#include "message.h"
#include "user.h"  // 实现时需要完整定义
#include <iostream>

Message::Message(const std::string& content) : content(content), sender(nullptr) {}

void Message::setSender(User* user) {
    sender = user;
}

void Message::printInfo() const {
    std::cout << "消息内容: " << content;
    if (sender) {
        std::cout << "，来自用户";
    }
    std::cout << std::endl;
}

