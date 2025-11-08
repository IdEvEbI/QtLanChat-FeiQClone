#include <iostream>

int main() {
    int num = 100;
    int* ptr = &num;

    std::cout << "通过指针读取的值: " << *ptr << std::endl;

    *ptr = 200;
    std::cout << "通过指针修改后的值: " << num << std::endl;

    return 0;
}




