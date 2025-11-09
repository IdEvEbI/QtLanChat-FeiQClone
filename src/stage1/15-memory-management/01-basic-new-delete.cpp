// 现代 C++ 示例 - 动态内存分配基础
#include <iostream>

int main() {
    // 示例 1：分配单个整数
    std::cout << "=== 分配单个对象 ===" << std::endl;
    int* ptr = new int(100);
    std::cout << "分配的值: " << *ptr << std::endl;
    *ptr = 200;
    std::cout << "修改后的值: " << *ptr << std::endl;
    delete ptr;                     // 释放内存
    ptr = nullptr;                  // 置空

    // 示例 2：分配数组
    std::cout << "\n=== 分配数组 ===" << std::endl;
    int* arr = new int[5];
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;
    }
    std::cout << "数组内容: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    delete[] arr;                   // 释放数组（必须用 delete[]）
    arr = nullptr;

    // 示例 3：分配失败处理（简化版）
    std::cout << "\n=== 内存分配完成 ===" << std::endl;

    return 0;
}
