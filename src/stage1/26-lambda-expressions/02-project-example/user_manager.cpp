#include "user_manager.h"
#include <algorithm>
#include <iostream>

void UserManager::addUser(const User& user) {
    users.push_back(user);
}

void UserManager::printAllUsers() const {
    std::cout << "=== 所有用户 ===" << std::endl;
    std::for_each(users.begin(), users.end(), 
        [](const User& user) {
            std::cout << user.getName() << " (" << user.getAge() << " 岁)" << std::endl;
        });
}

void UserManager::printUsersByAge(int minAge) const {
    std::cout << "\n=== 年龄 >= " << minAge << " 的用户 ===" << std::endl;
    std::for_each(users.begin(), users.end(), 
        [minAge](const User& user) {  // 值捕获 minAge
            if (user.getAge() >= minAge) {
                std::cout << user.getName() << " (" << user.getAge() << " 岁)" << std::endl;
            }
        });
}

void UserManager::sortUsersByAge() {
    std::sort(users.begin(), users.end(), 
        [](const User& a, const User& b) {
            return a.getAge() < b.getAge();
        });
}

int UserManager::countUsersByAge(int minAge) const {
    return std::count_if(users.begin(), users.end(), 
        [minAge](const User& user) {  // 值捕获 minAge
            return user.getAge() >= minAge;
        });
}


