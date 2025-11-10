#include <iostream>
#include <string>

class User {
private:
    std::string name;
    int age;
    std::string email;
    std::string password;

public:
    User(const std::string& userName, int userAge, const std::string& userEmail) {
        name = userName;
        age = userAge;
        email = userEmail;
        password = "";
    }

    // Getter
    std::string getName() const { return name; }
    int getAge() const { return age; }
    std::string getEmail() const { return email; }

    // Setter（带验证）
    void setName(const std::string& newName) {
        if (newName.length() >= 1 && newName.length() <= 50) {
            name = newName;
        } else {
            std::cout << "姓名长度必须在 1-50 之间" << std::endl;
        }
    }

    void setAge(int newAge) {
        if (newAge > 0 && newAge < 150) {
            age = newAge;
        } else {
            std::cout << "年龄必须在 0-150 之间" << std::endl;
        }
    }

    void setEmail(const std::string& newEmail) {
        if (newEmail.find('@') != std::string::npos) {
            email = newEmail;
        } else {
            std::cout << "邮箱格式无效（必须包含 @）" << std::endl;
        }
    }

    void setPassword(const std::string& pwd) {
        if (pwd.length() >= 6) {
            password = pwd;
            std::cout << "密码设置成功" << std::endl;
        } else {
            std::cout << "密码长度至少 6 位" << std::endl;
        }
    }

    bool changePassword(const std::string& oldPwd, const std::string& newPwd) {
        if (password.empty()) {
            std::cout << "请先设置密码" << std::endl;
            return false;
        }

        if (password != oldPwd) {
            std::cout << "旧密码错误" << std::endl;
            return false;
        }

        if (newPwd.length() >= 6) {
            password = newPwd;
            std::cout << "密码修改成功" << std::endl;
            return true;
        } else {
            std::cout << "新密码长度至少 6 位" << std::endl;
            return false;
        }
    }

    void printInfo() const {
        std::cout << "=== 用户信息 ===" << std::endl;
        std::cout << "姓名: " << name << std::endl;
        std::cout << "年龄: " << age << std::endl;
        std::cout << "邮箱: " << email << std::endl;
        // 不显示密码
    }
};

int main() {
    User user("张三", 25, "zhangsan@example.com");

    // 设置密码
    user.setPassword("123456");

    // 修改信息（带验证）
    user.setName("李四");
    user.setAge(30);
    user.setEmail("lisi@example.com");

    // 修改密码（需要旧密码）
    user.changePassword("123456", "newpass123");
    user.changePassword("wrong", "newpass456");  // 旧密码错误

    // 显示信息（不显示密码）
    user.printInfo();

    return 0;
}
