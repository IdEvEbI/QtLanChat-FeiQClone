// 项目中的实际应用示例
#include <iostream>
#include <string>

int main() {
    std::cout << "=== QtLanChat 消息广播系统 ===" << std::endl;
    
    // 模拟用户列表
    std::string users[5] = {"小丽", "小美", "小明", "小伟", "小强"};
    std::string message = "Hello from QtLanChat!";
    
    std::cout << "向所有在线用户发送广播：" << std::endl;
    std::cout << "消息内容：" << message << std::endl;
    std::cout << "\n发送进度：" << std::endl;
    
    // 使用 for 循环遍历并发送给每个用户
    for (int i = 0; i < 5; i++) {
        std::cout << "正在发送给 " << users[i] << "..." << std::endl;
        std::cout << ">>> [" << users[i] << "] 收到了消息" << std::endl;
    }
    
    std::cout << "\n所有用户已收到消息！" << std::endl;
    
    // 统计功能：使用嵌套 for 循环显示用户消息统计
    std::cout << "\n=== 用户消息统计表 ===" << std::endl;
    std::cout << "用户名\t消息数\t状态" << std::endl;
    
    for (int i = 0; i < 5; i++) {
        int messageCount = (i + 1) * 10;  // 模拟消息数
        std::cout << users[i] << "\t" << messageCount << "\t在线" << std::endl;
    }
    
    return 0;
}

