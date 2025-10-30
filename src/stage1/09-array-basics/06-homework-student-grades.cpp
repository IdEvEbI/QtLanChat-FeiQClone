#include <iostream>
#include <string>

int main() {
    std::string names[5] = {"小丽", "小强", "小伟", "小美", "小明"};
    int scores[5] = {85, 90, 78, 92, 88};

    int sum = 0;
    int max = scores[0];
    int min = scores[0];

    // 计算总和、最大值、最小值
    for (int i = 0; i < 5; i++) {
        sum += scores[i];
        if (scores[i] > max) max = scores[i];
        if (scores[i] < min) min = scores[i];
    }

    double average = static_cast<double>(sum) / 5;

    // 输出结果
    std::cout << "=== 学生成绩管理系统 ===" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << names[i] << ": " << scores[i] << "分" << std::endl;
    }
    std::cout << "\n平均分: " << average << std::endl;
    std::cout << "最高分: " << max << std::endl;
    std::cout << "最低分: " << min << std::endl;

    return 0;
}
