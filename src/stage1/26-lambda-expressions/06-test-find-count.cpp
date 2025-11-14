// 06-test-find-count.cpp
// 编程题 1：使用 Lambda 表达式查找和统计
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {3, 7, 2, 9, 5, 8, 1, 6, 4, 10};

    std::cout << "原始数据: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 1. 查找第一个大于 7 的元素
    auto it = std::find_if(numbers.begin(), numbers.end(),
        [](int num) { return num > 7; });

    if (it != numbers.end()) {
        std::cout << "第一个大于 7 的元素: " << *it << std::endl;
    } else {
        std::cout << "未找到大于 7 的元素" << std::endl;
    }

    // 2. 统计所有小于等于 5 的元素个数
    int count = std::count_if(numbers.begin(), numbers.end(),
        [](int num) { return num <= 5; });
    std::cout << "小于等于 5 的元素个数: " << count << std::endl;

    // 3. 将所有奇数乘以 2
    std::for_each(numbers.begin(), numbers.end(),
        [](int& num) {  // 引用捕获才能修改元素
            if (num % 2 != 0) {  // 判断是否为奇数
                num *= 2;
            }
        });

    std::cout << "奇数乘以 2 后: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

