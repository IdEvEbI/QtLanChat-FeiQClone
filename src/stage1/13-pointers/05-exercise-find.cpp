#include <iostream>

int* findValue(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return &arr[i];  // 返回指向元素的指针
        }
    }
    return nullptr;  // 未找到
}

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};

    int* found = findValue(numbers, 5, 30);
    if (found != nullptr) {
        std::cout << "找到值: " << *found << std::endl;
        std::cout << "位置: " << (found - numbers) << std::endl;  // 指针算术
    } else {
        std::cout << "未找到" << std::endl;
    }

    return 0;
}
