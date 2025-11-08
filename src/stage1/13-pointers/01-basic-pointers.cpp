// 现代 C++ 示例 - 指针基础
#include <iostream>

int main() {
    // 1. 指针声明和初始化
    int num = 42;
    int* ptr = &num;  // ptr 存储 num 的地址

    std::cout << "=== 指针基础 ===" << std::endl;
    std::cout << "num 的值: " << num << std::endl;
    std::cout << "num 的地址: " << &num << std::endl;
    std::cout << "ptr 的值（地址）: " << ptr << std::endl;
    std::cout << "ptr 指向的值: " << *ptr << std::endl;

    // 2. 通过指针修改值
    *ptr = 100;
    std::cout << "\n通过指针修改后：" << std::endl;
    std::cout << "num 的值: " << num << std::endl;
    std::cout << "*ptr 的值: " << *ptr << std::endl;

    // 3. 指针可以重新指向其他变量
    int num2 = 200;
    ptr = &num2;  // ptr 现在指向 num2
    std::cout << "\n指针重新指向 num2：" << std::endl;
    std::cout << "num 的值: " << num << std::endl;
    std::cout << "num2 的值: " << num2 << std::endl;
    std::cout << "*ptr 的值: " << *ptr << std::endl;

    // 4. 空指针
    int* nullPtr = nullptr;  // 空指针，不指向任何对象
    std::cout << "\n空指针：" << std::endl;
    std::cout << "nullPtr 的值: " << nullPtr << std::endl;
    // *nullPtr = 10;  // 危险！不能解引用空指针

    return 0;
}
