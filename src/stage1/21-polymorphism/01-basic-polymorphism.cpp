// 现代 C++ 示例 - 多态基础
#include <iostream>
#include <string>

// 基类：动物类（抽象类）
class Animal {
protected:
    std::string name;

public:
    Animal(const std::string& n) : name(n) {}

    virtual ~Animal() {  // 虚析构函数
        std::cout << name << " 被销毁" << std::endl;
    }

    virtual void makeSound() = 0;  // 纯虚函数

    virtual void printInfo() {  // 虚函数
        std::cout << "动物名称: " << name << std::endl;
    }
};

// 派生类：狗
class Dog : public Animal {
public:
    Dog(const std::string& n) : Animal(n) {}

    void makeSound() override {  // 实现纯虚函数
        std::cout << name << " 说: 汪汪汪" << std::endl;
    }

    void printInfo() override {  // 重写虚函数
        std::cout << "这是一只狗，名字叫: " << name << std::endl;
    }
};

// 派生类：猫
class Cat : public Animal {
public:
    Cat(const std::string& n) : Animal(n) {}

    void makeSound() override {  // 实现纯虚函数
        std::cout << name << " 说: 喵喵喵" << std::endl;
    }

    void printInfo() override {  // 重写虚函数
        std::cout << "这是一只猫，名字叫: " << name << std::endl;
    }
};

// 使用多态的函数
void playWithAnimal(Animal* animal) {
    animal->printInfo();
    animal->makeSound();
}

int main() {
    // 创建派生类对象
    Dog dog("旺财");
    Cat cat("咪咪");

    // 使用基类指针调用函数（多态）
    Animal* animal1 = &dog;
    Animal* animal2 = &cat;

    std::cout << "=== 使用多态 ===" << std::endl;
    playWithAnimal(animal1);  // 调用 Dog 的函数
    std::cout << std::endl;
    playWithAnimal(animal2);  // 调用 Cat 的函数

    return 0;
}
