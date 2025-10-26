#include <iostream>
#include <string>
#include <typeinfo>

int main() {
    std::cout << "=== auto 关键字示例 ===" << std::endl;

    // 使用 auto 声明变量
    auto age = 25;           // 推断为 int
    auto name = "张三";       // 推断为 const char*
    auto price = 19.99;      // 推断为 double
    auto isVip = true;       // 推断为 bool
    auto greeting = std::string("Hello");  // 推断为 std::string

    // 显示推断的类型
    std::cout << "age 类型: " << typeid(age).name() << std::endl;
    std::cout << "name 类型: " << typeid(name).name() << std::endl;
    std::cout << "price 类型: " << typeid(price).name() << std::endl;
    std::cout << "isVip 类型: " << typeid(isVip).name() << std::endl;
    std::cout << "greeting 类型: " << typeid(greeting).name() << std::endl;

    // 使用变量
    std::cout << "\n变量值:" << std::endl;
    std::cout << "年龄: " << age << std::endl;
    std::cout << "姓名: " << name << std::endl;
    std::cout << "价格: " << price << std::endl;
    std::cout << "VIP: " << isVip << std::endl;
    std::cout << "问候: " << greeting << std::endl;

    // 比较 auto 和显式声明
    std::cout << "\n=== auto vs 显式声明 ===" << std::endl;
    auto age2 = 25;           // auto 推断
    int age3 = 25;            // 显式声明
    std::cout << "auto age2 = 25: " << typeid(age2).name() << std::endl;
    std::cout << "int age3 = 25: " << typeid(age3).name() << std::endl;
    std::cout << "两者类型相同，效果等价" << std::endl;

    return 0;
}

