#include <iostream>

int main() {
    int num = 100;
    int& ref = num;

    std::cout << "通过引用读取的值: " << ref << std::endl;

    ref = 200;
    std::cout << "通过引用修改后的值: " << num << std::endl;

    return 0;
}
