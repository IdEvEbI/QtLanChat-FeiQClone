// 06-forward-declaration.cpp
#include <iostream>
#include <string>

// 前向声明
class Point;

// 函数声明：使用前向声明的类
void printPoint(const Point& p);

class Point {
private:
    int x, y;

    friend void printPoint(const Point& p);  // 友元函数

public:
    Point(int x, int y) : x(x), y(y) {}
};

// 函数定义：需要 Point 的完整定义
void printPoint(const Point& p) {
    std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;
}

int main() {
    Point p(3, 4);
    printPoint(p);
    return 0;
}

