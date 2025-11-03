#include <iostream>
#include <string>

int main() {
    std::string username;

    std::cout << "请输入用户名: ";
    std::cin >> username;  // 注意：std::cin >> 无法读取包含空格的字符串，会在空格处停止

    // 检查长度
    if (username.length() < 3) {
        std::cout << "用户名太短，至少需要 3 个字符" << std::endl;
        return 0;
    }

    // 检查空格（简化版：使用 find）
    if (username.find(" ") != std::string::npos) {
        std::cout << "用户名不能包含空格" << std::endl;
        return 0;
    }

    std::cout << "用户名验证通过: " << username << std::endl;

    return 0;
}

