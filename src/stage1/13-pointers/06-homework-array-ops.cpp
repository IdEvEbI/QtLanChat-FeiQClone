#include <iostream>

int* findMax(int arr[], int size) {
    if (size == 0) return nullptr;
    
    int* maxPtr = &arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > *maxPtr) {
            maxPtr = &arr[i];
        }
    }
    return maxPtr;
}

void updateValue(int* ptr, int newValue) {
    if (ptr != nullptr) {
        *ptr = newValue;
    }
}

int main() {
    int numbers[5] = {10, 30, 20, 50, 40};

    std::cout << "=== 数组操作程序 ===" << std::endl;
    std::cout << "原始数组: ";
    for (int i = 0; i < 5; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    int* maxPtr = findMax(numbers, 5);
    if (maxPtr != nullptr) {
        std::cout << "最大值: " << *maxPtr << std::endl;
    }

    updateValue(&numbers[2], 100);
    std::cout << "更新后数组: ";
    for (int i = 0; i < 5; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
