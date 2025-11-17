// 01-namespace-basic.cpp
#include <iostream>
#include <string>

// 定义命名空间
namespace MathUtils {
    int add(int a, int b) {
        return a + b;
    }

    int multiply(int a, int b) {
        return a * b;
    }
}

namespace StringUtils {
    std::string add(const std::string& a, const std::string& b) {
        return a + b;
    }
}

int main() {
    // 使用命名空间限定符
    int sum = MathUtils::add(5, 3);
    std::cout << "5 + 3 = " << sum << std::endl;

    std::string result = StringUtils::add("Hello", " World");
    std::cout << result << std::endl;

    // 使用 using 声明
    using MathUtils::multiply;
    int product = multiply(4, 5);
    std::cout << "4 * 5 = " << product << std::endl;

    return 0;
}

