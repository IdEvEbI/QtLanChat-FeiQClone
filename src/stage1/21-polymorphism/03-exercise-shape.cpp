#include <iostream>

class Shape {
public:
    virtual ~Shape() {}

    virtual void draw() = 0;  // 纯虚函数
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void draw() override {
        std::cout << "绘制圆形，半径: " << radius << std::endl;
    }
};

int main() {
    Circle circle(5.0);
    Shape* shape = &circle;
    shape->draw();  // 多态：调用 Circle 的 draw()

    return 0;
}
