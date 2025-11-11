// student_manager.cpp
#include "student_manager.h"
#include <iostream>

void StudentManager::addStudent(const Student& student) {
    students.push_back(student);
}

void StudentManager::displayAll() const {
    std::cout << "=== 所有学生信息 ===" << std::endl;
    for (const auto& student : students) {
        student.printInfo();
    }
}

double StudentManager::getAverageScore() const {
    if (students.empty()) {
        return 0.0;
    }

    double sum = 0.0;
    for (const auto& student : students) {
        sum += student.getScore();
    }
    return sum / students.size();
}
