#include <iostream>

int main() {
    int n;

    std::cout << "请输入一个数字: ";
    std::cin >> n;

    std::cout << "\n数字三角形：" << std::endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

