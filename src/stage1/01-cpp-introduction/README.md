# C++ 简介和快速入门教程配套代码

本目录包含 `docs/stage1/01-cpp-introduction.md` 文档的所有配套 C++ 源代码示例和练习。

## 文件列表

### 基础示例

- `01-hello-world.cpp`: 基础 Hello World 程序
- `02-hello-detailed.cpp`: 带详细注释的 Hello World
- `03-hello-optimized.cpp`: 性能优化版本（使用 \n 替代 std::endl）
- `04-project-welcome.cpp`: QtLanChat 项目欢迎信息

### 练习题

- `05-exercise-name.cpp`: 练习 1 - 输出姓名
- `06-exercise-personal-info.cpp`: 练习 2 - 多行输出个人信息
- `07-exercise-structure.cpp`: 练习 3 - 程序结构理解
- `08-exercise-compile-run.cpp`: 练习 4 - 编译运行
- `09-exercise-optimization.cpp`: 练习 5 - 代码优化

### 课后作业

- `10-homework-comprehensive.cpp`: 综合练习 - 多行文本输出

## 如何运行

### 使用命令行

1. 打开终端或命令行工具。
2. 导航到对应的代码文件目录，例如：

   ```bash
   cd src/stage1/01-cpp-introduction/
   ```

3. 编译并运行：

   ```bash
   g++ -std=c++17 -o <可执行文件名> <源文件名>.cpp && ./<可执行文件名>
   # 示例：
   # g++ -std=c++17 -o hello 01-hello-world.cpp && ./hello
   ```

### 使用 VSCode (推荐)

1. 确保已安装 "Code Runner" 扩展 (`formulahendry.code-runner`)。
2. 打开任意 `.cpp` 文件。
3. **一键运行**：按 `Ctrl+Alt+N` 或点击右上角的 ▶️ 按钮。
4. **调试运行**：按 `F5` 键进行调试。

## 注意事项

- 所有代码均使用 C++17 标准编写。
- 确保您的编译器支持 C++17。
- Qt 相关的示例已移除，当前项目暂未配置 Qt 开发环境。
- 建议按照文档中的学习顺序逐步运行和练习。

## 学习建议

1. **按顺序学习**：从 `01-hello-world.cpp` 开始，逐步学习每个示例
2. **动手实践**：每个示例都要亲自编译运行
3. **理解注释**：仔细阅读代码中的注释，理解每行代码的作用
4. **对比学习**：比较不同版本的代码，理解优化和改进
5. **完成练习**：独立完成所有练习题，加深理解
