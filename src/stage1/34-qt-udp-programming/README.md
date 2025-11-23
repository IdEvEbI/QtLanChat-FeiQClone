# Qt UDP 编程示例代码

本目录包含 `34-qt-udp-programming.md` 文档的所有配套代码示例。

## 示例列表

| 示例程序              | 说明                    |
| --------------------- | ----------------------- |
| **01-basic-udp**      | QUdpSocket 基础使用示例 |
| **02-unicast-demo**   | UDP 单播通信示例        |
| **03-broadcast-demo** | UDP 广播通信示例        |
| **04-multicast-demo** | UDP 多播通信示例        |
| **05-chat-demo**      | 完整的 UDP 聊天程序示例 |
| **06-ack-demo**       | UDP ACK 确认机制示例    |

## 编译和运行

每个示例程序都包含完整的 CMakeLists.txt 配置，可以独立编译运行：

```bash
# 进入示例目录
cd src/stage1/34-qt-udp-programming/01-basic-udp

# 创建构建目录
mkdir build && cd build

# 配置和编译
cmake ..
cmake --build .

# 运行
./BasicUdpDemo
```

## 依赖要求

- CMake 3.20 或更高版本
- Qt 6.x（Core、Network 模块）
- C++17 或更高版本的编译器

## 注意事项

1. **端口占用**：如果端口被占用，程序可能无法启动。可以修改代码中的端口号（默认 12345）。
2. **多播地址**：多播示例使用 `224.0.0.1` 作为多播地址，确保网络支持多播。
3. **防火墙**：某些系统可能需要配置防火墙以允许 UDP 通信。
4. **本地测试**：单播示例使用 `127.0.0.1` 进行本地测试，广播和多播需要局域网环境。

## 示例说明

### 01-basic-udp
演示 QUdpSocket 的基本使用方法，包括发送和接收 UDP 数据包。

### 02-unicast-demo
演示 UDP 单播通信，实现一对一的消息传输。

### 03-broadcast-demo
演示 UDP 广播通信，向局域网内所有设备发送消息。

### 04-multicast-demo
演示 UDP 多播通信，向加入多播组的设备发送消息。

### 05-chat-demo
完整的 UDP 聊天程序示例，支持单播、广播和多播三种通信方式。

### 06-ack-demo
演示 UDP 应用层确认机制（ACK），实现可靠的消息传输。

