#pragma once

#include <string>

class Message;  // 前向声明：只需要指针，不需要完整定义

class User {
private:
    std::string name;
    Message* message;  // 使用指针，前向声明足够

public:
    User(const std::string& name);
    void setMessage(Message* msg);
    void printInfo() const;
};

