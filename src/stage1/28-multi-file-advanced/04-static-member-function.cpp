// 04-static-member-function.cpp
#include <iostream>
#include <cmath>

class MathHelper {
public:
    // 静态成员函数：计算平方
    static double square(double x) {
        return x * x;
    }

    // 静态成员函数：计算平方根
    static double sqrt(double x) {
        return std::sqrt(x);
    }

    // 静态成员函数：计算两点之间的距离
    static double distance(double x1, double y1, double x2, double y2) {
        double dx = x2 - x1;
        double dy = y2 - y1;
        return std::sqrt(dx * dx + dy * dy);
    }
};

int main() {
    // 通过类名直接调用，不需要创建对象
    double result1 = MathHelper::square(5.0);
    std::cout << "5.0 的平方: " << result1 << std::endl;

    double result2 = MathHelper::sqrt(16.0);
    std::cout << "16.0 的平方根: " << result2 << std::endl;

    double dist = MathHelper::distance(0, 0, 3, 4);
    std::cout << "点 (0,0) 到 (3,4) 的距离: " << dist << std::endl;

    return 0;
}

