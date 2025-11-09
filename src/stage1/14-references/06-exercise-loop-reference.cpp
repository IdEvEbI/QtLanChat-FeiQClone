#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    std::cout << "原始数组: ";
    for (const int& num : numbers) {  // const 引用，只读
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 使用非 const 引用修改元素
    for (int& num : numbers) {  // 非 const 引用，可修改
        num *= 2;
    }

    std::cout << "修改后数组: ";
    for (const int& num : numbers) {  // const 引用，只读
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
