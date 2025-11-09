#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int> ptr = std::make_unique<int>(100);
    
    std::cout << "初始值: " << *ptr << std::endl;
    
    *ptr = 200;
    std::cout << "修改后的值: " << *ptr << std::endl;
    
    // 不需要手动 delete，自动释放
    return 0;
}
