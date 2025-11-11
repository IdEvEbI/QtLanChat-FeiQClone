// 项目中的实际应用示例
#include <iostream>
#include <string>

// 基类：用户类
class User {
protected:
    std::string name;
    int age;
    bool isOnline;

public:
    User(const std::string& userName, int userAge) {
        name = userName;
        age = userAge;
        isOnline = false;
    }

    std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    bool getIsOnline() const {
        return isOnline;
    }

    void setOnline(bool status) {
        isOnline = status;
    }

    void printInfo() {
        std::cout << "=== 用户信息 ===" << std::endl;
        std::cout << "姓名: " << name << std::endl;
        std::cout << "年龄: " << age << std::endl;
        std::cout << "在线状态: " << (isOnline ? "在线" : "离线") << std::endl;
    }
};

// 派生类：普通用户
class NormalUser : public User {
private:
    int messageCount;

public:
    NormalUser(const std::string& n, int a) : User(n, a), messageCount(0) {}

    void sendMessage() {
        messageCount++;
        std::cout << name << " 发送了一条消息（总计: " << messageCount << " 条）" << std::endl;
    }

    void printUserInfo() {
        printInfo();  // 调用基类的成员函数
        std::cout << "消息数量: " << messageCount << std::endl;
    }
};

// 派生类：管理员用户
class AdminUser : public User {
private:
    int manageCount;

public:
    AdminUser(const std::string& n, int a) : User(n, a), manageCount(0) {}

    void manageUser() {
        manageCount++;
        std::cout << name << " 执行了管理操作（总计: " << manageCount << " 次）" << std::endl;
    }

    void printAdminInfo() {
        printInfo();  // 调用基类的成员函数
        std::cout << "管理操作次数: " << manageCount << std::endl;
    }
};

int main() {
    std::cout << "=== QtLanChat 继承应用 ===" << std::endl;

    // 创建普通用户
    NormalUser user1("张三", 25);
    user1.setOnline(true);
    user1.sendMessage();
    user1.sendMessage();
    user1.printUserInfo();

    std::cout << std::endl;

    // 创建管理员用户
    AdminUser admin1("管理员", 30);
    admin1.setOnline(true);
    admin1.manageUser();
    admin1.printAdminInfo();

    return 0;
}
