// 03-exercise-filter.cpp
// 练习题 1：使用 Lambda 表达式实现：给定一个整数 vector，打印所有大于 10 的元素
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {5, 12, 8, 15, 3, 20, 7};
    
    std::for_each(numbers.begin(), numbers.end(), 
        [](int num) {
            if (num > 10) {
                std::cout << num << " ";
            }
        });
    std::cout << std::endl;
    
    return 0;
}


