# Qt 信号槽机制示例代码

本目录包含 Qt 信号槽机制的示例代码，对应 `docs/stage1/32-qt-signals-slots.md` 文档。

## 目录结构

- `01-quick-start/` - 快速体验示例（Counter 类）
- `02-message-demo/` - 消息通知系统示例（MessageSender/MessageReceiver）
- `03-timer-demo/` - 定时器示例（Timer 类）
- `04-temperature-demo/` - 温度监控系统示例（TemperatureSensor/TemperatureDisplay）

## 编译和运行

### 01-quick-start

```bash
cd 01-quick-start
mkdir build && cd build
cmake ..
cmake --build .
./SignalSlotDemo
```

### 02-message-demo

```bash
cd 02-message-demo
mkdir build && cd build
cmake ..
cmake --build .
./MessageDemo
```

### 03-timer-demo

```bash
cd 03-timer-demo
mkdir build && cd build
cmake ..
cmake --build .
./TimerDemo
```

### 04-temperature-demo

```bash
cd 04-temperature-demo
mkdir build && cd build
cmake ..
cmake --build .
./TemperatureDemo
```

## 前置要求

- Qt 6.9+（推荐 6.12+）
- CMake 3.20+
- C++17 编译器

## 学习目标

通过这些示例，你将学习到：

1. 如何声明信号和槽
2. 如何使用 `QObject::connect()` 连接信号和槽
3. 如何理解 Qt 对象模型（QObject、Q_OBJECT 宏、MOC）
4. 如何使用信号槽实现对象间通信

## 参考文档

详细说明请参考：[32-qt-signals-slots.md](../../docs/stage1/32-qt-signals-slots.md)

