// 02-advanced-lambda.cpp
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
        {"小明", 78}
    };
    
    // 示例 1：按分数从高到低排序
    std::sort(students.begin(), students.end(), 
        [](const Student& a, const Student& b) {
            return a.score > b.score;
        });
    
    std::cout << "=== 按分数排序 ===" << std::endl;
    std::for_each(students.begin(), students.end(), 
        [](const Student& s) {
            std::cout << s.name << ": " << s.score << std::endl;
        });
    
    // 示例 2：查找分数大于 90 的学生
    std::cout << "\n=== 分数大于 90 的学生 ===" << std::endl;
    std::for_each(students.begin(), students.end(), 
        [](const Student& s) {
            if (s.score > 90) {
                std::cout << s.name << ": " << s.score << std::endl;
            }
        });
    
    // 示例 3：统计平均分
    int sum = 0;
    std::for_each(students.begin(), students.end(), 
        [&sum](const Student& s) {  // 引用捕获 sum
            sum += s.score;
        });
    
    double average = static_cast<double>(sum) / students.size();
    std::cout << "\n平均分: " << average << std::endl;
    
    return 0;
}


