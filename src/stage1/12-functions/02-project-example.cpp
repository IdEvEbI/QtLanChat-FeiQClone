// 项目中的实际应用示例
#include <iostream>
#include <string>

// 函数 1：验证用户名长度
bool isValidUsername(std::string username) {
    return username.length() >= 3 && username.length() <= 20;
}

// 函数 2：格式化消息
std::string formatMessage(std::string sender, std::string content) {
    return "[" + sender + "] " + content;
}

// 函数 3：检查消息是否为空
bool isEmptyMessage(std::string message) {
    // 方法1：使用 empty() 检查是否为空字符串
    if (message.empty()) {
        return true;
    }
    // 方法2：检查是否只包含空格（简化版：遍历检查）
    for (size_t i = 0; i < message.length(); i++) {
        if (message[i] != ' ') {
            return false;  // 发现非空格字符，不是空消息
        }
    }
    return true;  // 全是空格，视为空消息
}

// 函数 4：计算消息长度（字节数）
int getMessageLength(std::string message) {
    return static_cast<int>(message.length());
}

int main() {
    std::cout << "=== QtLanChat 函数应用 ===" << std::endl;

    // 使用函数验证用户名
    std::string username = "张三";
    if (isValidUsername(username)) {
        std::cout << "用户名有效: " << username << std::endl;
    } else {
        std::cout << "用户名无效（长度应在 3-20 之间）" << std::endl;
    }

    // 使用函数格式化消息
    std::string formatted = formatMessage("张三", "你好，今天天气不错");
    std::cout << "\n格式化后的消息: " << formatted << std::endl;

    // 使用函数检查消息
    std::string message1 = "Hello";
    std::string message2 = "   ";
    std::cout << "\n消息检查:" << std::endl;
    std::cout << "message1 是否为空: " << (isEmptyMessage(message1) ? "是" : "否") << std::endl;
    std::cout << "message2 是否为空: " << (isEmptyMessage(message2) ? "是" : "否") << std::endl;

    // 使用函数计算长度
    std::cout << "\n消息长度: " << getMessageLength(formatted) << " 字节" << std::endl;

    return 0;
}

