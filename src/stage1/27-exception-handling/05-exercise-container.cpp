#include <iostream>
#include <map>
#include <vector>
#include <stdexcept>
#include <string>

int main() {
    // map 访问
    std::map<std::string, int> scores = {{"小美", 95}, {"小丽", 87}};

    std::string names[] = {"小美", "小明"};
    for (const std::string& name : names) {
        try {
            int score = scores.at(name);
            std::cout << name << " 的成绩: " << score << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "错误: 未找到学生 " << name << std::endl;
        }
    }

    // vector 访问
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    int indices[] = {2, 10};

    for (int index : indices) {
        try {
            int value = numbers.at(index);
            std::cout << "索引 " << index << " 的值: " << value << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "错误: 索引 " << index << " 越界" << std::endl;
        }
    }

    return 0;
}

