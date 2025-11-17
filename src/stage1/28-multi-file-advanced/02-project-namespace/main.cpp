#include <iostream>
#include "math_utils.h"
#include "string_utils.h"

int main() {
    // 使用命名空间限定符，避免冲突
    int sum = MathUtils::add(10, 20);
    std::cout << "10 + 20 = " << sum << std::endl;

    std::string result = StringUtils::add("Hello", " World");
    std::cout << result << std::endl;

    std::string upper = StringUtils::toUpper("hello");
    std::cout << upper << std::endl;

    return 0;
}

