#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int age;
    double score;

public:
    // 构造函数
    Student(const std::string& studentName, int studentAge, double studentScore) {
        name = studentName;
        age = studentAge;
        score = studentScore;
    }

    // Getter
    std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    double getScore() const {
        return score;
    }

    // Setter（带验证）
    void setName(const std::string& newName) {
        if (!newName.empty()) {
            name = newName;
        }
    }

    void setAge(int newAge) {
        if (newAge > 0 && newAge < 150) {
            age = newAge;
        }
    }

    void setScore(double newScore) {
        if (newScore >= 0 && newScore <= 100) {
            score = newScore;
        }
    }

    void printInfo() const {
        std::cout << "姓名: " << name << ", 年龄: " << age
                  << ", 成绩: " << score << std::endl;
    }
};

int main() {
    Student student("张三", 20, 85.5);

    // 使用 getter
    std::cout << "姓名: " << student.getName() << std::endl;
    std::cout << "年龄: " << student.getAge() << std::endl;

    // 使用 setter（带验证）
    student.setName("李四");
    student.setAge(25);
    student.setScore(95.0);

    student.printInfo();

    return 0;
}
