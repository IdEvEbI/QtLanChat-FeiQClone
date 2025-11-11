#include <iostream>
#include <string>

class Vehicle {
protected:
    std::string brand;

public:
    Vehicle(const std::string& b) : brand(b) {}

    void printInfo() {
        std::cout << "品牌: " << brand << std::endl;
    }
};

class Car : public Vehicle {
protected:
    std::string model;

public:
    Car(const std::string& b, const std::string& m) : Vehicle(b), model(m) {}

    void printCarInfo() {
        printInfo();
        std::cout << "型号: " << model << std::endl;
    }
};

class ElectricCar : public Car {
private:
    double batteryCapacity;

public:
    ElectricCar(const std::string& b, const std::string& m, double capacity)
        : Car(b, m), batteryCapacity(capacity) {}

    void printElectricCarInfo() {
        printCarInfo();
        std::cout << "电池容量: " << batteryCapacity << " kWh" << std::endl;
    }
};

int main() {
    ElectricCar car("特斯拉", "Model 3", 75.0);
    car.printElectricCarInfo();

    return 0;
}
