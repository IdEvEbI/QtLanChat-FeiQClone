// 现代 C++ 示例 - 文件 I/O 基础
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct User {
    std::string name;
    int age;
};

// 保存用户数据到文件
void saveUsers(const std::vector<User>& users, const std::string& filename) {
    std::ofstream file(filename);

    if (file.is_open()) {
        for (const auto& user : users) {
            file << user.name << " " << user.age << std::endl;
        }
        file.close();
        std::cout << "数据已保存到文件: " << filename << std::endl;
    } else {
        std::cout << "无法打开文件: " << filename << std::endl;
    }
}

// 从文件加载用户数据
void loadUsers(std::vector<User>& users, const std::string& filename) {
    std::ifstream file(filename);

    if (file.is_open()) {
        users.clear();  // 清空现有数据
        std::string name;
        int age;

        while (file >> name >> age) {
            users.push_back({name, age});
        }

        file.close();
        std::cout << "数据已从文件加载: " << filename << std::endl;
        std::cout << "加载了 " << users.size() << " 个用户" << std::endl;
    } else {
        std::cout << "无法打开文件: " << filename << std::endl;
        std::cout << "将创建新文件" << std::endl;
    }
}

// 打印用户列表
void printUsers(const std::vector<User>& users) {
    std::cout << "\n=== 用户列表 ===" << std::endl;
    for (size_t i = 0; i < users.size(); i++) {
        std::cout << (i + 1) << ". " << users[i].name
                  << ", 年龄: " << users[i].age << std::endl;
    }
}

int main() {
    std::vector<User> users;
    const std::string filename = "users.txt";

    // 从文件加载数据
    std::cout << "=== 加载数据 ===" << std::endl;
    loadUsers(users, filename);
    printUsers(users);

    // 添加新用户
    std::cout << "\n=== 添加新用户 ===" << std::endl;
    users.push_back({"张三", 25});
    users.push_back({"李四", 30});
    users.push_back({"王五", 28});
    printUsers(users);

    // 保存数据到文件
    std::cout << "\n=== 保存数据 ===" << std::endl;
    saveUsers(users, filename);

    return 0;
}
