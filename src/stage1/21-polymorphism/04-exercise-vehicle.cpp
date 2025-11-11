#include <iostream>
#include <string>

class Vehicle {
protected:
    std::string brand;

public:
    Vehicle(const std::string& b) : brand(b) {}

    virtual ~Vehicle() {}

    virtual void start() {
        std::cout << brand << " 启动" << std::endl;
    }
};

class Car : public Vehicle {
public:
    Car(const std::string& b) : Vehicle(b) {}

    void start() override {
        std::cout << brand << " 汽车启动，引擎轰鸣" << std::endl;
    }
};

class Bike : public Vehicle {
public:
    Bike(const std::string& b) : Vehicle(b) {}

    void start() override {
        std::cout << brand << " 自行车启动，开始骑行" << std::endl;
    }
};

int main() {
    Car car("大众");
    Bike bike("永久");

    Vehicle* vehicles[] = {&car, &bike};

    for (int i = 0; i < 2; i++) {
        vehicles[i]->start();  // 多态：根据实际类型调用相应的函数
    }

    return 0;
}
