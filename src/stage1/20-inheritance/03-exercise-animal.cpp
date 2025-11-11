#include <iostream>
#include <string>

class Animal {
protected:
    std::string name;

public:
    Animal(const std::string& n) : name(n) {}

    void printInfo() {
        std::cout << "动物名称: " << name << std::endl;
    }
};

class Dog : public Animal {
private:
    std::string breed;

public:
    Dog(const std::string& n, const std::string& b) : Animal(n), breed(b) {}

    void printDogInfo() {
        printInfo();  // 调用基类的成员函数
        std::cout << "品种: " << breed << std::endl;
    }
};

int main() {
    Dog dog("旺财", "金毛");
    dog.printDogInfo();

    return 0;
}
