// 优化版本：避免 std::endl 的 flush 开销
#include <iostream>

int main() {
    std::cout << "Hello, World!\n";  // 使用 \n 替代 std::endl
    return 0;
}
