#include "student_manager.h"
#include "student.h"                    // 实现时需要完整定义
#include <iostream>

namespace StudentSystem {
    void StudentManager::addStudent(Student* student) {
        students.push_back(student);
    }

    void StudentManager::printAllStudents() const {
        std::cout << "=== 所有学生 ===" << std::endl;
        for (const Student* student : students) {
            std::cout << student->getName() << " - " << student->getAge() << " 岁" << std::endl;
        }
    }

    int StudentManager::getStudentCount() const {
        return static_cast<int>(students.size());
    }

    // 友元函数定义：计算平均年龄
    double calculateAverageAge(const StudentManager& manager) {
        if (manager.students.empty()) {
            return 0.0;
        }

        int totalAge = 0;
        for (const Student* student : manager.students) {
            totalAge += student->age;   // 友元函数可以访问私有成员
        }

        return static_cast<double>(totalAge) / manager.students.size();
    }
}

