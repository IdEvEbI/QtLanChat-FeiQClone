// 03-basic-unordered-map.cpp
#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    // 创建并初始化 unordered_map
    std::unordered_map<std::string, int> scores = {
        {"小美", 95},
        {"小丽", 87},
        {"阿伟", 92}
    };

    // 添加元素
    scores["小明"] = 88;
    scores.emplace("小华", 90);

    // 访问元素
    std::cout << "小美的成绩: " << scores["小美"] << std::endl;

    // 遍历（顺序不确定，可能每次运行顺序不同）
    std::cout << "\n=== 所有成绩（无序） ===" << std::endl;
    for (const auto& pair : scores) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // 查找元素
    if (scores.find("阿伟") != scores.end()) {
        std::cout << "\n找到阿伟" << std::endl;
    }

    return 0;
}
