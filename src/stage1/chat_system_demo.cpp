#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <chrono>
#include <ctime>

/**
 * @brief 用户基类
 * 
 * 定义用户的基本属性和行为接口
 */
class User {
private:
    std::string username;
    std::string ipAddress;
    bool isOnline;

public:
    /**
     * @brief 构造函数
     * @param name 用户名
     * @param ip IP 地址
     */
    User(const std::string& name, const std::string& ip) 
        : username(name), ipAddress(ip), isOnline(false) {
        std::cout << "用户 " << username << " 创建成功" << std::endl;
    }

    /**
     * @brief 虚析构函数，支持多态
     */
    virtual ~User() = default;

    // Getter 方法
    std::string getUsername() const { return username; }
    std::string getIpAddress() const { return ipAddress; }
    bool getIsOnline() const { return isOnline; }

    // Setter 方法
    void setOnline(bool status) { 
        isOnline = status;
        std::cout << "用户 " << username << " " << (isOnline ? "上线" : "下线") << std::endl;
    }

    /**
     * @brief 发送消息（纯虚函数）
     * @param message 消息内容
     */
    virtual void sendMessage(const std::string& message) = 0;

    /**
     * @brief 接收消息（纯虚函数）
     * @param message 消息内容
     */
    virtual void receiveMessage(const std::string& message) = 0;
};

/**
 * @brief 消息类
 * 
 * 封装消息的基本信息
 */
class Message {
private:
    std::string content;
    std::string sender;
    std::chrono::system_clock::time_point timestamp;

public:
    /**
     * @brief 构造函数
     * @param msg 消息内容
     * @param from 发送者
     */
    Message(const std::string& msg, const std::string& from) 
        : content(msg), sender(from), timestamp(std::chrono::system_clock::now()) {}

    // Getter 方法
    std::string getContent() const { return content; }
    std::string getSender() const { return sender; }
    
    /**
     * @brief 获取格式化的时间戳
     * @return 格式化的时间字符串
     */
    std::string getTimestamp() const {
        auto time_t = std::chrono::system_clock::to_time_t(timestamp);
        char buffer[100];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&time_t));
        return std::string(buffer);
    }
};

/**
 * @brief 聊天室类
 * 
 * 管理用户和消息的容器
 */
class ChatRoom {
private:
    std::string roomName;
    std::vector<std::unique_ptr<User>> users;
    std::vector<Message> messages;

public:
    /**
     * @brief 构造函数
     * @param name 聊天室名称
     */
    ChatRoom(const std::string& name) : roomName(name) {
        std::cout << "聊天室 " << roomName << " 创建成功" << std::endl;
    }

    /**
     * @brief 添加用户
     * @param user 用户指针
     */
    void addUser(std::unique_ptr<User> user) {
        users.push_back(std::move(user));
        std::cout << "用户已加入聊天室 " << roomName << std::endl;
    }

    /**
     * @brief 移除用户
     * @param username 用户名
     */
    void removeUser(const std::string& username) {
        auto it = std::find_if(users.begin(), users.end(),
            [&username](const std::unique_ptr<User>& user) {
                return user->getUsername() == username;
            });
        
        if (it != users.end()) {
            users.erase(it);
            std::cout << "用户 " << username << " 已离开聊天室" << std::endl;
        }
    }

    /**
     * @brief 广播消息
     * @param message 消息对象
     */
    void broadcastMessage(const Message& message) {
        messages.push_back(message);
        
        // 向所有在线用户发送消息
        for (const auto& user : users) {
            if (user->getIsOnline()) {
                user->receiveMessage(message.getContent());
            }
        }
        
        std::cout << "[" << message.getTimestamp() << "] " 
                  << message.getSender() << ": " << message.getContent() << std::endl;
    }

    /**
     * @brief 获取所有消息
     * @return 消息列表
     */
    std::vector<Message> getMessages() const {
        return messages;
    }

    /**
     * @brief 获取聊天室名称
     * @return 聊天室名称
     */
    std::string getRoomName() const {
        return roomName;
    }

    /**
     * @brief 获取在线用户数量
     * @return 在线用户数
     */
    int getOnlineUserCount() const {
        int count = 0;
        for (const auto& user : users) {
            if (user->getIsOnline()) {
                count++;
            }
        }
        return count;
    }
};

/**
 * @brief 本地用户类
 * 
 * 继承自 User，实现本地用户的具体行为
 */
class LocalUser : public User {
public:
    LocalUser(const std::string& name, const std::string& ip) 
        : User(name, ip) {}

    void sendMessage(const std::string& message) override {
        std::cout << "本地用户 " << getUsername() << " 发送消息: " << message << std::endl;
    }

    void receiveMessage(const std::string& message) override {
        std::cout << "本地用户 " << getUsername() << " 收到消息: " << message << std::endl;
    }
};

/**
 * @brief 远程用户类
 * 
 * 继承自 User，实现远程用户的具体行为
 */
class RemoteUser : public User {
public:
    RemoteUser(const std::string& name, const std::string& ip) 
        : User(name, ip) {}

    void sendMessage(const std::string& message) override {
        std::cout << "远程用户 " << getUsername() << " (" << getIpAddress() 
                  << ") 发送消息: " << message << std::endl;
    }

    void receiveMessage(const std::string& message) override {
        std::cout << "远程用户 " << getUsername() << " (" << getIpAddress() 
                  << ") 收到消息: " << message << std::endl;
    }
};

/**
 * @brief 主函数 - 演示聊天系统的基本功能
 */
int main() {
    std::cout << "=== C++ 聊天系统基础类设计演示 ===" << std::endl;
    
    // 创建聊天室
    ChatRoom chatRoom("QtLanChat 开发群");
    
    // 创建用户
    auto user1 = std::make_unique<LocalUser>("开发者A", "192.168.1.100");
    auto user2 = std::make_unique<RemoteUser>("开发者B", "192.168.1.101");
    auto user3 = std::make_unique<LocalUser>("开发者C", "192.168.1.102");
    
    // 添加用户到聊天室
    chatRoom.addUser(std::move(user1));
    chatRoom.addUser(std::move(user2));
    chatRoom.addUser(std::move(user3));
    
    // 用户上线
    // 注意：这里需要重新获取用户引用，实际项目中会有更好的设计
    std::cout << "\n--- 用户上线 ---" << std::endl;
    
    // 发送消息
    std::cout << "\n--- 发送消息 ---" << std::endl;
    Message msg1("大家好，我是开发者A！", "开发者A");
    chatRoom.broadcastMessage(msg1);
    
    Message msg2("欢迎加入 QtLanChat 项目！", "开发者B");
    chatRoom.broadcastMessage(msg2);
    
    Message msg3("让我们开始 C++ 学习之旅吧！", "开发者C");
    chatRoom.broadcastMessage(msg3);
    
    // 显示聊天室信息
    std::cout << "\n--- 聊天室信息 ---" << std::endl;
    std::cout << "聊天室名称: " << chatRoom.getRoomName() << std::endl;
    std::cout << "消息总数: " << chatRoom.getMessages().size() << std::endl;
    
    std::cout << "\n=== 演示完成 ===" << std::endl;
    
    return 0;
}