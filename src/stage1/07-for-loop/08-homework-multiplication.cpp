#include <iostream>

int main() {
    std::cout << "=== 完整九九乘法表 ===" << std::endl;
    std::cout << "\n";

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << j << " x " << i << " = " << (i * j) << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << "\n九九乘法表打印完成！" << std::endl;

    return 0;
}

