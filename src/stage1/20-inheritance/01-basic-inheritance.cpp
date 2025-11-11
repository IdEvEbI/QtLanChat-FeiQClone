// 现代 C++ 示例 - 继承基础
#include <iostream>
#include <string>

// 基类：人员类
class Person {
protected:
    std::string name;
    int age;

public:
    Person(const std::string& n, int a) : name(n), age(a) {
        std::cout << "创建人员: " << name << std::endl;
    }

    void printInfo() {
        std::cout << "=== 人员信息 ===" << std::endl;
        std::cout << "姓名: " << name << std::endl;
        std::cout << "年龄: " << age << std::endl;
    }
};

// 派生类：学生类
class Student : public Person {
private:
    std::string studentId;

public:
    Student(const std::string& n, int a, const std::string& id)
        : Person(n, a), studentId(id) {
        std::cout << "创建学生: " << name << std::endl;
    }

    void printStudentInfo() {
        printInfo();  // 调用基类的成员函数
        std::cout << "学号: " << studentId << std::endl;
    }
};

// 派生类：教师类
class Teacher : public Person {
private:
    std::string teacherId;

public:
    Teacher(const std::string& n, int a, const std::string& id)
        : Person(n, a), teacherId(id) {
        std::cout << "创建教师: " << name << std::endl;
    }

    void printTeacherInfo() {
        printInfo();  // 调用基类的成员函数
        std::cout << "工号: " << teacherId << std::endl;
    }
};

int main() {
    // 创建学生对象
    Student student("张三", 20, "S001");
    student.printStudentInfo();

    std::cout << std::endl;

    // 创建教师对象
    Teacher teacher("李老师", 35, "T001");
    teacher.printTeacherInfo();

    return 0;
}
