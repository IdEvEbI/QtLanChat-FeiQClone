// student.cpp
#include "student.h"
#include <iostream>  // 包含 iostream

Student::Student(const std::string& n, int s) : name(n), score(s) {}

void Student::printInfo() {  // 在源文件中实现
    std::cout << name << ": " << score << std::endl;
}
