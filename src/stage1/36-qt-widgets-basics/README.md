# Qt Widgets 基础控件示例代码

本目录包含 `36-qt-widgets-basics.md` 文档的配套代码示例。

## 目录结构

- `01-basic-widgets/`：基础控件示例（QPushButton、QLineEdit、QTextEdit、QLabel、QCheckBox、QRadioButton）
- `02-layouts/`：布局管理器示例（QVBoxLayout、QHBoxLayout、QGridLayout、QFormLayout）
- `03-main-window/`：QMainWindow 示例（菜单栏、工具栏、状态栏）
- `04-calculator/`：简单计算器应用示例
- `05-login-window/`：登录窗口示例

## 编译和运行

### 编译单个示例

```bash
cd src/stage1/36-qt-widgets-basics/01-basic-widgets
mkdir build && cd build
cmake ..
cmake --build .
```

### 运行示例

```bash
./BasicWidgets  # 或 ./Layouts, ./MainWindow, ./Calculator, ./LoginWindow
```

## 示例说明

### 01-basic-widgets

演示了 Qt Widgets 的基础控件使用方法：
- QPushButton：普通按钮、禁用按钮、切换按钮
- QLineEdit：单行输入框、密码输入框
- QTextEdit：多行文本输入框
- QLabel：文本标签、对齐方式、自动换行
- QCheckBox：复选框
- QRadioButton：单选按钮（使用 QButtonGroup 管理）

### 02-layouts

演示了 Qt 的布局管理器使用方法：
- QVBoxLayout：垂直布局
- QHBoxLayout：水平布局
- QGridLayout：网格布局（3x3 按钮网格）
- QFormLayout：表单布局（标签-输入框对）

### 03-main-window

演示了 QMainWindow 的使用方法：
- 菜单栏（QMenuBar、QMenu、QAction）
- 状态栏（QStatusBar）
- 中央控件（QWidget）

### 04-calculator

完整的计算器应用示例：
- 使用 QMainWindow 作为主窗口
- 使用 QFormLayout 创建表单（数字输入）
- 使用 QHBoxLayout 水平排列单选按钮（运算符选择）
- 使用 QVBoxLayout 垂直排列所有控件
- 实现基本的四则运算（加法、减法、乘法、除法）
- 包含输入验证和错误处理（除零检查）

### 05-login-window

登录窗口示例：
- 使用 QWidget 作为窗口
- 使用 QFormLayout 创建表单（用户名、密码）
- 密码输入框使用密码模式（setEchoMode）
- 简单的用户名和密码验证
- 使用样式表（setStyleSheet）设置文字颜色

## 注意事项

1. **Qt Widgets 模块**：所有示例都需要链接 `Qt6::Widgets` 模块
2. **MOC 处理**：使用 `Q_OBJECT` 宏的类需要 MOC 处理，CMakeLists.txt 中已设置 `CMAKE_AUTOMOC ON`
3. **信号槽连接**：示例中使用了 Lambda 表达式作为槽函数（已在之前的文档中学习）
4. **布局管理**：所有示例都使用布局管理器，确保窗口大小改变时控件自动调整

## 相关文档

- [36-qt-widgets-basics.md](../../../docs/stage1/36-qt-widgets-basics.md)

