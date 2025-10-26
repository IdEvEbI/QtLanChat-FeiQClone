// 项目中的实际应用示例
#include <iostream>

int main() {
    std::cout << "=== QtLanChat 菜单系统 ===" << std::endl;
    
    int choice = -1;  // 初始化选择
    
    while (choice != 0) {
        // 显示菜单
        std::cout << "\n--- 主菜单 ---" << std::endl;
        std::cout << "1. 发送消息" << std::endl;
        std::cout << "2. 查看历史" << std::endl;
        std::cout << "3. 用户设置" << std::endl;
        std::cout << "0. 退出程序" << std::endl;
        std::cout << "请选择: ";
        
        std::cin >> choice;
        
        if (choice == 1) {
            std::cout << ">>> 发送消息功能" << std::endl;
        } else if (choice == 2) {
            std::cout << ">>> 查看历史功能" << std::endl;
        } else if (choice == 3) {
            std::cout << ">>> 用户设置功能" << std::endl;
        } else if (choice == 0) {
            std::cout << ">>> 正在退出程序..." << std::endl;
        } else {
            std::cout << ">>> 无效选择，请重试" << std::endl;
        }
    }
    
    std::cout << "程序已退出，再见！" << std::endl;
    
    return 0;
}

