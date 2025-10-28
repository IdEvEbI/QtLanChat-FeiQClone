#include <iostream>

int main() {
    int target;
    int searchCount = 0;

    std::cout << "请输入目标数字（1-20）: ";
    std::cin >> target;

    std::cout << "开始查找..." << std::endl;
    for (int i = 1; i <= 20; i++) {
        searchCount++;
        if (i == target) {
            std::cout << "找到了！" << target << " 在第 " << searchCount << " 次查找" << std::endl;
            break;  // 找到目标，跳出循环
        }
    }

    return 0;
}
