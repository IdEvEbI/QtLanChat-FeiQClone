# 阶段 1：C++ 基础学习（第 1-5 天）

## 📋 学习目标

通过 5 天的系统性学习，掌握现代 C++ 的核心语法和面向对象编程，为后续 Qt 开发打下坚实基础。

## 🎯 学习成果

- **C++ 语法**：掌握变量、函数、类、继承等核心概念
- **面向对象**：理解封装、继承、多态三大特性
- **综合应用**：设计聊天系统的基础类结构
- **工程实践**：遵循 Google C++ Style 编码规范

## 📅 学习计划

### 第 1-2 天：C++ 语法回顾

#### 第 1 天：基础语法

- **变量与数据类型**
  - 基本类型：`int`, `double`, `char`, `bool`
  - 复合类型：`string`, `vector`, `array`
  - 现代 C++：`auto` 关键字
- **函数**
  - 函数声明与定义
  - 参数传递：值传递、引用传递、指针传递
  - 函数重载
- **控制结构**
  - 条件语句：`if`, `switch`
  - 循环语句：`for`, `while`, `range-based for`

#### 第 2 天：高级语法

- **指针与引用**
  - 指针的基本概念和操作
  - 引用的使用场景
  - 智能指针：`unique_ptr`, `shared_ptr`
- **内存管理**
  - 栈内存 vs 堆内存
  - `new` 和 `delete` 操作
  - RAII 原则
- **异常处理**
  - `try-catch` 机制
  - 异常安全编程

### 第 3-4 天：面向对象编程

#### 第 3 天：类与对象

- **类的定义**
  - 成员变量和成员函数
  - 访问控制：`public`, `private`, `protected`
  - 构造函数和析构函数
- **封装**
  - 数据隐藏
  - 接口设计
  - getter/setter 模式

#### 第 4 天：继承与多态

- **继承**
  - 基类和派生类
  - 继承方式：`public`, `private`, `protected`
  - 虚函数和虚析构函数
- **多态**
  - 动态绑定
  - 纯虚函数和抽象类
  - 接口设计模式

### 第 5 天：综合案例练习

#### 聊天系统基础类设计

设计一个简单的聊天系统，包含以下核心类：

```cpp
// 用户类
class User {
private:
    std::string username;
    std::string ipAddress;
    bool isOnline;

public:
    User(const std::string& name, const std::string& ip);
    virtual ~User() = default;

    // getter/setter
    std::string getUsername() const;
    void setOnline(bool status);
    bool getIsOnline() const;

    // 虚函数，支持多态
    virtual void sendMessage(const std::string& message) = 0;
    virtual void receiveMessage(const std::string& message) = 0;
};

// 消息类
class Message {
private:
    std::string content;
    std::string sender;
    std::chrono::system_clock::time_point timestamp;

public:
    Message(const std::string& msg, const std::string& from);

    std::string getContent() const;
    std::string getSender() const;
    std::string getTimestamp() const;
};

// 聊天室类
class ChatRoom {
private:
    std::string roomName;
    std::vector<std::unique_ptr<User>> users;
    std::vector<Message> messages;

public:
    ChatRoom(const std::string& name);

    void addUser(std::unique_ptr<User> user);
    void removeUser(const std::string& username);
    void broadcastMessage(const Message& message);
    std::vector<Message> getMessages() const;
};
```

## 🛠️ 实践练习

### 练习 1：基础语法练习

```cpp
// 创建一个计算器类
class Calculator {
public:
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);

private:
    double lastResult = 0.0;
};
```

### 练习 2：继承练习

```cpp
// 基类：网络连接
class NetworkConnection {
protected:
    std::string ipAddress;
    int port;

public:
    NetworkConnection(const std::string& ip, int p);
    virtual ~NetworkConnection() = default;

    virtual bool connect() = 0;
    virtual void disconnect() = 0;
    virtual bool sendData(const std::string& data) = 0;
};

// 派生类：TCP 连接
class TcpConnection : public NetworkConnection {
public:
    TcpConnection(const std::string& ip, int p);

    bool connect() override;
    void disconnect() override;
    bool sendData(const std::string& data) override;
};
```

### 练习 3：综合应用

实现一个简单的用户管理系统，包含：

- 用户注册/登录
- 用户信息管理
- 用户状态跟踪

## 📚 学习资源

### 推荐书籍

- 《C++ Primer》- 全面系统的 C++ 教程
- 《Effective C++》- C++ 最佳实践
- 《Modern C++》- 现代 C++ 特性

### 在线资源

- [cppreference.com](https://en.cppreference.com/) - C++ 标准库参考
- [learncpp.com](https://www.learncpp.com/) - 免费 C++ 教程
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/) - C++ 编码规范

## ✅ 验收标准

### 第 1-2 天验收

- [ ] 能够熟练使用基本数据类型和变量
- [ ] 掌握函数的定义、调用和重载
- [ ] 理解指针和引用的区别和使用场景
- [ ] 能够进行基本的内存管理

### 第 3-4 天验收

- [ ] 能够设计和使用类
- [ ] 理解封装的概念和实现
- [ ] 掌握继承和多态的使用
- [ ] 能够设计合理的类层次结构

### 第 5 天验收

- [ ] 完成聊天系统基础类设计
- [ ] 代码符合 Google C++ Style 规范
- [ ] 通过编译和基本测试
- [ ] 能够解释设计思路和实现细节

## 🎯 下一步

完成阶段 1 后，将进入**阶段 2：Qt 环境搭建**，学习：

- Qt 开发环境配置
- CMake 构建系统
- Qt 项目结构
- 开发规范和工具链

---

**预计完成时间**：5 天  
**难度等级**：入门级  
**前置要求**：C 语言基础（可选）
