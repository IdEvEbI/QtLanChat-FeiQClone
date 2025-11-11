// 练习 2：图形绘制系统（增强版）
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

class Shape {
protected:
    std::string color;

public:
    Shape(const std::string& c) : color(c) {}
    virtual ~Shape() {}

    std::string getColor() const { return color; }
    void setColor(const std::string& c) { color = c; }

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void draw() const = 0;
    virtual std::string getType() const = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(const std::string& c, double r) : Shape(c), radius(r) {}

    double getArea() const override {
        return 3.14159 * radius * radius;
    }

    double getPerimeter() const override {
        return 2 * 3.14159 * radius;
    }

    void draw() const override {
        std::cout << "绘制 " << color << " 的圆形，半径: " << radius << std::endl;
    }

    std::string getType() const override {
        return "Circle";
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(const std::string& c, double w, double h)
        : Shape(c), width(w), height(h) {}

    double getArea() const override {
        return width * height;
    }

    double getPerimeter() const override {
        return 2 * (width + height);
    }

    void draw() const override {
        std::cout << "绘制 " << color << " 的矩形，宽度: " << width 
                  << ", 高度: " << height << std::endl;
    }

    std::string getType() const override {
        return "Rectangle";
    }
};

class ShapeManager {
private:
    std::vector<std::unique_ptr<Shape>> shapes;
    const std::string filename = "shapes.txt";

public:
    void addShape(std::unique_ptr<Shape> shape) {
        shapes.push_back(std::move(shape));
    }

    void displayAll() const {
        for (size_t i = 0; i < shapes.size(); i++) {
            std::cout << "\n[" << (i + 1) << "] ";
            shapes[i]->draw();
            std::cout << "面积: " << shapes[i]->getArea() << std::endl;
            std::cout << "周长: " << shapes[i]->getPerimeter() << std::endl;
        }
    }

    void saveToFile() const {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& shape : shapes) {
                file << shape->getType() << " " << shape->getColor() << std::endl;
            }
            file.close();
            std::cout << "图形数据已保存到文件" << std::endl;
        } else {
            std::cout << "无法保存文件" << std::endl;
        }
    }
};

int main() {
    ShapeManager manager;

    manager.addShape(std::make_unique<Circle>("红色", 5.0));
    manager.addShape(std::make_unique<Rectangle>("蓝色", 4.0, 6.0));

    manager.displayAll();
    manager.saveToFile();

    return 0;
}
