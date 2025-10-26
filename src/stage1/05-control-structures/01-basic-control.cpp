// 现代 C++ 示例 - 控制结构基础
#include <iostream>

int main() {
    // if-else 条件语句
    std::cout << "=== if-else 条件语句 ===" << std::endl;
    int score = 85;
    
    if (score >= 90) {
        std::cout << "优秀" << std::endl;
    } else if (score >= 60) {
        std::cout << "及格" << std::endl;
    } else {
        std::cout << "不及格" << std::endl;
    }

    // while 循环
    std::cout << "\n=== while 循环 ===" << std::endl;
    int count = 1;
    while (count <= 5) {
        std::cout << "次数: " << count << std::endl;
        count++;
    }

    // for 循环
    std::cout << "\n=== for 循环 ===" << std::endl;
    for (int i = 1; i <= 5; i++) {
        std::cout << "数字: " << i << std::endl;
    }

    // 嵌套循环
    std::cout << "\n=== 嵌套循环 ===" << std::endl;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            std::cout << "(" << i << "," << j << ") ";
        }
        std::cout << std::endl;
    }

    return 0;
}

