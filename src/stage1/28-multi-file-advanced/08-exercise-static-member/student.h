#pragma once

#include <string>

class Student {
private:
    std::string name;
    int age;
    static int totalStudents;  // 静态成员变量声明

public:
    Student(const std::string& name, int age);
    ~Student();

    static int getTotalStudents();  // 静态成员函数
    std::string getName() const;
    int getAge() const;
};

