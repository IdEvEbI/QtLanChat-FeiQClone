#include <iostream>

int main() {
    int choice = 0;
    
    while (choice != 4) {
        std::cout << "\n=== 简单菜单系统 ===" << std::endl;
        std::cout << "1. 显示当前用户" << std::endl;
        std::cout << "2. 发送消息" << std::endl;
        std::cout << "3. 查看消息历史" << std::endl;
        std::cout << "4. 退出" << std::endl;
        std::cout << "请选择: ";
        
        choice = 2;  // 模拟用户输入
        
        if (choice == 1) {
            std::cout << "当前用户：张三" << std::endl;
        } else if (choice == 2) {
            std::cout << "消息已发送！" << std::endl;
        } else if (choice == 3) {
            std::cout << "消息历史：无" << std::endl;
        } else if (choice == 4) {
            std::cout << "退出系统" << std::endl;
        } else {
            std::cout << "无效选择！" << std::endl;
        }
    }
    
    return 0;
}

