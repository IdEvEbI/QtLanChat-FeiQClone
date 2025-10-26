# C++ 变量和常量教程配套代码

本目录包含 `docs/stage1/02-variables-constants.md` 文档的所有配套 C++ 源代码示例和练习。

## 文件列表

### 基础示例

- `01-basic-variables.cpp`: 基础变量和常量声明示例
- `02-variable-scope.cpp`: 变量作用域示例
- `03-project-example.cpp`: QtLanChat 项目中的变量和常量应用示例

### 练习题

- `04-exercise-personal-info.cpp`: 练习 1 - 个人信息存储
- `05-exercise-math-calculator.cpp`: 练习 2 - 简单数学计算
- `06-exercise-naming-convention.cpp`: 练习 3 - 变量命名规范
- `07-exercise-constants.cpp`: 练习 4 - 常量使用
- `08-exercise-calculator.cpp`: 练习 5 - 综合计算器应用

### 课后作业

- `09-homework-student-system.cpp`: 综合练习 - 学生信息管理系统

## 如何运行

### 使用命令行

1. 打开终端或命令行工具。
2. 导航到对应的代码文件目录，例如：

   ```bash
   cd src/stage1/02-variables-constants/
   ```

3. 编译并运行：

   ```bash
   g++ -std=c++17 -o <可执行文件名> <源文件名>.cpp && ./<可执行文件名>
   # 示例：
   # g++ -std=c++17 -o basic_vars 01-basic-variables.cpp && ./basic_vars
   ```

### 使用 VSCode (推荐)

1. 确保已安装 "Code Runner" 扩展 (`formulahendry.code-runner`)。
2. 打开任意 `.cpp` 文件。
3. **一键运行**：按 `Ctrl+Alt+N` 或点击右上角的 ▶️ 按钮。
4. **调试运行**：按 `F5` 键进行调试。

## 注意事项

- 所有代码均使用 C++17 标准编写。
- 确保您的编译器支持 C++17。
- 建议按照文档中的学习顺序逐步运行和练习。

## 学习建议

1. **按顺序学习**：从 `01-basic-variables.cpp` 开始，逐步学习每个示例
2. **理解概念**：仔细阅读代码中的注释，理解变量和常量的概念
3. **动手实践**：每个示例都要亲自编译运行
4. **对比学习**：比较不同示例的代码，理解变量作用域和命名规范
5. **完成练习**：独立完成所有练习题，加深理解
6. **综合应用**：完成课后作业，巩固所学知识

## 核心概念

- **变量声明**：先声明后使用，建议初始化
- **常量定义**：使用 `const` 关键字，值不可修改
- **作用域管理**：全局变量和局部变量的可见范围
- **命名规范**：见名知义，遵循 C++ 命名约定
- **数据类型**：`int`、`double`、`std::string`、`bool` 等基本类型
