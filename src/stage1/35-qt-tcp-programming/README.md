# Qt TCP 编程示例代码

本目录包含 `35-qt-tcp-programming.md` 文档的所有配套代码示例。

## 示例列表

| 示例程序                  | 说明                           |
| ------------------------- | ------------------------------ |
| **01-basic-tcp-client**   | TCP 客户端基础示例             |
| **02-basic-tcp-server**   | TCP 服务器基础示例              |
| **03-chat-server**        | TCP 聊天服务器示例（多客户端） |
| **04-chat-client**        | TCP 聊天客户端示例             |
| **05-file-transfer-client** | TCP 文件传输客户端示例       |
| **06-file-transfer-server** | TCP 文件传输服务器示例       |

## 编译和运行

每个示例程序都包含完整的 CMakeLists.txt 配置，可以独立编译运行：

```bash
# 进入示例目录
cd src/stage1/35-qt-tcp-programming/01-basic-tcp-client

# 创建构建目录
mkdir build && cd build

# 配置和编译
cmake ..
cmake --build .

# 运行
./BasicTcpClient
```

## 依赖要求

- CMake 3.20 或更高版本
- Qt 6.x（Core、Network 模块）
- C++17 或更高版本的编译器

## 注意事项

1. **端口占用**：如果端口被占用，程序可能无法启动。可以修改代码中的端口号（默认 12345、12346、12347）。
2. **防火墙**：某些系统可能需要配置防火墙以允许 TCP 通信。
3. **运行顺序**：
   - **基础示例**：先运行 `02-basic-tcp-server`，再运行 `01-basic-tcp-client`
   - **聊天示例**：先运行 `03-chat-server`，再运行 `04-chat-client`（可以运行多个客户端）
   - **文件传输**：先运行 `06-file-transfer-server`，再运行 `05-file-transfer-client <文件路径>`

## 示例说明

### 01-basic-tcp-client

演示 TCP 客户端的基本使用方法，包括：
- 连接到服务器
- 发送数据
- 接收服务器响应
- 处理连接错误

**运行方式**：
1. 先启动 `02-basic-tcp-server`
2. 再运行 `./BasicTcpClient`

### 02-basic-tcp-server

演示 TCP 服务器的基本使用方法，包括：
- 监听端口
- 接受客户端连接
- 接收客户端数据
- 向客户端发送响应
- 处理客户端断开连接

**运行方式**：
```bash
./BasicTcpServer
```

### 03-chat-server

演示 TCP 聊天服务器，支持多个客户端同时连接：
- 监听端口，等待客户端连接
- 接收客户端消息
- 将消息广播给所有连接的客户端
- 处理客户端连接和断开

**运行方式**：
```bash
./ChatServer
```

### 04-chat-client

演示 TCP 聊天客户端：
- 连接到聊天服务器
- 发送消息到服务器
- 接收服务器广播的消息
- 自动发送演示消息（每3秒一条）

**运行方式**：
1. 先启动 `03-chat-server`
2. 再运行 `./ChatClient`（可以运行多个客户端）

### 05-file-transfer-client

演示 TCP 文件传输客户端：
- 连接到文件传输服务器
- 发送文件信息（文件名、大小）
- 分块发送文件数据（每次 4KB）
- 显示传输进度
- 处理传输完成

**运行方式**：
1. 先启动 `06-file-transfer-server`
2. 再运行 `./FileTransferClient <文件路径>`
   ```bash
   ./FileTransferClient /path/to/file.txt
   ```

### 06-file-transfer-server

演示 TCP 文件传输服务器：
- 监听端口，等待客户端连接
- 接收文件信息
- 接收文件数据（分块接收）
- 保存文件到本地（文件名前缀：`received_`）
- 支持多个客户端同时传输文件

**运行方式**：
```bash
./FileTransferServer
```

## 代码说明

### 关键知识点

1. **QTcpSocket**：Qt 的 TCP 客户端类，用于与服务器建立连接并进行数据传输
2. **QTcpServer**：Qt 的 TCP 服务器类，用于创建 TCP 服务器，监听客户端连接
3. **TCP 连接流程**：三次握手建立连接，四次挥手断开连接
4. **信号槽机制**：网络事件通过信号槽通知（connected、disconnected、readyRead、errorOccurred）
5. **文件传输协议**：FILE_INFO（文件信息）、FILE_DATA（文件数据）、FILE_END（传输完成）
6. **分块传输**：大文件分块发送，避免内存问题

### 注意事项

- 所有示例都使用 `QCoreApplication`（控制台应用），不需要 GUI
- 使用 `this` 指针作为父对象，实现自动内存管理
- 网络操作可能失败，实际应用中需要错误处理
- 文件传输使用分块传输，每次发送 4KB
- 服务器支持多个客户端同时连接

## 相关文档

- [35-qt-tcp-programming.md](../../../docs/stage1/35-qt-tcp-programming.md)：完整文档
- [34-qt-udp-programming.md](../34-qt-udp-programming/README.md)：Qt UDP 编程
- [33-qt-network-basics.md](../33-qt-network-basics/README.md)：Qt 网络基础

## 常见问题

### 问题 1：找不到 Qt6

**解决方案**：
- 确保已安装 Qt 6.9+（推荐 6.12+）
- 设置 `Qt6_DIR` 环境变量（可选，CMake 会自动查找）
- 参考 [30-qt-environment-setup.md](../../../docs/stage1/30-qt-environment-setup.md)

### 问题 2：端口绑定失败

**解决方案**：
- 检查端口是否被占用：`lsof -i :12345`（macOS/Linux）
- 使用其他端口（建议使用 1024-65535 范围）
- 检查是否有权限绑定系统端口（0-1023）

### 问题 3：连接失败

**解决方案**：
- 确保服务器已启动
- 检查服务器和客户端使用的端口是否一致
- 检查防火墙设置
- 检查网络连接

### 问题 4：文件传输失败

**解决方案**：
- 确保文件路径正确
- 确保有读取文件的权限
- 确保服务器有写入文件的权限
- 检查磁盘空间是否充足

