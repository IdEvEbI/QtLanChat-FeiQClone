#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::cout << "=== 数据类型综合演示 ===" << std::endl;

    // 学生信息
    std::string studentName = "小明";
    int studentAge = 20;
    double gpa = 3.85;                  // GPA：平均绩点，范围0.0-4.0
    char grade = 'A';
    bool isGraduated = false;

    // 使用 auto 推断类型
    auto studentId = 2023001;
    auto fee = 5000.0;

    // 输出学生信息
    std::cout << "学生姓名: " << studentName << std::endl;
    std::cout << "学生年龄: " << studentAge << "岁" << std::endl;
    std::cout << "学生ID: " << studentId << std::endl;
    std::cout << "GPA: " << std::fixed << std::setprecision(2) << gpa << std::endl;
    std::cout << "等级: " << grade << std::endl;
    std::cout << "学费: " << fee << "元" << std::endl;
    std::cout << "是否毕业: " << isGraduated << std::endl;

    return 0;
}

