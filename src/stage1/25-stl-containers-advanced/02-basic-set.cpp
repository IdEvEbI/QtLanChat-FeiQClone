// 02-basic-set.cpp
#include <iostream>
#include <set>
#include <vector>

int main() {
    // 创建并初始化 set（自动去重和排序）
    std::set<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

    std::cout << "=== Original numbers (with duplicates) ===" << std::endl;
    std::vector<int> original = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    for (int num : original) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "\n=== Set (unique and sorted) ===" << std::endl;
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 添加元素
    numbers.insert(7);
    numbers.insert(1);              // 重复元素，不会添加

    std::cout << "\n=== After inserting 7 and 1 ===" << std::endl;
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 查找元素
    if (numbers.find(5) != numbers.end()) {
        std::cout << "\n5 is in the set" << std::endl;
    }

    // 删除元素
    numbers.erase(3);
    std::cout << "\n=== After removing 3 ===" << std::endl;
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
