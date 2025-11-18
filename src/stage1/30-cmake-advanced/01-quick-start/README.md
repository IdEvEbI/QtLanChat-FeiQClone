# CMake 进阶 - 快速体验项目

本目录包含 `docs/stage1/30-cmake-advanced.md` 文档的快速体验示例代码。

## 项目说明

这是一个简单的 Qt6 控制台应用程序，演示如何使用 CMake 链接外部库（Qt6）并配置 Qt 项目。

**学习目标**：

- 理解 `find_package` 如何自动查找外部库
- 理解 `target_link_libraries` 如何链接 Qt6 模块
- 理解 CMake 如何自动处理 Qt 的特殊文件（AUTOMOC）
- 体验跨平台构建（一套配置，多平台使用）

## 文件结构

```ini
01-quick-start/
├── CMakeLists.txt          # CMake 配置文件
├── src/
│   └── main.cpp            # Qt6 控制台程序
└── README.md               # 本文件
```

## 如何构建和运行

### 方法 1：使用命令行（传统方式）

**步骤 1：创建构建目录**

```bash
cd src/stage1/30-cmake-advanced/01-quick-start
mkdir build
cd build
```

**步骤 2：配置项目**

```bash
cmake ..
```

CMake 会自动查找 Qt6 库。如果找不到 Qt6，请参考文档中的解决方法。

**步骤 3：编译项目**

```bash
cmake --build .
```

**步骤 4：运行程序**

```bash
# macOS/Linux
./MyQtApp

# Windows
.\MyQtApp.exe
```

**预期输出**：

```
Hello from Qt6!
Qt Version: 6.x.x
```

### 方法 2：使用 Cursor/VSCode（推荐）

**前提条件**：

- 已配置项目根目录的 `.vscode/tasks.json` 和 `.vscode/launch.json`
- 已创建 `.vscode/build-smart.sh` 脚本

**步骤 1：打开项目**

在 Cursor 中打开 `src/main.cpp` 文件。

**步骤 2：构建项目**

按 `Cmd+Shift+B`（macOS）或 `Ctrl+Shift+B`（Windows/Linux），会自动：
- 检测到 CMakeLists.txt
- 配置 CMake 项目
- 编译项目
- 创建符号链接 `cmake-app`

**步骤 3：调试项目**

按 `F5` 启动调试，会自动：
- 运行 `build-smart` 任务（自动构建）
- 启动调试器
- 程序在断点处停止（如果设置了断点）

**步骤 4：设置断点**

在代码行号左侧点击，出现红色圆点表示断点已设置。

**调试控制**：

- `F5`：继续执行
- `F10`：单步跳过
- `F11`：单步进入
- `Shift+F11`：单步跳出

## 项目配置说明

### CMakeLists.txt 关键配置

1. **`find_package(Qt6 REQUIRED COMPONENTS Core Network)`**
   - 自动查找 Qt6 库
   - 需要 Core 和 Network 模块
   - `REQUIRED` 表示如果找不到库会报错

2. **`CMAKE_AUTOMOC ON`**
   - 自动处理 Qt 的 MOC（Meta-Object Compiler）工具
   - 用于处理信号槽、属性等 Qt 特性

3. **`CMAKE_EXPORT_COMPILE_COMMANDS ON`**
   - 生成 `compile_commands.json` 文件
   - 用于 IntelliSense/clangd 代码补全和错误检查

4. **`target_link_libraries(... Qt6::Core Qt6::Network)`**
   - 链接 Qt6::Core 和 Qt6::Network 模块
   - 使用现代 CMake 语法（自动处理路径）

### main.cpp 说明

这是一个最简单的 Qt6 控制台程序：
- 使用 `QCoreApplication`（不需要 GUI）
- 使用 `qDebug()` 输出信息
- 显示 Qt 版本信息

## 常见问题

### Q1：找不到 Qt6 怎么办？

**错误信息**：

```text
CMake Error at CMakeLists.txt:16 (find_package):
  Could not find a package configuration file provided by "Qt6"
```

**解决方法**：

1. 检查 Qt6 是否已安装
2. 设置 `Qt6_DIR` 环境变量指向 Qt6 的 CMake 配置文件路径
3. 或通过命令行参数指定：`cmake -DQt6_DIR=/path/to/Qt6/lib/cmake/Qt6 ..`

Qt6 的安装将在后续文档（31-qt-environment-setup.md）中学习。

### Q2：为什么使用 `Qt6::Core` 而不是 `Qt6Core`？

`Qt6::Core` 是现代 CMake（3.0+）的推荐语法，是 CMake 目标（target），自动处理：
- 头文件路径
- 库文件路径
- 编译选项
- 跨平台支持

`Qt6Core` 是传统方式，需要手动处理路径。

### Q3：CMAKE_AUTOMOC 是什么？

`CMAKE_AUTOMOC` 自动处理 Qt 的 MOC（Meta-Object Compiler）工具，用于：
- 信号槽机制
- 属性系统
- 反射功能

启用后，CMake 会自动处理 Qt 的特殊文件，不需要手动调用工具。

## 学习建议

1. **理解配置**：仔细阅读 `CMakeLists.txt`，理解每个配置项的作用
2. **动手实践**：按照文档中的步骤构建和运行项目
3. **尝试修改**：尝试修改 `CMakeLists.txt`，观察效果
4. **阅读文档**：参考 `docs/stage1/30-cmake-advanced.md` 了解详细说明

## 相关文档

- **主文档**：`docs/stage1/30-cmake-advanced.md`
- **下一步学习**：`docs/stage1/31-qt-environment-setup.md`（Qt 环境搭建）

## 注意事项

- 所有代码均使用 C++17 标准编写
- 确保您的编译器支持 C++17
- 需要安装 Qt6 才能构建本项目
- 建议按照文档中的学习顺序逐步学习
