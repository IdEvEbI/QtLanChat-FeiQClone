// 项目中的实际应用示例
#include <iostream>
#include <string>

int main() {
    // 用户信息变量
    std::string userName = "小丽";
    int userAge = 18;
    double userHeight = 1.65;
    bool isVip = true;
    char gender = 'F';

    // 系统配置常量
    const int MAX_MESSAGE_LENGTH = 1000;
    const std::string SERVER_ADDRESS = "192.168.1.100";
    const int DEFAULT_PORT = 8080;

    // 聊天消息变量
    std::string messageContent = "Hello, QtLanChat!";
    int messageCount = 1;
    long long timestamp = 1698123456789LL;

    // 显示用户信息
    std::cout << "=== QtLanChat 用户信息 ===" << std::endl;
    std::cout << "用户名: " << userName << std::endl;
    std::cout << "年龄: " << userAge << "岁" << std::endl;
    std::cout << "身高: " << userHeight << "米" << std::endl;
    std::cout << "性别: " << gender << std::endl;
    std::cout << "VIP状态: " << isVip << std::endl;
    std::cout << "服务器: " << SERVER_ADDRESS << ":" << DEFAULT_PORT << std::endl;
    std::cout << "消息: " << messageContent << std::endl;
    std::cout << "消息长度: " << messageContent.length() << " 字符" << std::endl;
    std::cout << "最大消息长度: " << MAX_MESSAGE_LENGTH << " 字符" << std::endl;
    std::cout << "消息数量: " << messageCount << std::endl;
    std::cout << "时间戳: " << timestamp << std::endl;

    // 类型大小信息
    std::cout << "\n=== 数据类型大小 ===" << std::endl;
    std::cout << "int 大小: " << sizeof(int) << " 字节" << std::endl;
    std::cout << "double 大小: " << sizeof(double) << " 字节" << std::endl;
    std::cout << "bool 大小: " << sizeof(bool) << " 字节" << std::endl;
    std::cout << "char 大小: " << sizeof(char) << " 字节" << std::endl;
    std::cout << "long long 大小: " << sizeof(long long) << " 字节" << std::endl;

    return 0;
}

