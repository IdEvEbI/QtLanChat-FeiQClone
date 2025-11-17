// 01-basic-exception.cpp
#include <iostream>
#include <stdexcept>

int divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("除数不能为零！");
    }
    return a / b;
}

int main() {
    try {
        int result = divide(10, 2);
        std::cout << "10 / 2 = " << result << std::endl;

        result = divide(10, 0);  // 会抛出异常
        std::cout << "10 / 0 = " << result << std::endl;  // 不会执行
    } catch (const std::runtime_error& e) {
        std::cout << "捕获到异常: " << e.what() << std::endl;
    }

    std::cout << "程序继续执行" << std::endl;

    return 0;
}

