#include "student.h"

int Student::totalStudents = 0;  // 静态成员变量定义

Student::Student(const std::string& name, int age)
    : name(name), age(age) {
    totalStudents++;
}

Student::~Student() {
    totalStudents--;
}

int Student::getTotalStudents() {
    return totalStudents;
}

std::string Student::getName() const {
    return name;
}

int Student::getAge() const {
    return age;
}

