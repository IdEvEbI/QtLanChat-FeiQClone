// 现代 C++ 示例 - 引用基础
#include <iostream>

int main() {
    // 1. 引用声明和初始化
    int value = 50;
    int& ref = value;  // ref 是 value 的别名

    std::cout << "=== 引用基础 ===" << std::endl;
    std::cout << "value 的值: " << value << std::endl;
    std::cout << "ref 的值: " << ref << std::endl;
    std::cout << "value 的地址: " << &value << std::endl;
    std::cout << "ref 的地址: " << &ref << std::endl;  // 地址相同！

    // 2. 通过引用修改值
    ref = 200;
    std::cout << "\n通过引用修改后：" << std::endl;
    std::cout << "value 的值: " << value << std::endl;
    std::cout << "ref 的值: " << ref << std::endl;

    // 3. 直接修改原变量，引用也会变化
    value = 300;
    std::cout << "\n直接修改 value 后：" << std::endl;
    std::cout << "value 的值: " << value << std::endl;
    std::cout << "ref 的值: " << ref << std::endl;

    // 4. 引用不能重新绑定
    int value2 = 100;
    // ref = value2;  // 这不是重新绑定！这是将 value2 的值赋给 value
    std::cout << "\n尝试'重新绑定'（实际是赋值）：" << std::endl;
    ref = value2;  // 等价于 value = value2;
    std::cout << "value 的值: " << value << std::endl;
    std::cout << "value2 的值: " << value2 << std::endl;
    std::cout << "ref 的地址仍然是 value 的地址: " << (&ref == &value ? "是" : "否") << std::endl;

    return 0;
}
