# Qt 网络编程示例代码

本目录包含 Qt 网络编程的示例代码，对应 `docs/stage1/33-qt-network-programming.md` 文档。

## 目录结构

- `01-udp-basic/` - UDP 基础通信示例（UdpSender/UdpReceiver）
- `02-udp-broadcast/` - UDP 广播示例
- `03-udp-multicast/` - UDP 多播示例
- `04-tcp-client-server/` - TCP 客户端/服务器示例
- `05-udp-chat/` - UDP 聊天程序示例
- `06-tcp-file-transfer/` - TCP 文件传输示例

## 编译和运行

### 01-udp-basic

```bash
cd 01-udp-basic
mkdir build && cd build
cmake ..
cmake --build .
./UdpDemo
```

### 02-udp-broadcast

```bash
cd 02-udp-broadcast
mkdir build && cd build
cmake ..
cmake --build .
./BroadcastDemo
```

### 03-udp-multicast

```bash
cd 03-udp-multicast
mkdir build && cd build
cmake ..
cmake --build .
./MulticastDemo
```

### 04-tcp-client-server

```bash
cd 04-tcp-client-server
mkdir build && cd build
cmake ..
cmake --build .
# 先运行服务器
./TcpServerDemo
# 再运行客户端（另一个终端）
./TcpClientDemo
```

### 05-udp-chat

```bash
cd 05-udp-chat
mkdir build && cd build
cmake ..
cmake --build .
./UdpChat
```

### 06-tcp-file-transfer

```bash
cd 06-tcp-file-transfer
mkdir build && cd build
cmake ..
cmake --build .
# 先运行接收者
./FileReceiverDemo
# 再运行发送者（另一个终端）
./FileSenderDemo
```

## 注意事项

1. **端口占用**：如果端口被占用，请修改代码中的端口号
2. **防火墙**：某些系统可能需要允许程序通过防火墙
3. **网络权限**：macOS 可能需要授予网络权限
4. **多终端测试**：TCP 示例需要两个终端分别运行客户端和服务器

## 学习建议

1. **按顺序学习**：从基础示例开始，逐步学习更复杂的示例
2. **理解信号槽**：注意网络事件如何通过信号槽机制处理
3. **对比 UDP/TCP**：理解两种协议的区别和适用场景
4. **实践修改**：尝试修改代码，如改变端口、添加功能等

