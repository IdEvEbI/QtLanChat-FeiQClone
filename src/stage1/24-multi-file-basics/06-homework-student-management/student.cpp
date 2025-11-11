// student.cpp
#include "student.h"
#include <iostream>

Student::Student(const std::string& n, const std::string& i, double s)
    : name(n), id(i), score(s) {}

void Student::printInfo() const {
    std::cout << "姓名: " << name
              << ", 学号: " << id
              << ", 成绩: " << score << std::endl;
}

double Student::getScore() const {
    return score;
}

std::string Student::getName() const {
    return name;
}
