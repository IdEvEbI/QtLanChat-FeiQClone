#include <iostream>

int main() {
    int number;
    
    std::cout << "请输入一个数字: ";
    std::cin >> number;

    if (number > 0) {
        std::cout << "正数" << std::endl;
    } else if (number < 0) {
        std::cout << "负数" << std::endl;
    } else {
        std::cout << "零" << std::endl;
    }

    return 0;
}

