# Qt Widgets 高级控件示例代码

本目录包含 `37-qt-widgets-advanced.md` 文档的配套代码示例。

## 目录结构

- `01-list-widget/`：QListWidget 示例
- `02-table-widget/`：QTableWidget 示例
- `03-tree-widget/`：QTreeWidget 示例
- `04-progress-bar/`：QProgressBar 和 QProgressDialog 示例
- `05-combo-box/`：QComboBox 示例
- `06-scroll-area/`：QScrollArea 示例
- `07-student-management/`：完整的学生管理系统示例

## 编译和运行

### 编译单个示例

```bash
cd 01-list-widget  # 或其他示例目录
mkdir build && cd build
cmake ..
cmake --build .
```

### 运行示例

```bash
./ListWidget        # 01-list-widget
./TableWidget       # 02-table-widget
./TreeWidget        # 03-tree-widget
./ProgressBar       # 04-progress-bar
./ComboBox          # 05-combo-box
./ScrollArea        # 06-scroll-area
./StudentManagement # 07-student-management
```

## 示例说明

### 01-list-widget
演示 QListWidget 的基本用法，包括：
- 添加列表项
- 设置选择模式（多选）
- 响应列表项点击事件
- 获取选中的列表项

### 02-table-widget
演示 QTableWidget 的基本用法，包括：
- 创建表格并设置行列数
- 设置表头
- 填充表格数据
- 设置选择行为（行选择）
- 获取选中的行

### 03-tree-widget
演示 QTreeWidget 的基本用法，包括：
- 创建树形结构
- 添加顶级节点和子节点
- 响应节点点击事件
- 获取当前选中的节点

### 04-progress-bar
演示 QProgressBar 和 QProgressDialog 的用法，包括：
- QProgressBar 的基本使用
- 使用 QTimer 模拟进度更新
- QProgressDialog 的创建和使用
- 处理取消操作

### 05-combo-box
演示 QComboBox 的基本用法，包括：
- 添加选项
- 响应选择变化事件
- 获取当前选中的文本

### 06-scroll-area
演示 QScrollArea 的基本用法，包括：
- 创建滚动区域
- 设置内容控件
- 启用内容大小调整

### 07-student-management
完整的学生管理系统示例，综合使用多个高级控件：
- QListWidget：显示学生列表
- QTableWidget：显示学生详细信息
- QLineEdit：输入学生信息
- QProgressBar：显示数据加载进度
- 实现添加、删除学生功能
- 实现列表和表格的同步选择

## 注意事项

1. 所有示例都需要 Qt6 Widgets 模块
2. 确保已正确配置 Qt6 环境
3. 使用 CMake 3.20 或更高版本
4. 需要 C++17 或更高版本的编译器支持

