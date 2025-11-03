#include <iostream>
#include <string>

int main() {
    std::string message;

    std::cout << "请输入消息: ";
    // 📌 新知识点 - std::getline() 函数
    // 功能：读取一整行输入（包括空格），直到遇到换行符
    // 语法：std::getline(std::cin, 字符串变量)
    // 与 std::cin >> 的区别：
    //   - std::cin >> message：只能读取到第一个空格或换行符之前的内容
    //   - std::getline(std::cin, message)：读取一整行，包括空格
    // 示例：如果输入 "Hello World"
    //   - std::cin >> message：message = "Hello"（只读取到空格前）
    //   - std::getline(std::cin, message)：message = "Hello World"（读取整行）
    std::getline(std::cin, message);

    // 添加时间戳前缀（简化版）
    std::string formatted = "[2025-10-26] " + message;

    // 检查长度
    if (message.length() > 100) {
        std::cout << "警告：消息过长" << std::endl;
    }

    std::cout << "格式化后的消息: " << formatted << std::endl;

    return 0;
}

