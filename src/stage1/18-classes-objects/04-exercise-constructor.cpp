#include <iostream>
#include <string>

class Student {
public:
    std::string name;
    int age;
    double score;

    // 构造函数
    Student(const std::string& studentName, int studentAge, double studentScore) {
        name = studentName;
        age = studentAge;
        score = studentScore;
    }

    void printInfo() {
        std::cout << "姓名: " << name << ", 年龄: " << age
                  << ", 成绩: " << score << std::endl;
    }
};

int main() {
    // 使用构造函数创建对象
    Student student1("张三", 20, 85.5);
    Student student2("李四", 21, 92.0);

    student1.printInfo();
    student2.printInfo();

    return 0;
}
