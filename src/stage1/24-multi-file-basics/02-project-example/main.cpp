// main.cpp - 项目主程序
#include <iostream>
#include "user.h"

int main() {
    User user("张三", 25);
    user.setOnline(true);
    user.printInfo();
    return 0;
}
