// 课后作业：学生信息管理系统
#include <iostream>
#include <string>
#include <iomanip>

int main() {
    // 系统配置常量
    const double PASSING_GRADE = 60.0;
    const std::string SCHOOL_NAME = "QtLanChat 学院";

    // 学生信息变量
    std::string studentName = "小美";
    int studentAge = 19;
    double mathScore = 85.5;
    double englishScore = 78.0;
    double averageScore = (mathScore + englishScore) / 2.0;

    // 设置输出格式
    std::cout << std::fixed << std::setprecision(1);

    // 输出学生信息
    std::cout << "=== " << SCHOOL_NAME << " ===" << std::endl;
    std::cout << "学生姓名: " << studentName << std::endl;
    std::cout << "学生年龄: " << studentAge << "岁" << std::endl;
    std::cout << "数学成绩: " << mathScore << "分" << std::endl;
    std::cout << "英语成绩: " << englishScore << "分" << std::endl;
    std::cout << "平均成绩: " << averageScore << "分" << std::endl;
    std::cout << "及格标准: " << PASSING_GRADE << "分" << std::endl;

    return 0;
}
