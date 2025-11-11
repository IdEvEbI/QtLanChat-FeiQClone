// user.cpp - 项目中的用户类源文件
#include "user.h"
#include <iostream>

User::User(const std::string& n, int a)
    : name(n), age(a), isOnline(false) {}

void User::setOnline(bool status) {
    isOnline = status;
}

void User::printInfo() const {
    std::cout << "用户: " << name
              << " (" << (isOnline ? "在线" : "离线") << ")"
              << std::endl;
}

std::string User::getName() const {
    return name;
}

bool User::getIsOnline() const {
    return isOnline;
}
