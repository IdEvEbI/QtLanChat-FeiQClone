#include <iostream>
#include <stdexcept>
#include <string>

// 自定义异常类
class DivisionByZeroException : public std::runtime_error {
public:
    DivisionByZeroException()
        : std::runtime_error("除数不能为零") {}
};

int divide(int a, int b) {
    if (b == 0) {
        throw DivisionByZeroException();
    }
    return a / b;
}

int main() {
    int testCases[][2] = {{10, 2}, {10, 0}, {15, 3}, {20, 0}};

    for (auto& testCase : testCases) {
        int a = testCase[0];
        int b = testCase[1];

        try {
            int result = divide(a, b);
            std::cout << a << " / " << b << " = " << result << std::endl;
        } catch (const DivisionByZeroException& e) {
            std::cout << "错误: " << e.what() << std::endl;
        }
    }

    return 0;
}

