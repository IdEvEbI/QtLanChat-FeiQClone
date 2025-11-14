// 01-basic-lambda.cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    // 示例 1：打印每个元素
    std::cout << "原始数据: ";
    std::for_each(numbers.begin(), numbers.end(), 
        [](int num) { std::cout << num << " "; });
    std::cout << std::endl;
    
    // 示例 2：将每个元素乘以 2
    std::for_each(numbers.begin(), numbers.end(), 
        [](int& num) { num *= 2; });
    
    std::cout << "乘以 2 后: ";
    std::for_each(numbers.begin(), numbers.end(), 
        [](int num) { std::cout << num << " "; });
    std::cout << std::endl;
    
    // 示例 3：使用外部变量（值捕获）
    int multiplier = 3;
    std::for_each(numbers.begin(), numbers.end(), 
        [multiplier](int& num) { num *= multiplier; });
    
    std::cout << "乘以 " << multiplier << " 后: ";
    std::for_each(numbers.begin(), numbers.end(), 
        [](int num) { std::cout << num << " "; });
    std::cout << std::endl;
    
    return 0;
}


