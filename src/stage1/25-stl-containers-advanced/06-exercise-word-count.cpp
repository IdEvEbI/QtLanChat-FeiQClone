// 06-exercise-word-count.cpp
#include <iostream>
#include <map>
#include <string>
#include <sstream>

int main() {
    std::string text = "hello world hello cpp world cpp";
    std::map<std::string, int> wordCount;

    // 使用 stringstream 分割单词
    std::istringstream iss(text);
    std::string word;
    while (iss >> word) {
        wordCount[word]++;  // 如果键不存在，自动创建并初始化为 0，然后自增
    }

    // 显示统计结果
    std::cout << "=== Word Count ===" << std::endl;
    for (const auto& pair : wordCount) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
