#include <iostream>
#include "grade_manager.h"

int main() {
    GradeManager manager;

    // 添加学生（可能抛出异常）
    try {
        manager.addStudent("小美", 95);
        manager.addStudent("小丽", 87);
        manager.addStudent("阿伟", 150);  // 无效成绩，会抛出异常
    } catch (const std::invalid_argument& e) {
        std::cout << "添加学生时发生错误: " << e.what() << std::endl;
    }

    // 查询成绩（可能抛出异常）
    try {
        int score = manager.getScore("小美");
        std::cout << "小美的成绩: " << score << std::endl;

        score = manager.getScore("小明");  // 不存在的学生，会抛出异常
        std::cout << "小明的成绩: " << score << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "查询成绩时发生错误: " << e.what() << std::endl;
    }

    // 更新成绩（可能抛出异常）
    try {
        manager.updateScore("小丽", 92);
        manager.updateScore("小明", 88);  // 不存在的学生，会抛出异常
    } catch (const std::runtime_error& e) {
        std::cout << "更新成绩时发生错误: " << e.what() << std::endl;
    }

    // 显示所有学生
    manager.printAllStudents();

    return 0;
}

