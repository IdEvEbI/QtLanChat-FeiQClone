#include <iostream>
#include <vector>

int main() {
    std::vector<int> scores;

    // 添加成绩
    scores.push_back(85);
    scores.push_back(90);
    scores.push_back(78);
    scores.push_back(92);
    scores.push_back(88);

    // 遍历并计算平均分
    int sum = 0;
    std::cout << "成绩列表：" << std::endl;
    for (size_t i = 0; i < scores.size(); i++) {
        std::cout << "学生" << (i + 1) << ": " << scores[i] << std::endl;
        sum += scores[i];
    }

    double average = static_cast<double>(sum) / scores.size();
    std::cout << "\n平均分: " << average << std::endl;

    return 0;
}

