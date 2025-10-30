#include <iostream>

int main() {
    int scores[5] = {85, 90, 78, 92, 88};
    int sum = 0;

    // 计算总和
    for (int i = 0; i < 5; i++) {
        sum += scores[i];
        std::cout << "学生" << (i + 1) << "的成绩: " << scores[i] << std::endl;
    }

    // 计算平均分
    double average = static_cast<double>(sum) / 5;
    std::cout << "\n平均分: " << average << std::endl;

    return 0;
}
