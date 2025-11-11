// user.cpp - 用户类源文件
#include "user.h"
#include <iostream>

// 构造函数实现
User::User(const std::string& n, int a) : name(n), age(a) {}

// 成员函数实现
void User::printInfo() const {
    std::cout << "=== 用户信息 ===" << std::endl;
    std::cout << "姓名: " << name << std::endl;
    std::cout << "年龄: " << age << std::endl;
}

std::string User::getName() const {
    return name;
}

int User::getAge() const {
    return age;
}
