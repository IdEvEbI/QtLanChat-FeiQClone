// 项目中的实际应用示例
#include <iostream>

int main() {
    // 用户信息
    int messageCount = 0;
    int userAge = 20;
    bool isVip = true;

    // 模拟收到消息（使用 += 运算符）
    messageCount += 1;  // messageCount = messageCount + 1
    std::cout << "收到新消息！当前消息数: " << messageCount << std::endl;

    // 年龄判断（使用比较和逻辑运算符）
    bool canAccess = (userAge >= 18) && isVip;
    std::cout << "年龄: " << userAge << ", VIP: " << isVip << std::endl;
    std::cout << "能否访问高级功能: " << canAccess << std::endl;

    // 消息状态（使用取余运算符检查奇偶数）
    if (messageCount % 2 == 0) {
        std::cout << "消息数量为偶数" << std::endl;
    } else {
        std::cout << "消息数量为奇数" << std::endl;
    }

    return 0;
}

