// student.h
#pragma once

#include <string>

class Student {
private:
    std::string name;
    int score;
public:
    Student(const std::string& n, int s);
    void printInfo();
};
