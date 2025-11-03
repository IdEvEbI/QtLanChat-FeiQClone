#include <iostream>

double calculateAverage(double a, double b, double c) {
    return (a + b + c) / 3.0;
}

int main() {
    double result = calculateAverage(10.0, 20.0, 30.0);
    std::cout << "平均值: " << result << std::endl;
    return 0;
}

