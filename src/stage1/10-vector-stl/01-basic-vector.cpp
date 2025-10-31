// 现代 C++ 示例 - vector 基础
#include <iostream>
#include <vector>

int main() {
    // 示例 1：声明和使用 vector
    std::cout << "=== 基本使用 ===" << std::endl;
    std::vector<int> vec;

    vec.push_back(10);              // 添加元素
    vec.push_back(20);
    vec.push_back(30);

    std::cout << "第一个元素: " << vec[0] << std::endl;
    std::cout << "向量大小: " << vec.size() << std::endl;

    // 示例 2：遍历 vector
    std::cout << "\n=== 遍历 vector ===" << std::endl;
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // 示例 3：访问和修改元素
    std::cout << "\n=== 修改元素 ===" << std::endl;
    vec[0] = 100;                   // 修改第一个元素
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // 示例 4：删除元素
    std::cout << "\n=== 删除元素 ===" << std::endl;
    vec.pop_back();                 // 删除最后一个元素
    std::cout << "删除后的大小: " << vec.size() << std::endl;
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // 示例 5：判断是否为空
    std::cout << "\n=== 判断是否为空 ===" << std::endl;
    if (!vec.empty()) {
        std::cout << "vector 不为空，包含 " << vec.size() << " 个元素" << std::endl;
    }

    // 示例 6：在中间插入元素（insert）
    std::cout << "\n=== 在中间插入元素 ===" << std::endl;
    std::vector<int> v1 = {10, 20, 30, 40};
    std::cout << "插入前: ";
    for (size_t i = 0; i < v1.size(); i++) {
        std::cout << v1[i] << " ";
    }
    std::cout << std::endl;
    
    v1.insert(v1.begin() + 2, 99);   // 在索引2之前插入 99，结果：10 20 99 30 40
    std::cout << "插入后: ";
    for (size_t i = 0; i < v1.size(); i++) {
        std::cout << v1[i] << " ";
    }
    std::cout << std::endl;

    // 示例 7：删除中间元素与批量删除（erase）
    std::cout << "\n=== 删除中间元素与批量删除 ===" << std::endl;
    std::vector<int> v2 = {1, 2, 3, 4, 5, 6};
    std::cout << "原始数据: ";
    for (size_t i = 0; i < v2.size(); i++) {
        std::cout << v2[i] << " ";
    }
    std::cout << std::endl;

    v2.erase(v2.begin() + 1);        // 删除索引1处的元素（2）=> 1 3 4 5 6
    std::cout << "删除索引1后: ";
    for (size_t i = 0; i < v2.size(); i++) {
        std::cout << v2[i] << " ";
    }
    std::cout << std::endl;

    // 遍历删除所有偶数：it 是一个"位置标记"（迭代器），用于遍历和定位元素
    // erase 删除后会返回下一个有效位置，必须用返回值更新 it（安全做法）
    for (auto it = v2.begin(); it != v2.end(); ) {
        if ((*it) % 2 == 0) {
            it = v2.erase(it);       // 删除偶数，并用返回值更新位置标记
        } else {
            ++it;                    // 不是偶数，移动到下一个位置
        }
    }
    // 结果：1 3 5
    std::cout << "删除所有偶数后: ";
    for (size_t i = 0; i < v2.size(); i++) {
        std::cout << v2[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

