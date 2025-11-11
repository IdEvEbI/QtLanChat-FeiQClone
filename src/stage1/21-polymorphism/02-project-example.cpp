// 项目中的实际应用示例
#include <iostream>
#include <string>

// 基类：用户类（抽象类）
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

    virtual ~User() {  // 虚析构函数
        std::cout << name << " 被销毁" << std::endl;
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

    // 虚函数：打印用户信息
    virtual void printInfo() {
        std::cout << "=== 用户信息 ===" << std::endl;
        std::cout << "姓名: " << name << std::endl;
        std::cout << "年龄: " << age << std::endl;
        std::cout << "在线状态: " << (isOnline ? "在线" : "离线") << std::endl;
    }

    // 纯虚函数：发送消息（不同用户类型有不同的实现）
    virtual void sendMessage(const std::string& message) = 0;
};

// 派生类：普通用户
class NormalUser : public User {
private:
    int messageCount;

public:
    NormalUser(const std::string& n, int a) : User(n, a), messageCount(0) {}

    void printInfo() override {  // 重写虚函数
        std::cout << "=== 普通用户信息 ===" << std::endl;
        std::cout << "姓名: " << name << std::endl;
        std::cout << "年龄: " << age << std::endl;
        std::cout << "在线状态: " << (isOnline ? "在线" : "离线") << std::endl;
        std::cout << "消息数量: " << messageCount << std::endl;
    }

    void sendMessage(const std::string& message) override {  // 实现纯虚函数
        messageCount++;
        std::cout << "[" << name << "] 发送消息: " << message << std::endl;
        std::cout << "（总计发送 " << messageCount << " 条消息）" << std::endl;
    }
};

// 派生类：管理员用户
class AdminUser : public User {
private:
    int manageCount;

public:
    AdminUser(const std::string& n, int a) : User(n, a), manageCount(0) {}

    void printInfo() override {  // 重写虚函数
        std::cout << "=== 管理员信息 ===" << std::endl;
        std::cout << "姓名: " << name << std::endl;
        std::cout << "年龄: " << age << std::endl;
        std::cout << "在线状态: " << (isOnline ? "在线" : "离线") << std::endl;
        std::cout << "管理操作次数: " << manageCount << std::endl;
    }

    void sendMessage(const std::string& message) override {  // 实现纯虚函数
        std::cout << "[管理员 " << name << "] 发送系统消息: " << message << std::endl;
    }

    void manageUser() {
        manageCount++;
        std::cout << name << " 执行了管理操作（总计: " << manageCount << " 次）" << std::endl;
    }
};

// 使用多态的函数
void processUser(User* user) {
    user->printInfo();              // 多态：根据实际类型调用相应的函数
    user->sendMessage("你好！");     // 多态：根据实际类型调用相应的函数
    std::cout << std::endl;
}

int main() {
    std::cout << "=== QtLanChat 多态应用 ===" << std::endl;

    // 创建派生类对象
    NormalUser user1("张三", 25);
    AdminUser admin1("管理员", 30);

    user1.setOnline(true);
    admin1.setOnline(true);

    // 使用基类指针调用函数（多态）
    User* userPtr1 = &user1;
    User* userPtr2 = &admin1;

    processUser(userPtr1);  // 调用 NormalUser 的函数
    processUser(userPtr2);  // 调用 AdminUser 的函数

    return 0;
}
