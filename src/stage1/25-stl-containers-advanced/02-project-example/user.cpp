// user.cpp
#include "user.h"
#include <iostream>

User::User(const std::string& n, int a)
    : name(n), age(a), isOnline(false) {}

void User::setOnline(bool status) {
    isOnline = status;
}

std::string User::getName() const {
    return name;
}

int User::getAge() const {
    return age;
}

bool User::getIsOnline() const {
    return isOnline;
}

void User::printInfo() const {
    std::cout << "Name: " << name
              << ", Age: " << age
              << ", Status: " << (isOnline ? "Online" : "Offline")
              << std::endl;
}
