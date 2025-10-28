#include <iostream>

int main() {
    int skipCount = 0;

    std::cout << "输出 1-20 中不是 3 的倍数的数字：" << std::endl;
    for (int i = 1; i <= 20; i++) {
        if (i % 3 == 0) {
            skipCount++;
            continue;  // 跳过 3 的倍数
        }
        std::cout << i << " ";
    }
    std::cout << "\n跳过了 " << skipCount << " 个数字" << std::endl;

    return 0;
}
