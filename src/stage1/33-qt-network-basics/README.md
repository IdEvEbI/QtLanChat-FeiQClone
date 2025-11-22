# Qt 网络编程基础 - 配套代码

本目录包含 `33-qt-network-basics.md` 文档的配套代码示例。

## 📁 代码结构

```
33-qt-network-basics/
├── 01-qhostaddress-demo/      # QHostAddress 基础使用示例
│   ├── CMakeLists.txt
│   └── main.cpp
├── 02-network-info/            # 获取本机网络信息示例
│   ├── CMakeLists.txt
│   ├── NetworkInfo.h
│   ├── NetworkInfo.cpp
│   └── main.cpp
├── 03-network-validator/       # IP 地址和端口验证示例
│   ├── CMakeLists.txt
│   ├── NetworkValidator.h
│   ├── NetworkValidator.cpp
│   └── main.cpp
├── 04-get-local-ip/            # 获取本机 IP 地址实用函数示例
│   ├── CMakeLists.txt
│   ├── NetworkUtils.h
│   ├── NetworkUtils.cpp
│   └── main.cpp
└── README.md
```

## 🚀 编译和运行

### 前置要求

- Qt 6.9+（推荐 6.12+）
- CMake 3.20+
- C++17 编译器

### 编译步骤

1. **进入示例目录**：

   ```bash
   cd src/stage1/33-qt-network-basics/01-qhostaddress-demo
   ```

2. **创建构建目录**：

   ```bash
   mkdir build && cd build
   ```

3. **配置 CMake**：

   ```bash
   cmake ..
   ```

4. **编译**：

   ```bash
   cmake --build .
   ```

5. **运行**：

   ```bash
   ./QHostAddressDemo
   ```

### 使用 Cursor 调试

1. 在 Cursor 中打开项目根目录
2. 按 `Cmd+Shift+B` 执行 `build-smart` 任务（自动检测并构建）
3. 按 `F5` 启动调试

## 📝 示例说明

### 01-qhostaddress-demo

演示 `QHostAddress` 类的基本使用：

- 创建 IP 地址对象
- 使用常量（LocalHost、Broadcast、AnyIPv4）
- 判断地址类型（loopback、multicast）
- 验证地址有效性

**运行结果示例**：

```
=== QHostAddress Demo ===

1. Basic IP Address Operations:
   addr1: "192.168.1.100"
   addr2 (LocalHost): "127.0.0.1"
   addr3 (Broadcast): "255.255.255.255"

2. Address Type Checking:
   addr1 is null: false
   addr1 is loopback: false
   addr1 is multicast: false
   ...
```

### 02-network-info

演示如何获取本机的网络接口信息：

- 获取所有网络接口
- 显示接口名称、硬件地址、IP 地址、子网掩码、广播地址
- 过滤非活动接口

**运行结果示例**：

```
=== Network Interfaces ===

Interface: en0
  Hardware Address: 00:11:22:33:44:55
  Is Loopback: false
  Is Up: true
  IPv4 Address: 192.168.1.100
  Netmask: 255.255.255.0
  Broadcast: 192.168.1.255
```

### 03-network-validator

演示如何验证 IP 地址和端口号：

- 验证 IPv4 地址的有效性
- 判断地址类型（loopback、multicast、broadcast）
- 验证端口号范围

**运行结果示例**：

```
=== IP Address Validation ===
192.168.1.100 is valid: true
Is loopback: false
Is multicast: false

224.0.0.1 is multicast: true
Broadcast address: "255.255.255.255"

=== Port Validation ===
Port 80 (HTTP): 80
Port 443 (HTTPS): 443
Port 12345 (Custom): 12345
Port 80 requires administrator privileges
Port 12345 is in user range (1024-65535)
```

### 04-get-local-ip

提供获取本机 IP 地址的实用函数：

- `getLocalIpAddress()`：获取第一个 IPv4 地址（非回环）
- `getAllLocalIpAddresses()`：获取所有 IPv4 地址

**运行结果示例**：

```
=== Get Local IP Address ===
Local IP Address: 192.168.1.100

All IPv4 Addresses:
  - 192.168.1.100
  - 10.0.0.5
```

## 🔍 代码说明

### 关键知识点

1. **QHostAddress**：Qt 的 IP 地址类，用于表示和操作 IP 地址
2. **QNetworkInterface**：Qt 的网络接口类，用于获取网络接口信息
3. **QNetworkAddressEntry**：网络地址条目，包含 IP 地址、子网掩码、广播地址
4. **端口绑定**：服务器程序需要绑定端口才能接收连接
5. **端口复用**：多播场景下需要端口复用

### 注意事项

- 所有示例都使用 `QCoreApplication`（控制台应用），不需要 GUI
- 使用 `this` 指针作为父对象，实现自动内存管理
- 网络操作可能失败，实际应用中需要错误处理
- 端口绑定需要检查返回值，处理绑定失败的情况

## 📚 相关文档

- [33-qt-network-basics.md](../../../docs/stage1/33-qt-network-basics.md)：完整文档
- [31-qt-signals-slots.md](../31-qt-signals-slots/README.md)：Qt 信号槽机制
- [32-network-programming-concepts.md](../../../docs/stage1/32-network-programming-concepts.md)：网络编程概念

## 🐛 常见问题

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

### 问题 3：获取不到 IP 地址

**解决方案**：

- 确保网络接口已启用（`IsUp` 标志）
- 检查是否有活动的网络连接
- 跳过回环接口（`IsLoopBack`）
