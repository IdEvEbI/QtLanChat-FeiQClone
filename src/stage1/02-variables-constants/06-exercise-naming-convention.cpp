// 练习 3：变量命名规范
#include <iostream>
#include <string>

int main() {
    // 使用规范的变量命名
    std::string student_name = "小明";
    int student_age = 20;
    double math_score = 85.5;
    double english_score = 78.0;

    // 使用规范的常量命名
    const int MAX_STUDENTS = 50;
    const double PASSING_SCORE = 60.0;
    const std::string SCHOOL_NAME = "QtLanChat 学院";

    // 输出信息
    std::cout << "=== " << SCHOOL_NAME << " ===" << std::endl;
    std::cout << "学生姓名: " << student_name << std::endl;
    std::cout << "学生年龄: " << student_age << "岁" << std::endl;
    std::cout << "数学成绩: " << math_score << "分" << std::endl;
    std::cout << "英语成绩: " << english_score << "分" << std::endl;
    std::cout << "最大学生数: " << MAX_STUDENTS << std::endl;
    std::cout << "及格分数: " << PASSING_SCORE << "分" << std::endl;

    return 0;
}
