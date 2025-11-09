#include <iostream>
#include <string>

struct Student {
    std::string name;
    int age;
    double score;
};

int main() {
    Student student1 = {"张三", 20, 85.5};
    Student student2 = {"李四", 21, 92.0};

    std::cout << "学生 1: " << student1.name << ", " << student1.age
              << "岁, 成绩: " << student1.score << std::endl;
    std::cout << "学生 2: " << student2.name << ", " << student2.age
              << "岁, 成绩: " << student2.score << std::endl;

    return 0;
}
