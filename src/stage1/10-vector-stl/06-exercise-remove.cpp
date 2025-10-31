#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 2, 4, 2, 5};
    int x;
    std::cout << "要删除的值: ";
    std::cin >> x;

    for (auto it = vec.begin(); it != vec.end(); ) {
        if (*it == x) {
            it = vec.erase(it);
        } else {
            ++it;
        }
    }

    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

