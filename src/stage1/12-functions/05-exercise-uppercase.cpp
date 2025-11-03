#include <iostream>
#include <string>

std::string toUpperCase(std::string str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';  // 转换为大写
        }
    }
    return str;
}

int main() {
    std::string text = "Hello World";
    std::string upper = toUpperCase(text);
    std::cout << "原字符串: " << text << std::endl;
    std::cout << "转换后: " << upper << std::endl;
    return 0;
}

