// main.cpp - 主程序文件
#include <iostream>
#include "user.h"

int main() {
    // 创建用户对象
    User user1("张三", 25);
    User user2("李四", 30);

    // 使用用户对象
    user1.printInfo();
    std::cout << std::endl;
    user2.printInfo();

    return 0;
}
