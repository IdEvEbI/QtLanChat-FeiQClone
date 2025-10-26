#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::cout << "=== 数据类型演示系统 ===" << std::endl;

    // 学生信息变量 - 根据数据特性选择合适的类型
    std::string studentName = "小红";
    int studentAge = 19;
    double studentHeight = 1.68;
    char studentGrade = 'B';
    bool isScholarship = true;

    // 系统配置
    const int MAX_STUDENTS = 1000;
    const double PASSING_SCORE = 60.0;
    const std::string SCHOOL_NAME = "QtLanChat 学院";

    // 显示学生信息
    std::cout << "=== " << SCHOOL_NAME << " ===" << std::endl;
    std::cout << "学生姓名: " << studentName << std::endl;
    std::cout << "学生年龄: " << studentAge << "岁" << std::endl;
    std::cout << "学生身高: " << std::fixed << std::setprecision(2) << studentHeight << "米" << std::endl;
    std::cout << "学生等级: " << studentGrade << std::endl;
    std::cout << "奖学金: " << isScholarship << std::endl;
    std::cout << "最大学生数: " << MAX_STUDENTS << std::endl;
    std::cout << "及格分数: " << PASSING_SCORE << "分" << std::endl;

    // 类型转换演示
    double score = 85.7;
    int roundedScore = static_cast<int>(score);
    std::cout << "\n原始分数: " << score << std::endl;
    std::cout << "整数分数: " << roundedScore << std::endl;

    // 类型大小信息
    std::cout << "\n=== 类型大小信息 ===" << std::endl;
    std::cout << "int 大小: " << sizeof(int) << " 字节" << std::endl;
    std::cout << "double 大小: " << sizeof(double) << " 字节" << std::endl;
    std::cout << "char 大小: " << sizeof(char) << " 字节" << std::endl;
    std::cout << "bool 大小: " << sizeof(bool) << " 字节" << std::endl;
    std::cout << "string 大小: " << sizeof(std::string) << " 字节" << std::endl;

    return 0;
}

