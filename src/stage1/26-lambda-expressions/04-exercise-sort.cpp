// 04-exercise-sort.cpp
// 练习题 2：使用 Lambda 表达式实现：给定一个字符串 vector，按字符串长度从短到长排序
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    std::vector<std::string> words = {"apple", "cat", "banana", "dog", "elephant"};
    
    std::sort(words.begin(), words.end(), 
        [](const std::string& a, const std::string& b) {
            return a.length() < b.length();
        });
    
    for (const std::string& word : words) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
    
    return 0;
}


