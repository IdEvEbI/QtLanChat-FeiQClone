#include <iostream>

int main() {
    int day;
    std::cout << "请输入数字（1-7）: ";
    std::cin >> day;

    switch (day) {
        case 1:
            std::cout << "星期一" << std::endl;
            break;
        case 2:
            std::cout << "星期二" << std::endl;
            break;
        case 3:
            std::cout << "星期三" << std::endl;
            break;
        case 4:
            std::cout << "星期四" << std::endl;
            break;
        case 5:
            std::cout << "星期五" << std::endl;
            break;
        case 6:
            std::cout << "星期六" << std::endl;
            break;
        case 7:
            std::cout << "星期日" << std::endl;
            break;
        default:
            std::cout << "无效的数字" << std::endl;
            break;
    }

    return 0;
}

