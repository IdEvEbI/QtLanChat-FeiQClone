// 项目中的实际应用示例
#include <iostream>
#include <string>

int main() {
    // 用户信息变量
    std::string userName = "小丽";
    int userAge = 18;
    bool isOnline = true;

    // 系统配置常量
    const int MAX_MESSAGE_LENGTH = 1000;
    const std::string SERVER_ADDRESS = "192.168.1.100";
    const int DEFAULT_PORT = 8080;

    // 聊天消息变量
    std::string messageContent = "Hello, QtLanChat!";
    int messageCount = 1;

    // 显示用户信息
    std::cout << "=== QtLanChat 用户信息 ===" << std::endl;
    std::cout << "用户名: " << userName << std::endl;
    std::cout << "年龄: " << userAge << std::endl;
    std::cout << "在线状态: " << isOnline << std::endl;
    std::cout << "服务器: " << SERVER_ADDRESS << ":" << DEFAULT_PORT << std::endl;
    std::cout << "消息: " << messageContent << std::endl;
    std::cout << "消息长度: " << messageContent.length() << " 字符" << std::endl;
    std::cout << "最大消息长度: " << MAX_MESSAGE_LENGTH << " 字符" << std::endl;
    std::cout << "消息数量: " << messageCount << std::endl;

    return 0;
}