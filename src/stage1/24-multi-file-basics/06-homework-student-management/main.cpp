// main.cpp
#include <iostream>
#include "student_manager.h"

int main() {
    StudentManager manager;

    // 添加学生
    manager.addStudent(Student("张三", "001", 85.5));
    manager.addStudent(Student("李四", "002", 92.0));
    manager.addStudent(Student("王五", "003", 78.5));

    // 显示所有学生
    manager.displayAll();

    // 显示平均成绩
    std::cout << "\n平均成绩: " << manager.getAverageScore() << std::endl;

    return 0;
}
