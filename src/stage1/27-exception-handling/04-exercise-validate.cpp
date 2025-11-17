#include <iostream>
#include <stdexcept>

void validateAge(int age) {
    if (age < 0) {
        throw std::invalid_argument("年龄不能为负数");
    }
    if (age > 150) {
        throw std::invalid_argument("年龄不能大于 150");
    }
    std::cout << "年龄验证通过: " << age << std::endl;
}

int main() {
    int ages[] = {25, -5, 200, 30};

    for (int age : ages) {
        try {
            validateAge(age);
        } catch (const std::invalid_argument& e) {
            std::cout << "验证失败: " << e.what() << std::endl;
        }
    }

    return 0;
}

