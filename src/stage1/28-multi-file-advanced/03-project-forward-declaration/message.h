#pragma once

#include <string>

class User;  // 前向声明

class Message {
private:
    std::string content;
    User* sender;  // 使用指针，前向声明足够

public:
    Message(const std::string& content);
    void setSender(User* user);
    void printInfo() const;
};

