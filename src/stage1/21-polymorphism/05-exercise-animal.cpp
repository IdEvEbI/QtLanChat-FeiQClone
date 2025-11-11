#include <iostream>
#include <string>

class Animal {
protected:
    std::string name;

public:
    Animal(const std::string& n) : name(n) {}

    virtual ~Animal() {}

    virtual void makeSound() = 0;  // 纯虚函数
};

class Dog : public Animal {
public:
    Dog(const std::string& n) : Animal(n) {}

    void makeSound() override {
        std::cout << name << " 说: 汪汪汪" << std::endl;
    }
};

class Cat : public Animal {
public:
    Cat(const std::string& n) : Animal(n) {}

    void makeSound() override {
        std::cout << name << " 说: 喵喵喵" << std::endl;
    }
};

class Bird : public Animal {
public:
    Bird(const std::string& n) : Animal(n) {}

    void makeSound() override {
        std::cout << name << " 说: 叽叽喳喳" << std::endl;
    }
};

int main() {
    Dog dog("旺财");
    Cat cat("咪咪");
    Bird bird("小鸟");

    Animal* animals[] = {&dog, &cat, &bird};

    for (int i = 0; i < 3; i++) {
        animals[i]->makeSound();  // 多态：根据实际类型调用相应的函数
    }

    return 0;
}
