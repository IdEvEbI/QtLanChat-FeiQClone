#include <iostream>
#include <string>

int main() {
    std::string str;
    char target;

    std::cout << "请输入一个字符串: ";
    std::cin >> str;

    std::cout << "请输入要查找的字符: ";
    std::cin >> target;

    // 将字符转换为字符串
    std::string targetStr = "";
    targetStr += target;

    int count = 0;
    size_t pos = 0;

    // 循环查找所有出现的位置
    while ((pos = str.find(targetStr, pos)) != std::string::npos) {
        count++;
        pos++;  // 从下一个位置继续查找
    }

    std::cout << "字符 '" << target << "' 出现了 " << count << " 次" << std::endl;

    return 0;
}

