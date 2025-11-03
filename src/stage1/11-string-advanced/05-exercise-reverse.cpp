#include <iostream>
#include <string>

int main() {
    std::string str;

    std::cout << "请输入一个字符串: ";
    std::cin >> str;

    std::cout << "原字符串: " << str << std::endl;

    // 反转字符串
    std::string reversed = "";
    // 注意：使用 static_cast<int> 来避免 size_t 减到负数的问题
    for (int i = static_cast<int>(str.length()) - 1; i >= 0; i--) {
        reversed += str[i];  // 从后往前拼接
    }

    std::cout << "反转后: " << reversed << std::endl;

    return 0;
}

