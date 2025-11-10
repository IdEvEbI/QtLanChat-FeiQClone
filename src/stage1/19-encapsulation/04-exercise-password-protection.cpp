#include <iostream>
#include <string>

class Account {
private:
    std::string username;
    std::string password;

public:
    Account(const std::string& user, const std::string& pwd) {
        username = user;
        password = pwd;
    }

    std::string getUsername() const {
        return username;
    }

    void setPassword(const std::string& pwd) {
        if (pwd.length() >= 6) {
            password = pwd;
            std::cout << "密码设置成功" << std::endl;
        } else {
            std::cout << "密码长度至少 6 位" << std::endl;
        }
    }

    bool checkPassword(const std::string& pwd) const {
        return password == pwd;
    }
};

int main() {
    Account account("张三", "123456");

    // 可以获取用户名
    std::cout << "用户名: " << account.getUsername() << std::endl;

    // 可以设置密码（带验证）
    account.setPassword("123");  // 会被拒绝
    account.setPassword("12345678");  // 成功

    // 可以验证密码，但不能直接获取
    if (account.checkPassword("12345678")) {
        std::cout << "密码正确" << std::endl;
    }

    return 0;
}
