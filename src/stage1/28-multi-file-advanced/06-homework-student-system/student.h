#pragma once

#include <string>

namespace StudentSystem {
    class StudentManager;               // 前向声明

    // 前向声明友元函数
    double calculateAverageAge(const StudentManager& manager);

    class Student {
    private:
        std::string name;
        int age;
        static int totalStudents;       // 静态成员变量

        friend class StudentManager;    // 友元类
        friend double calculateAverageAge(const StudentManager& manager);  // 友元函数

    public:
        Student(const std::string& name, int age);
        ~Student();

        static int getTotalStudents();  // 静态成员函数
        std::string getName() const;
        int getAge() const;
    };
}

