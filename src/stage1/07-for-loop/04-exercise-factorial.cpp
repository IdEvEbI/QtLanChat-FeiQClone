#include <iostream>

int main() {
    int n;
    long long factorial = 1;

    std::cout << "请输入一个正整数: ";
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        factorial *= i;  // 累乘
    }

    std::cout << n << "! = " << factorial << std::endl;

    return 0;
}

