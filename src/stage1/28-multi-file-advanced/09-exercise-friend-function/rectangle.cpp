#include "rectangle.h"

Rectangle::Rectangle(double width, double height)
    : width(width), height(height) {}

double Rectangle::getArea() const {
    return width * height;
}

// 友元函数定义
double calculateTotalArea(const Rectangle& r1, const Rectangle& r2) {
    return r1.width * r1.height + r2.width * r2.height;  // 直接访问私有成员
}

