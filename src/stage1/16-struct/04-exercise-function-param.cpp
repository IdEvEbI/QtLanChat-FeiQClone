#include <iostream>
#include <string>

struct Student {
    std::string name;
    int age;
    double score;
};

// 使用 const 引用打印学生信息（只读）
void printStudent(const Student& student) {
    std::cout << "姓名: " << student.name << std::endl;
    std::cout << "年龄: " << student.age << std::endl;
    std::cout << "成绩: " << student.score << std::endl;
}

// 使用非 const 引用修改成绩
void updateScore(Student& student, double newScore) {
    student.score = newScore;
}

int main() {
    Student student1 = {"张三", 20, 85.5};

    std::cout << "修改前：" << std::endl;
    printStudent(student1);

    updateScore(student1, 95.0);

    std::cout << "\n修改后：" << std::endl;
    printStudent(student1);

    return 0;
}
