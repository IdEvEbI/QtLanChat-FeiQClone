#include <iostream>
#include "student.h"

int main() {
    std::cout << "初始学生数: " << Student::getTotalStudents() << std::endl;

    {
        Student s1("张三", 20);
        Student s2("李四", 21);
        std::cout << "创建 2 个学生后: " << Student::getTotalStudents() << std::endl;
    }

    std::cout << "学生对象销毁后: " << Student::getTotalStudents() << std::endl;

    return 0;
}

