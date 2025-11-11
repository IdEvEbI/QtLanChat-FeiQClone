// user.h - 用户类头文件
#pragma once

#include <string>

class User {
private:
    std::string name;
    int age;

public:
    // 构造函数
    User(const std::string& n, int a);

    // 成员函数
    void printInfo() const;
    std::string getName() const;
    int getAge() const;
};
