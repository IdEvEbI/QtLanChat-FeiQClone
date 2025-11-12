// 05-exercise-deduplicate.cpp
#include <iostream>
#include <vector>
#include <set>

int main() {
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    std::cout << "Original numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 使用 set 去重和排序
    std::set<int> uniqueNumbers(numbers.begin(), numbers.end());

    std::cout << "Unique and sorted: ";
    for (int num : uniqueNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
