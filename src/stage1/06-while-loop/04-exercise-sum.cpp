#include <iostream>

int main() {
    int sum = 0;
    int number;

    std::cout << "请输入数字（输入0停止）: ";
    std::cin >> number;

    while (number != 0) {
        sum += number;
        std::cout << "当前总和: " << sum << std::endl;
        std::cout << "请输入下一个数字（输入0停止）: ";
        std::cin >> number;
    }

    std::cout << "\n最终总和: " << sum << std::endl;

    return 0;
}

