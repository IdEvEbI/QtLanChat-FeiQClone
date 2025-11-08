#include <iostream>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    std::cout << "交换前: x = " << x << ", y = " << y << std::endl;

    swap(&x, &y);  // 传递地址
    std::cout << "交换后: x = " << x << ", y = " << y << std::endl;

    return 0;
}




