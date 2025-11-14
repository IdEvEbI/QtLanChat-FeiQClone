#include <iostream>
#include "user_manager.h"

int main() {
    UserManager manager;
    
    // 添加用户
    manager.addUser(User("小美", 25));
    manager.addUser(User("小丽", 22));
    manager.addUser(User("阿伟", 28));
    manager.addUser(User("小明", 20));
    
    // 打印所有用户
    manager.printAllUsers();
    
    // 打印年龄 >= 25 的用户
    manager.printUsersByAge(25);
    
    // 按年龄排序
    manager.sortUsersByAge();
    std::cout << "\n=== 按年龄排序后 ===" << std::endl;
    manager.printAllUsers();
    
    // 统计年龄 >= 25 的用户数量
    int count = manager.countUsersByAge(25);
    std::cout << "\n年龄 >= 25 的用户数量: " << count << std::endl;
    
    return 0;
}


