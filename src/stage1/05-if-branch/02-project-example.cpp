// 项目中的实际应用示例
#include <iostream>

int main() {
    std::cout << "=== QtLanChat 权限控制 ===" << std::endl;
    std::cout << "请输入年龄: ";

    int userAge;
    std::cin >> userAge;  // 用户输入年龄

    std::cout << "请输入VIP状态（1=是，0=否）: ";

    int vipStatus;
    std::cin >> vipStatus;
    bool isVip = (vipStatus == 1);

    int messageCount = 5;

    // 年龄判断
    if (userAge >= 18) {
        std::cout << "年龄: " << userAge << "岁 - 已成年" << std::endl;

        // 嵌套判断：VIP状态
        if (isVip) {
            std::cout << "用户类型：VIP用户" << std::endl;

            // 嵌套判断：消息数量
            if (messageCount >= 10) {
                std::cout << "消息较多，建议清理历史记录" << std::endl;
            } else {
                std::cout << "消息数量正常" << std::endl;
            }
        } else {
            std::cout << "用户类型：普通用户" << std::endl;
            std::cout << "部分功能受限" << std::endl;
        }
    } else {
        std::cout << "年龄: " << userAge << "岁 - 未成年" << std::endl;
        std::cout << "访问受限，部分功能不可用" << std::endl;
    }

    return 0;
}

