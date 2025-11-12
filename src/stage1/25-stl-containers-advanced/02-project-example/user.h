// user.h
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
    std::string getName() const;
    int getAge() const;
    bool getIsOnline() const;
    void printInfo() const;
};
