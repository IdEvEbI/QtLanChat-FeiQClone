// user.h - 项目中的用户类头文件
#pragma once

#include <string>

class User {
private:
    std::string name;
    int age;
    bool isOnline;

public:
    User(const std::string& n, int a);
    void setOnline(bool status);
    void printInfo() const;
    std::string getName() const;
    bool getIsOnline() const;
};
