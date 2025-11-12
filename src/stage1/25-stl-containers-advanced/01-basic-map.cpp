// 01-basic-map.cpp
#include <iostream>
#include <map>
#include <string>

int main() {
    // 创建并初始化 map
    std::map<std::string, int> scores = {
        {"小美", 95},
        {"小丽", 87},
        {"阿伟", 92}
    };

    // 添加元素
    scores["小明"] = 88;
    scores.emplace("小华", 90);

    // 访问元素
    std::cout << "小美的成绩: " << scores["小美"] << std::endl;
    std::cout << "小丽的成绩: " << scores.at("小丽") << std::endl;

    // 修改元素
    scores["小美"] = 98;
    std::cout << "小美的新成绩: " << scores["小美"] << std::endl;

    // 遍历 map（自动按键排序）
    std::cout << "\n=== 所有成绩（按姓名排序） ===" << std::endl;
    for (const auto& pair : scores) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // 查找元素
    auto it = scores.find("阿伟");
    if (it != scores.end()) {
        std::cout << "\n找到阿伟: " << it->second << std::endl;
    }

    // 删除元素
    scores.erase("小丽");
    std::cout << "\n删除小丽后，人数: " << scores.size() << std::endl;

    return 0;
}
