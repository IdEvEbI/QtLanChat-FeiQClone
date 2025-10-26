#include <iostream>

int main() {
    char lightColor;
    std::cout << "请输入信号灯颜色（r=红色, y=黄色, g=绿色）: ";
    std::cin >> lightColor;

    std::cout << "\n=== 交通灯状态 ===" << std::endl;
    
    switch (lightColor) {
        case 'r':
        case 'R':
            std::cout << ">>> 红灯：停车等待" << std::endl;
            std::cout << ">>> 请保持静止" << std::endl;
            break;
        case 'y':
        case 'Y':
            std::cout << ">>> 黄灯：准备启动" << std::endl;
            std::cout << ">>> 请减速或准备启动" << std::endl;
            break;
        case 'g':
        case 'G':
            std::cout << ">>> 绿灯：通行" << std::endl;
            std::cout << ">>> 可以安全通过" << std::endl;
            break;
        default:
            std::cout << ">>> 无效的输入" << std::endl;
            std::cout << ">>> 请输入 r, y, 或 g" << std::endl;
            break;
    }

    return 0;
}

