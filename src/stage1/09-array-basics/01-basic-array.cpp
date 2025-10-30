#include <iostream>
#include <string>

int main() {
    // 示例 1：整数数组声明和初始化
    std::cout << "=== 整数数组 ===" << std::endl;
    int scores[5] = {85, 90, 78, 92, 88};

    // 访问数组元素：scores[0] 是第一个元素
    std::cout << "第一个学生的成绩: " << scores[0] << std::endl;
    std::cout << "第二个学生的成绩: " << scores[1] << std::endl;
    std::cout << "第三个学生的成绩: " << scores[2] << std::endl;

    // 示例 2：字符串数组
    std::cout << "\n=== 字符串数组 ===" << std::endl;
    std::string names[3] = {"张三", "李四", "王五"};

    for (int i = 0; i < 3; i++) {
        std::cout << "第" << (i + 1) << "个人: " << names[i] << std::endl;
    }

    // 示例 3：修改数组元素
    std::cout << "\n=== 修改数组元素 ===" << std::endl;
    int numbers[5] = {1, 2, 3, 4, 5};

    std::cout << "修改前: ";
    for (int i = 0; i < 5; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    numbers[0] = 10;            // 修改第一个元素
    numbers[4] = 50;            // 修改最后一个元素

    std::cout << "修改后: ";
    for (int i = 0; i < 5; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    // 示例 4：计算数组元素总和
    std::cout << "\n=== 计算数组总和 ===" << std::endl;
    int data[5] = {10, 20, 30, 40, 50};
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        sum += data[i];         // 累加
    }

    std::cout << "数组总和: " << sum << std::endl;
    std::cout << "平均值: " << sum / 5 << std::endl;

    // 示例 5：查找最大值
    std::cout << "\n=== 查找最大值 ===" << std::endl;
    int values[5] = {34, 67, 23, 89, 12};
    int max = values[0];        // 假设第一个元素是最大值

    for (int i = 1; i < 5; i++) {
        if (values[i] > max) {
            max = values[i];    // 找到更大的值，更新max
        }
    }

    std::cout << "最大值: " << max << std::endl;

    return 0;
}
