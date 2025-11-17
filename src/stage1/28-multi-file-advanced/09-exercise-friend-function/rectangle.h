#pragma once

class Rectangle {
private:
    double width;
    double height;

    friend double calculateTotalArea(const Rectangle& r1, const Rectangle& r2);

public:
    Rectangle(double width, double height);
    double getArea() const;
};

