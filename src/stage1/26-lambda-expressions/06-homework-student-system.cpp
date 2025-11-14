// 06-homework-student-system.cpp
// 综合练习：学生成绩管理系统
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Student {
    std::string name;
    int score;
};

int main() {
    std::vector<Student> students = {
        {"小美", 95},
        {"小丽", 87},
        {"阿伟", 92},
        {"小明", 78},
        {"小华", 65}
    };

    std::cout << "=== 学生成绩管理系统 ===" << std::endl;

    // 1. 按分数从高到低排序
    std::sort(students.begin(), students.end(),
        [](const Student& a, const Student& b) {
            return a.score > b.score;
        });

    std::cout << "\n=== 按分数排序 ===" << std::endl;
    std::for_each(students.begin(), students.end(),
        [](const Student& s) {
            std::cout << s.name << ": " << s.score << std::endl;
        });

    // 2. 打印所有分数大于等于 80 的学生
    std::cout << "\n=== 分数 >= 80 的学生 ===" << std::endl;
    std::for_each(students.begin(), students.end(),
        [](const Student& s) {
            if (s.score >= 80) {
                std::cout << s.name << ": " << s.score << std::endl;
            }
        });

    // 3. 统计分数大于等于 60 的学生数量
    int passCount = std::count_if(students.begin(), students.end(),
        [](const Student& s) {
            return s.score >= 60;
        });
    std::cout << "\n分数 >= 60 的学生数量: " << passCount << std::endl;

    // 4. 计算所有学生的平均分
    int sum = 0;
    std::for_each(students.begin(), students.end(),
        [&sum](const Student& s) {  // 引用捕获 sum
            sum += s.score;
        });
    double average = static_cast<double>(sum) / students.size();
    std::cout << "平均分: " << average << std::endl;

    return 0;
}

