// 07-test-sort-filter.cpp
// 编程题 2：使用 Lambda 表达式实现复杂排序和过滤
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

struct Product {
    std::string name;
    double price;
};

int main() {
    std::vector<Product> products = {
        {"苹果", 5.5},
        {"香蕉", 3.2},
        {"橙子", 4.8},
        {"葡萄", 12.0},
        {"西瓜", 8.5}
    };

    std::cout << "=== 产品管理系统 ===" << std::endl;

    // 1. 按价格从低到高排序
    std::sort(products.begin(), products.end(),
        [](const Product& a, const Product& b) {
            return a.price < b.price;
        });

    std::cout << "\n=== 按价格排序（从低到高） ===" << std::endl;
    std::for_each(products.begin(), products.end(),
        [](const Product& p) {
            std::cout << p.name << ": " << std::fixed << std::setprecision(1)
                      << p.price << " 元" << std::endl;
        });

    // 2. 打印所有价格 >= 5.0 的产品
    std::cout << "\n=== 价格 >= 5.0 的产品 ===" << std::endl;
    std::for_each(products.begin(), products.end(),
        [](const Product& p) {
            if (p.price >= 5.0) {
                std::cout << p.name << ": " << std::fixed << std::setprecision(1)
                          << p.price << " 元" << std::endl;
            }
        });

    // 3. 统计价格 < 5.0 的产品数量
    int cheapCount = std::count_if(products.begin(), products.end(),
        [](const Product& p) {
            return p.price < 5.0;
        });
    std::cout << "\n价格 < 5.0 的产品数量: " << cheapCount << std::endl;

    return 0;
}

