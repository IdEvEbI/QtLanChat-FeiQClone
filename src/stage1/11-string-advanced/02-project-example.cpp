// 项目中的实际应用示例
#include <iostream>
#include <string>

int main() {
    std::cout << "=== QtLanChat 消息处理 ===" << std::endl;

    // 模拟接收消息
    std::string rawMessage = "张三: 你好，今天天气不错";

    std::cout << "原始消息: " << rawMessage << std::endl;

    // 查找冒号位置（分割用户名和消息内容）
    size_t colonPos = rawMessage.find(":");  // find() 返回 size_t 类型
    if (colonPos != std::string::npos) {
        std::string sender = rawMessage.substr(0, colonPos);
        std::string content = rawMessage.substr(colonPos + 2);

        std::cout << "发送者: " << sender << std::endl;
        std::cout << "内容: " << content << std::endl;
    }

    // 判断消息长度
    if (rawMessage.length() > 100) {
        std::cout << "消息过长，建议分多条发送" << std::endl;
    } else {
        std::cout << "消息长度正常" << std::endl;
    }

    return 0;
}

