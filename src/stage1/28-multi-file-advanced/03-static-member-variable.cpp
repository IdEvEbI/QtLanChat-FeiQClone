// 03-static-member-variable.cpp
#include <iostream>
#include <string>

class Counter {
private:
    static int count;               // 静态成员变量声明

public:
    Counter() {
        count++;                    // 每次创建对象时增加计数
    }

    static int getCount() {
        return count;
    }
};

int Counter::count = 0;             // 静态成员变量定义（必须在类外）

int main() {
    std::cout << "初始计数: " << Counter::getCount() << std::endl;

    Counter c1;
    std::cout << "创建 1 个对象后: " << Counter::getCount() << std::endl;

    Counter c2, c3;
    std::cout << "创建 3 个对象后: " << Counter::getCount() << std::endl;

    return 0;
}

