#include <iostream>
#include "student.h"
#include "student_manager.h"
#include "utils.h"

int main() {
    using namespace StudentSystem;

    // 创建学生
    Student s1("张三", 20);
    Student s2("李四", 21);
    Student s3("王五", 19);

    std::cout << "学生总数: " << Student::getTotalStudents() << std::endl;

    // 创建管理器
    StudentManager manager;
    manager.addStudent(&s1);
    manager.addStudent(&s2);
    manager.addStudent(&s3);

    // 显示所有学生
    manager.printAllStudents();

    // 计算平均年龄
    double avgAge = calculateAverageAge(manager);
    std::cout << "平均年龄: " << avgAge << " 岁" << std::endl;

    return 0;
}

