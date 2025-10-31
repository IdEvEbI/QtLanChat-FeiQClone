#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;

    // 添加 1 到 10
    for (int i = 1; i <= 10; i++) {
        vec.push_back(i);
    }

    std::cout << "原始数据: ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // 删除所有偶数：使用迭代器配合 erase 安全删除
    for (auto it = vec.begin(); it != vec.end(); ) {
        if ((*it) % 2 == 0) {
            it = vec.erase(it);   // 返回下一个有效迭代器
        } else {
            ++it;
        }
    }

    std::cout << "删除偶数后: ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

