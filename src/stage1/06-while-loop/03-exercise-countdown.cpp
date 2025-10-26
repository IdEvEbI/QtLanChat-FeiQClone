#include <iostream>

int main() {
    int count;

    std::cout << "请输入一个正整数: ";
    std::cin >> count;

    std::cout << "倒计时开始：" << std::endl;
    while (count >= 0) {
        std::cout << count << std::endl;
        count--;  // 递减，避免无限循环
    }
    std::cout << "倒计时完成！" << std::endl;

    return 0;
}

