#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    double score;
};

int main() {
    std::vector<Student> students;

    // 输入学生信息
    std::cout << "请输入学生信息（输入 'end' 结束）：" << std::endl;
    std::string name;
    double score;

    while (std::cin >> name && name != "end") {
        std::cin >> score;
        students.push_back({name, score});
    }

    // 保存到文件
    std::ofstream file("students.txt");
    if (file.is_open()) {
        for (const auto& student : students) {
            file << student.name << " " << student.score << std::endl;
        }
        file.close();
        std::cout << "学生信息已保存" << std::endl;
    }

    // 从文件加载并计算平均分
    std::ifstream inFile("students.txt");
    if (inFile.is_open()) {
        std::vector<Student> loadedStudents;
        std::string name;
        double score;

        while (inFile >> name >> score) {
            loadedStudents.push_back({name, score});
        }
        inFile.close();

        // 计算平均分
        double sum = 0;
        for (const auto& student : loadedStudents) {
            sum += student.score;
        }

        if (!loadedStudents.empty()) {
            double average = sum / loadedStudents.size();
            std::cout << "平均分: " << average << std::endl;
        }
    }

    return 0;
}
