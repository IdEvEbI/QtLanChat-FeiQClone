// 05-exercise-sum.cpp
// 练习题 3：使用 Lambda 表达式实现：给定一个整数 vector，统计所有偶数的和
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    int sum = 0;
    std::for_each(numbers.begin(), numbers.end(), 
        [&sum](int num) {  // 引用捕获 sum
            if (num % 2 == 0) {
                sum += num;
            }
        });
    
    std::cout << "偶数的和: " << sum << std::endl;
    
    return 0;
}


