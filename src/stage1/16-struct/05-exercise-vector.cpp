#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    int age;
    double score;
};

void printStudent(const Student& student) {
    std::cout << student.name << ", " << student.age
              << "岁, 成绩: " << student.score << std::endl;
}

int main() {
    std::vector<Student> students;

    // 添加学生
    students.push_back({"张三", 20, 85.5});
    students.push_back({"李四", 21, 92.0});
    students.push_back({"王五", 19, 88.5});

    // 遍历并输出
    std::cout << "=== 学生列表 ===" << std::endl;
    for (const auto& student : students) {
        printStudent(student);
    }

    return 0;
}
