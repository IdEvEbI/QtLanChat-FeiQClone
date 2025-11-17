#pragma once

#include <vector>

namespace StudentSystem {
    class Student;                      // 前向声明
    class StudentManager;               // 前向声明

    // 友元函数声明
    double calculateAverageAge(const StudentManager& manager);

    class StudentManager {
    private:
        std::vector<Student*> students; // 使用指针，前向声明足够

        friend double calculateAverageAge(const StudentManager& manager);  // 友元函数

    public:
        void addStudent(Student* student);
        void printAllStudents() const;
        int getStudentCount() const;
    };
}

