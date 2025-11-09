#include <iostream>
#include <string>
#include <vector>

struct User {
    std::string name;
    int age;
};

void printUser(const User& user) {
    std::cout << "姓名: " << user.name << ", 年龄: " << user.age << std::endl;
}

void updateAge(User& user, int newAge) {
    user.age = newAge;
    std::cout << user.name << " 的年龄已更新为: " << newAge << std::endl;
}

void processUserList(const std::vector<User>& users) {
    std::cout << "用户列表：" << std::endl;
    for (const User& user : users) {  // 使用 const 引用遍历
        printUser(user);
    }
}

int main() {
    std::vector<User> users = {
        {"张三", 25},
        {"李四", 30},
        {"王五", 28}
    };

    std::cout << "=== 用户管理系统 ===" << std::endl;

    // 打印所有用户
    processUserList(users);

    // 更新年龄
    std::cout << "\n更新年龄：" << std::endl;
    updateAge(users[0], 26);  // 通过引用修改

    // 再次打印
    std::cout << "\n更新后的用户列表：" << std::endl;
    processUserList(users);

    return 0;
}
