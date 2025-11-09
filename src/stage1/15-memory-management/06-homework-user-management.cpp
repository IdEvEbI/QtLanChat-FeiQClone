#include <iostream>
#include <memory>
#include <vector>
#include <string>

struct User {
    std::string name;
    int age;
};

int main() {
    std::vector<std::unique_ptr<User>> users;

    // 添加用户
    users.push_back(std::make_unique<User>());
    users.back()->name = "张三";
    users.back()->age = 25;

    users.push_back(std::make_unique<User>());
    users.back()->name = "李四";
    users.back()->age = 30;

    // 显示所有用户
    std::cout << "=== 用户列表 ===" << std::endl;
    for (size_t i = 0; i < users.size(); i++) {
        std::cout << (i + 1) << ". " << users[i]->name 
                  << " (" << users[i]->age << "岁)" << std::endl;
    }

    // 删除第一个用户
    if (!users.empty()) {
        users.erase(users.begin());
        std::cout << "\n删除第一个用户后：" << std::endl;
        for (size_t i = 0; i < users.size(); i++) {
            std::cout << (i + 1) << ". " << users[i]->name 
                      << " (" << users[i]->age << "岁)" << std::endl;
        }
    }

    // 函数结束时，所有 unique_ptr 自动销毁，内存自动释放
    return 0;
}
