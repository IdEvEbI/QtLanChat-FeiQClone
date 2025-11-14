#pragma once

#include <string>

class User {
public:
    User(const std::string& name, int age);
    
    std::string getName() const;
    int getAge() const;
    
private:
    std::string name;
    int age;
};


