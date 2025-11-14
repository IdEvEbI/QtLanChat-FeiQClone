#pragma once

#include <vector>
#include <string>
#include "user.h"

class UserManager {
public:
    void addUser(const User& user);
    void printAllUsers() const;
    void printUsersByAge(int minAge) const;
    void sortUsersByAge();
    int countUsersByAge(int minAge) const;
    
private:
    std::vector<User> users;
};


