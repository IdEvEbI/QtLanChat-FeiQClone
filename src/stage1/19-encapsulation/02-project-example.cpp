// 项目中的实际应用示例
#include <iostream>
#include <string>
#include <vector>

// 用户类（使用封装）
class User {
private:
    std::string name;
    int age;
    std::string password;
    bool isOnline;

public:
    // 构造函数
    User(const std::string& userName, int userAge) {
        name = userName;
        age = userAge;
        password = "";
        isOnline = false;
    }

    // Getter：获取姓名
    std::string getName() const {
        return name;
    }

    // Getter：获取年龄
    int getAge() const {
        return age;
    }

    // Getter：获取在线状态
    bool getIsOnline() const {
        return isOnline;
    }

    // Setter：设置姓名（带验证）
    void setName(const std::string& newName) {
        if (!newName.empty() && newName.length() <= 50) {
            name = newName;
        } else {
            std::cout << "姓名长度必须在 1-50 之间" << std::endl;
        }
    }

    // Setter：设置年龄（带验证）
    void setAge(int newAge) {
        if (newAge > 0 && newAge < 150) {
            age = newAge;
        } else {
            std::cout << "年龄必须在 0-150 之间" << std::endl;
        }
    }

    // Setter：设置密码（带验证）
    void setPassword(const std::string& pwd) {
        if (pwd.length() >= 6) {
            password = pwd;
            std::cout << "密码设置成功" << std::endl;
        } else {
            std::cout << "密码长度至少 6 位" << std::endl;
        }
    }

    // 验证密码
    bool checkPassword(const std::string& pwd) const {
        return password == pwd;
    }

    // 设置在线状态
    void setOnline(bool status) {
        isOnline = status;
        std::cout << name << " 的状态已更新为: " << (status ? "在线" : "离线") << std::endl;
    }

    // 打印用户信息
    void printInfo() const {
        std::cout << "=== 用户信息 ===" << std::endl;
        std::cout << "姓名: " << name << std::endl;
        std::cout << "年龄: " << age << std::endl;
        std::cout << "在线状态: " << (isOnline ? "在线" : "离线") << std::endl;
    }
};

// 用户管理类（使用封装）
class UserManager {
private:
    std::vector<User> users;

public:
    // 添加用户
    void addUser(const std::string& name, int age) {
        users.push_back(User(name, age));
        std::cout << "添加用户: " << name << std::endl;
    }

    // 查找用户（按姓名）
    User* findUser(const std::string& name) {
        for (size_t i = 0; i < users.size(); i++) {
            if (users[i].getName() == name) {
                return &users[i];
            }
        }
        return nullptr;
    }

    // 显示所有用户
    void printAllUsers() {
        std::cout << "\n=== 用户列表 ===" << std::endl;
        for (size_t i = 0; i < users.size(); i++) {
            users[i].printInfo();
            std::cout << std::endl;
        }
    }
};

int main() {
    std::cout << "=== QtLanChat 封装应用 ===" << std::endl;

    // 创建用户
    User user1("张三", 25);
    user1.setPassword("123456");
    user1.setOnline(true);
    user1.printInfo();

    // 使用 getter 获取信息
    std::cout << "\n使用 getter 获取信息：" << std::endl;
    std::cout << "姓名: " << user1.getName() << std::endl;
    std::cout << "年龄: " << user1.getAge() << std::endl;
    std::cout << "在线状态: " << (user1.getIsOnline() ? "在线" : "离线") << std::endl;

    // 使用 setter 修改信息（带验证）
    std::cout << "\n使用 setter 修改信息：" << std::endl;
    user1.setName("李四");
    user1.setAge(30);
    user1.setPassword("123");       // 密码太短，会被拒绝
    user1.setPassword("12345678");  // 密码有效

    // 验证密码
    if (user1.checkPassword("12345678")) {
        std::cout << "密码验证成功" << std::endl;
    }

    // 使用用户管理类
    UserManager manager;
    manager.addUser("王五", 28);
    manager.addUser("赵六", 32);
    manager.printAllUsers();

    return 0;
}
