#include <iostream>
#include <string>

int main() {
    std::cout << "=== 字符串处理示例 ===" << std::endl;

    // C++ 字符串
    std::string firstName = "张";
    std::string lastName = "三";
    std::string fullName = firstName + lastName;

    std::cout << "姓: " << firstName << std::endl;
    std::cout << "名: " << lastName << std::endl;
    std::cout << "全名: " << fullName << std::endl;
    std::cout << "全名长度: " << fullName.length() << std::endl;

    return 0;
}

