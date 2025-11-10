#include <iostream>
#include <string>

class User {
private:
    std::string name;
    int age;
    std::string password;

public:
    // 构造函数
    User(const std::string& userName, int userAge) {
        name = userName;
        age = userAge;
        password = "";
    }

    // Getter：获取姓名
    std::string getName() const {
        return name;
    }

    // Getter：获取年龄
    int getAge() const {
        return age;
    }

    // Setter：设置姓名
    void setName(const std::string& newName) {
        if (!newName.empty()) {
            name = newName;
        }
    }

    // Setter：设置年龄
    void setAge(int newAge) {
        if (newAge > 0 && newAge < 150) {
            age = newAge;
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

    // 验证密码（不直接返回密码）
    bool checkPassword(const std::string& pwd) const {
        return password == pwd;
    }

    // 打印用户信息
    void printInfo() const {
        std::cout << "姓名: " << name << std::endl;
        std::cout << "年龄: " << age << std::endl;
    }
};

int main() {
    User user("张三", 25);

    // 使用 Getter 获取信息
    std::cout << "姓名: " << user.getName() << std::endl;
    std::cout << "年龄: " << user.getAge() << std::endl;

    // 使用 Setter 修改信息
    user.setName("李四");
    user.setAge(30);
    user.setPassword("123456");

    // 验证密码
    if (user.checkPassword("123456")) {
        std::cout << "密码正确" << std::endl;
    }

    user.printInfo();

    return 0;
}
