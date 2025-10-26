#include <iostream>

int main() {
    int num1;
    int num2;
    char operation;

    std::cout << "请输入第一个数字: ";
    std::cin >> num1;

    std::cout << "请输入运算符 (+, -, *, /): ";
    std::cin >> operation;

    std::cout << "请输入第二个数字: ";
    std::cin >> num2;

    std::cout << num1 << " " << operation << " " << num2 << " = ";

    switch (operation) {
        case '+':
            std::cout << (num1 + num2) << std::endl;
            break;
        case '-':
            std::cout << (num1 - num2) << std::endl;
            break;
        case '*':
            std::cout << (num1 * num2) << std::endl;
            break;
        case '/':
            if (num2 != 0) {
                std::cout << (num1 / num2) << std::endl;
            } else {
                std::cout << "错误：除数不能为0！" << std::endl;
            }
            break;
        default:
            std::cout << "不支持的运算符！" << std::endl;
            break;
    }

    return 0;
}

