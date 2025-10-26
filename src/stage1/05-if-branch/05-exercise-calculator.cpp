#include <iostream>

int main() {
    int num1 = 10;
    int num2 = 3;
    char operation = '+';

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

    return 0;
}

