// 04-exercise-grade-manager.cpp
#include <iostream>
#include <map>
#include <string>

class GradeManager {
private:
    std::map<std::string, int> grades;

public:
    void addGrade(const std::string& name, int score) {
        grades[name] = score;
    }

    int getGrade(const std::string& name) const {
        auto it = grades.find(name);
        if (it != grades.end()) {
            return it->second;
        }
        return -1;  // 未找到
    }

    void printAllGrades() const {
        std::cout << "=== All Grades ===" << std::endl;
        for (const auto& pair : grades) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
    }

    double getAverage() const {
        if (grades.empty()) {
            return 0.0;
        }
        int sum = 0;
        for (const auto& pair : grades) {
            sum += pair.second;
        }
        return static_cast<double>(sum) / grades.size();
    }
};

int main() {
    GradeManager manager;

    manager.addGrade("小美", 95);
    manager.addGrade("小丽", 87);
    manager.addGrade("阿伟", 92);

    manager.printAllGrades();

    std::cout << "\n小美的成绩: " << manager.getGrade("小美") << std::endl;
    std::cout << "Average grade: " << manager.getAverage() << std::endl;

    return 0;
}
