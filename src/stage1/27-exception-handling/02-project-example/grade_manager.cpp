#include "grade_manager.h"
#include <iostream>
#include <stdexcept>

void GradeManager::addStudent(const std::string& name, int score) {
    try {
        students.emplace(name, Student(name, score));
        std::cout << "添加学生成功: " << name << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "添加学生失败: " << e.what() << std::endl;
        throw;  // 重新抛出异常，让调用者处理
    }
}

int GradeManager::getScore(const std::string& name) const {
    try {
        return students.at(name).getScore();
    } catch (const std::out_of_range& e) {
        throw std::runtime_error("未找到学生: " + name);
    }
}

void GradeManager::updateScore(const std::string& name, int score) {
    try {
        Student& student = students.at(name);
        student.setScore(score);
        std::cout << "更新成绩成功: " << name << " -> " << score << std::endl;
    } catch (const std::out_of_range& e) {
        throw std::runtime_error("未找到学生: " + name);
    } catch (const std::invalid_argument& e) {
        std::cout << "更新成绩失败: " << e.what() << std::endl;
        throw;
    }
}

void GradeManager::printAllStudents() const {
    std::cout << "=== 所有学生成绩 ===" << std::endl;
    for (const auto& pair : students) {
        std::cout << pair.first << ": " << pair.second.getScore() << std::endl;
    }
}

