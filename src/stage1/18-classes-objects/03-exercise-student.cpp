#include <iostream>
#include <string>

class Student {
public:
    std::string name;
    int age;
    double score;

    void printInfo() {
        std::cout << "姓名: " << name << std::endl;
        std::cout << "年龄: " << age << std::endl;
        std::cout << "成绩: " << score << std::endl;
    }
};

int main() {
    Student student1;
    student1.name = "张三";
    student1.age = 20;
    student1.score = 85.5;

    Student student2;
    student2.name = "李四";
    student2.age = 21;
    student2.score = 92.0;

    student1.printInfo();
    std::cout << std::endl;
    student2.printInfo();

    return 0;
}
