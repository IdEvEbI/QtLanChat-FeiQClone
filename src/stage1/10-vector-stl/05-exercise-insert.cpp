#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {10, 20, 30, 40};

    int pos;
    int x;
    std::cout << "请输入插入位置和数值（如：2 99）: ";
    std::cin >> pos >> x;

    if (pos >= 0 && pos <= static_cast<int>(vec.size())) {
        vec.insert(vec.begin() + pos, x);
    } else {
        std::cout << "位置非法，未进行插入" << std::endl;
    }

    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

