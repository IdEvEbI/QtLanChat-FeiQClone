#include <iostream>
#include <string>

int countChar(const std::string& str) {
    int count = 0;
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == 'a' || str[i] == 'A') {
            count++;
        }
    }
    return count;
}

int main() {
    std::string text = "Hello, this is a sample text";
    int result = countChar(text);
    std::cout << "字符 'a' 的个数: " << result << std::endl;

    return 0;
}
