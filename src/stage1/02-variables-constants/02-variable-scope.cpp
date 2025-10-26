// 变量作用域示例
#include <iostream>

int globalVar = 100;  // 全局变量

int main() {
    // 全局变量在main函数中可见
    std::cout << "全局变量: " << globalVar << std::endl;

    // 代码块作用域示例
    {
        int localVar = 10;  // 局部变量，只在当前代码块中可见
        std::cout << "局部变量: " << localVar << std::endl;
        std::cout << "代码块内访问全局变量: " << globalVar << std::endl;
    }

    // std::cout << localVar << std::endl;  // 错误：局部变量不可访问

    return 0;
}
