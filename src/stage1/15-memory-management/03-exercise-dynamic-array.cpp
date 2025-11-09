#include <iostream>

int main() {
    int* arr = new int[5];
    
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }
    
    std::cout << "数组内容: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    delete[] arr;
    arr = nullptr;
    
    return 0;
}
