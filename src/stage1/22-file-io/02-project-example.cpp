// 项目中的实际应用示例
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct User {
    std::string name;
    int age;
    bool isOnline;
};

struct Message {
    std::string sender;
    std::string content;
    std::string timestamp;
};

// 用户数据管理类
class UserManager {
private:
    std::vector<User> users;
    const std::string filename = "users.txt";

public:
    // 从文件加载用户数据
    void loadUsers() {
        std::ifstream file(filename);
        if (file.is_open()) {
            users.clear();
            std::string name;
            int age;
            bool isOnline;

            while (file >> name >> age >> isOnline) {
                users.push_back({name, age, isOnline});
            }

            file.close();
            std::cout << "加载了 " << users.size() << " 个用户" << std::endl;
        } else {
            std::cout << "用户文件不存在，将创建新文件" << std::endl;
        }
    }

    // 保存用户数据到文件
    void saveUsers() {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& user : users) {
                file << user.name << " " << user.age << " "
                     << (user.isOnline ? 1 : 0) << std::endl;
            }
            file.close();
            std::cout << "用户数据已保存" << std::endl;
        } else {
            std::cout << "无法保存用户数据" << std::endl;
        }
    }

    // 添加用户
    void addUser(const std::string& name, int age) {
        users.push_back({name, age, false});
        std::cout << "添加用户: " << name << std::endl;
    }

    // 设置用户在线状态
    void setUserOnline(const std::string& name, bool isOnline) {
        for (auto& user : users) {
            if (user.name == name) {
                user.isOnline = isOnline;
                break;
            }
        }
    }

    // 打印用户列表
    void printUsers() {
        std::cout << "\n=== 用户列表 ===" << std::endl;
        for (size_t i = 0; i < users.size(); i++) {
            std::cout << (i + 1) << ". " << users[i].name
                      << ", 年龄: " << users[i].age
                      << ", 状态: " << (users[i].isOnline ? "在线" : "离线")
                      << std::endl;
        }
    }
};

// 消息记录管理类
class MessageLogger {
private:
    const std::string logFile = "messages.log";

public:
    // 记录消息到日志文件（追加模式）
    void logMessage(const std::string& sender, const std::string& content) {
        std::ofstream file(logFile, std::ios::app);
        if (file.is_open()) {
            file << "[" << sender << "] " << content << std::endl;
            file.close();
        }
    }

    // 读取所有消息记录
    void readAllMessages() {
        std::ifstream file(logFile);
        if (file.is_open()) {
            std::cout << "\n=== 消息记录 ===" << std::endl;
            std::string line;
            while (std::getline(file, line)) {
                std::cout << line << std::endl;
            }
            file.close();
        } else {
            std::cout << "没有消息记录" << std::endl;
        }
    }
};

int main() {
    std::cout << "=== QtLanChat 文件 I/O 应用 ===" << std::endl;

    // 用户管理
    UserManager userManager;

    // 加载用户数据
    std::cout << "\n=== 加载用户数据 ===" << std::endl;
    userManager.loadUsers();
    userManager.printUsers();

    // 添加新用户
    std::cout << "\n=== 添加新用户 ===" << std::endl;
    userManager.addUser("张三", 25);
    userManager.addUser("李四", 30);
    userManager.setUserOnline("张三", true);
    userManager.printUsers();

    // 保存用户数据
    std::cout << "\n=== 保存用户数据 ===" << std::endl;
    userManager.saveUsers();

    // 消息记录
    MessageLogger logger;

    std::cout << "\n=== 记录消息 ===" << std::endl;
    logger.logMessage("张三", "你好，大家好！");
    logger.logMessage("李四", "很高兴认识大家");
    logger.logMessage("张三", "今天天气不错");

    // 读取消息记录
    logger.readAllMessages();

    return 0;
}
