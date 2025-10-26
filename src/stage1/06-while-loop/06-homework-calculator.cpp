#include <iostream>

int main() {
    std::cout << "=== 简单计算器循环程序 ===" << std::endl;
    
    int choice = 1;
    int num1;
    int num2;
    char operation;
    
    while (choice == 1) {
        std::cout << "\n请输入第一个数字: ";
        std::cin >> num1;
        
        std::cout << "请输入运算符 (+, -, *, /): ";
        std::cin >> operation;
        
        std::cout << "请输入第二个数字: ";
        std::cin >> num2;
        
        std::cout << num1 << " " << operation << " " << num2 << " = ";
        
        if (operation == '+') {
            std::cout << (num1 + num2) << std::endl;
        } else if (operation == '-') {
            std::cout << (num1 - num2) << std::endl;
        } else if (operation == '*') {
            std::cout << (num1 * num2) << std::endl;
        } else if (operation == '/') {
            if (num2 != 0) {
                std::cout << (num1 / num2) << std::endl;
            } else {
                std::cout << "错误：除数不能为0！" << std::endl;
            }
        } else {
            std::cout << "不支持的运算符！" << std::endl;
        }
        
        std::cout << "\n继续计算（输入1）还是退出（输入0）? ";
        std::cin >> choice;
    }
    
    std::cout << "程序已退出，再见！" << std::endl;
    
    return 0;
}

