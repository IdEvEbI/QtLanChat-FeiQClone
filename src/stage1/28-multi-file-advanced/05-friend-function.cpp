// 05-friend-function.cpp
#include <iostream>
#include <cmath>

class Point {
private:
    int x, y;

    // 声明友元函数
    friend double distance(const Point& p1, const Point& p2);
    friend void printPoint(const Point& p);

public:
    Point(int x, int y) : x(x), y(y) {}
};

// 友元函数：计算两点之间的距离
double distance(const Point& p1, const Point& p2) {
    int dx = p1.x - p2.x;  // 直接访问私有成员
    int dy = p1.y - p2.y;
    return std::sqrt(dx * dx + dy * dy);
}

// 友元函数：打印点的坐标
void printPoint(const Point& p) {
    std::cout << "(" << p.x << ", " << p.y << ")";  // 直接访问私有成员
}

int main() {
    Point p1(0, 0);
    Point p2(3, 4);

    printPoint(p1);
    std::cout << " 到 ";
    printPoint(p2);
    std::cout << " 的距离: " << distance(p1, p2) << std::endl;

    return 0;
}

