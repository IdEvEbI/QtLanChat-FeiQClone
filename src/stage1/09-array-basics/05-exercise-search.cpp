#include <iostream>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int target;
    int index = -1;  // -1 表示未找到

    std::cout << "请输入要查找的数字: ";
    std::cin >> target;

    // 查找元素
    for (int i = 0; i < 5; i++) {
        if (arr[i] == target) {
            index = i;
            break;  // 找到后退出循环
        }
    }

    // 输出结果
    if (index != -1) {
        std::cout << "找到了！索引位置: " << index << std::endl;
    } else {
        std::cout << "未找到" << std::endl;
    }

    return 0;
}
