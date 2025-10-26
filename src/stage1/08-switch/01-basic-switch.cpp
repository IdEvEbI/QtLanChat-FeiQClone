// 现代 C++ 示例 - switch 分支基础
#include <iostream>

int main() {
    // 示例 1：整数选择
    std::cout << "=== switch 整数选择 ===" << std::endl;
    int choice = 2;

    switch (choice) {
        case 1:
            std::cout << "你选择了选项 1" << std::endl;
            break;
        case 2:
            std::cout << "你选择了选项 2" << std::endl;
            break;
        case 3:
            std::cout << "你选择了选项 3" << std::endl;
            break;
        default:
            std::cout << "无效的选择" << std::endl;
            break;
    }

    // 示例 2：字符选择
    std::cout << "\n=== switch 字符选择 ===" << std::endl;
    char grade = 'B';

    switch (grade) {
        case 'A':
            std::cout << "优秀" << std::endl;
            break;
        case 'B':
            std::cout << "良好" << std::endl;
            break;
        case 'C':
            std::cout << "及格" << std::endl;
            break;
        case 'D':
            std::cout << "不及格" << std::endl;
            break;
        default:
            std::cout << "无效等级" << std::endl;
            break;
    }

    // 示例 3：menu 菜单系统
    std::cout << "\n=== switch 菜单系统 ===" << std::endl;
    int menuChoice = 1;

    switch (menuChoice) {
        case 1:
            std::cout << ">>> 功能1：新建聊天" << std::endl;
            break;
        case 2:
            std::cout << ">>> 功能2：查看历史" << std::endl;
            break;
        case 3:
            std::cout << ">>> 功能3：用户设置" << std::endl;
            break;
        case 4:
            std::cout << ">>> 功能4：帮助" << std::endl;
            break;
        case 0:
            std::cout << ">>> 退出程序" << std::endl;
            break;
        default:
            std::cout << ">>> 无效选项" << std::endl;
            break;
    }

    // 示例 4：case 穿透（有意的）
    std::cout << "\n=== switch case 穿透 ===" << std::endl;
    int num = 3;

    switch (num) {
        case 1:
        case 2:
            std::cout << "数字是 1 或 2" << std::endl;
            break;
        case 3:
        case 4:
            std::cout << "数字是 3 或 4" << std::endl;
            break;
        case 5:
            std::cout << "数字是 5" << std::endl;
            break;
        default:
            std::cout << "其他数字" << std::endl;
            break;
    }

    return 0;
}

