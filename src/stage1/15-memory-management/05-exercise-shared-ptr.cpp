#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> ptr1 = std::make_shared<int>(42);
    std::cout << "ptr1 创建后，引用计数: " << ptr1.use_count() << std::endl;
    
    {
        std::shared_ptr<int> ptr2 = ptr1;
        std::cout << "ptr2 创建后，引用计数: " << ptr1.use_count() << std::endl;
        
        std::shared_ptr<int> ptr3 = ptr1;
        std::cout << "ptr3 创建后，引用计数: " << ptr1.use_count() << std::endl;
    }  // ptr2 和 ptr3 离开作用域，自动销毁
    
    std::cout << "ptr2 和 ptr3 销毁后，引用计数: " << ptr1.use_count() << std::endl;
    
    return 0;  // ptr1 销毁，内存自动释放
}
