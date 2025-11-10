#include <iostream>
#include <string>

class Student {
public:
    std::string name;
    int age;
    double score;

    Student(const std::string& studentName, int studentAge, double studentScore) {
        name = studentName;
        age = studentAge;
        score = studentScore;
    }

    // 设置成绩
    void setScore(double newScore) {
        score = newScore;
    }

    // 获取成绩
    double getScore() const {
        return score;
    }

    void printInfo() {
        std::cout << "姓名: " << name << ", 成绩: " << score << std::endl;
    }
};

int main() {
    Student student1("张三", 20, 85.5);

    std::cout << "修改前：" << std::endl;
    student1.printInfo();

    student1.setScore(95.0);

    std::cout << "\n修改后：" << std::endl;
    std::cout << "成绩: " << student1.getScore() << std::endl;

    return 0;
}
