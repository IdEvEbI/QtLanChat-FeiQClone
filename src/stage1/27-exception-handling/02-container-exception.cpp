// 02-container-exception.cpp
#include <iostream>
#include <map>
#include <vector>
#include <stdexcept>
#include <string>

int main() {
    // 示例 1：map 访问异常
    std::map<std::string, int> scores = {{"小美", 95}, {"小丽", 87}};

    try {
        int score = scores.at("小明");  // 使用 at() 访问，键不存在会抛出异常
        std::cout << "小明的成绩: " << score << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "错误: " << e.what() << std::endl;
        std::cout << "未找到学生: 小明" << std::endl;
    }

    // 示例 2：vector 访问异常
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    try {
        int value = numbers.at(10);  // 越界访问，会抛出异常
        std::cout << "值: " << value << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "错误: " << e.what() << std::endl;
        std::cout << "索引越界" << std::endl;
    }

    return 0;
}

