// 现代 C++ 示例 - 枚举基础
#include <iostream>

// 定义用户状态枚举
enum UserStatus {
    Online,
    Offline,
    Away,
    Busy
};

int main() {
    // 声明枚举变量
    UserStatus user1Status = UserStatus::Online;
    UserStatus user2Status = UserStatus::Offline;

    // 输出枚举值
    std::cout << "=== 用户状态 ===" << std::endl;
    std::cout << "用户 1 状态: " << user1Status << std::endl;  // 输出: 0
    std::cout << "用户 2 状态: " << user2Status << std::endl;  // 输出: 1

    // 修改状态
    user1Status = UserStatus::Away;
    std::cout << "用户 1 新状态: " << user1Status << std::endl;  // 输出: 2

    return 0;
}
