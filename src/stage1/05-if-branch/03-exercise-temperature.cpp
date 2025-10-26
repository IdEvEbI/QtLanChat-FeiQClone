#include <iostream>

int main() {
    int temp;

    std::cout << "请输入温度: ";
    std::cin >> temp;

    if (temp >= 30) {
        std::cout << "炎热，注意防暑" << std::endl;
    } else if (temp >= 20) {
        std::cout << "温暖，适合出行" << std::endl;
    } else if (temp >= 10) {
        std::cout << "凉爽，注意保暖" << std::endl;
    } else {
        std::cout << "寒冷，注意防寒" << std::endl;
    }

    return 0;
}

