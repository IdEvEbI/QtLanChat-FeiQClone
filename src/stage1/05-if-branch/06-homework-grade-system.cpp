#include <iostream>

int main() {
    std::cout << "=== 学生等级评定系统 ===" << std::endl;

    int math = 85;
    int english = 78;
    int chinese = 92;

    std::cout << "数学: " << math << " 分" << std::endl;
    std::cout << "英语: " << english << " 分" << std::endl;
    std::cout << "语文: " << chinese << " 分" << std::endl;

    int total = math + english + chinese;
    int average = total / 3;
    std::cout << "平均分: " << average << " 分" << std::endl;

    // 等级评定
    if (average >= 90) {
        std::cout << "等级: 优秀" << std::endl;
    } else if (average >= 80) {
        std::cout << "等级: 良好" << std::endl;
    } else if (average >= 60) {
        std::cout << "等级: 及格" << std::endl;
    } else {
        std::cout << "等级: 不及格" << std::endl;
    }

    return 0;
}

