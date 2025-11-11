#include <iostream>

class Shape {
public:
    virtual ~Shape() {}

    virtual void draw() = 0;  // 纯虚函数
    virtual double getArea() = 0;  // 纯虚函数
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void draw() override {
        std::cout << "绘制圆形，半径: " << radius << std::endl;
    }

    double getArea() override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    void draw() override {
        std::cout << "绘制矩形，宽度: " << width << ", 高度: " << height << std::endl;
    }

    double getArea() override {
        return width * height;
    }
};

int main() {
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);

    Shape* shapes[] = {&circle, &rectangle};

    for (int i = 0; i < 2; i++) {
        shapes[i]->draw();  // 多态
        std::cout << "面积: " << shapes[i]->getArea() << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
