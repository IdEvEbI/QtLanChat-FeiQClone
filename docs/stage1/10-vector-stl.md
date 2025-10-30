# std::vector 详解

> **学习目标**：掌握 C++ std::vector 容器的使用，能够动态管理数组  
> **前置知识**：C++ 数组基础、for 循环  
> **预计时间**：45 分钟  
> **难度等级**：⭐⭐⭐  
> **技能收获**：vector 声明、动态大小、常用方法、STL 容器基础  
> **文档版本**：v1.0  
> **最后更新**：2025-10-26

📊 **难度等级说明**

| 等级           | 描述                       | 练习题数量     | 颜色码 |
| -------------- | -------------------------- | -------------- | ------ |
| **⭐**         | 入门级，零基础可学         | 5 题基础概念题 | 🟢绿   |
| **⭐⭐**       | 基础级，需要基本编程概念   | 5 题基础概念题 | 🟡黄   |
| **⭐⭐⭐**     | 中级，需要相关技术基础     | 3 题代码分析题 | 🟠橙   |
| **⭐⭐⭐⭐**   | 高级，需要扎实的技术功底   | 3 题代码分析题 | 🔴红   |
| **⭐⭐⭐⭐⭐** | 专家级，需要丰富的项目经验 | 2 题设计思考题 | 🟣紫   |

## 1. 学习目标

### 1.1 学习动机

- **实际需求**：`std::vector` 是动态数组，可以随时添加和删除元素，解决了 C 风格数组大小固定的问题
- **应用场景**：不确定数量的数据存储、动态管理用户列表、弹性的数据处理
- **技能价值**：学会后能编写更灵活的程序，无需提前知道数据量
- **数据支持**：`std::vector` 是现代 C++ 中使用频率最高的容器，90% 的场景替代了 C 风格数组

### 1.2 技能树位置

```mermaid
graph TD
    A[C++ 技能树] --> B[基础语法 ⭐⭐]
    A --> C[内存管理 ⭐⭐⭐]
    A --> D[面向对象 ⭐⭐⭐⭐]

    B --> B1[变量和常量 ✅]
    B --> B2[数据类型 ✅]
    B --> B3[控制结构 ✅]
    B --> B4[数组 ✅]
    B --> B5[函数基础 ⏳]
    B --> B6[指针和引用 ⏳]

    C --> C1[STL容器 🔄]
    C --> C2[智能指针 ⏳]

    D --> D1[类和对象 ⏳]
    D --> D2[封装 ⏳]

    style C1 fill:#ffeb3b
```

> **图表说明**：C++ 技能树结构图，当前文档点亮 STL 容器技能点

### 1.3 前置知识检查

在开始学习之前，请确认你已经掌握：

- [ ] C++ 数组的声明和初始化
- [ ] for 循环的基本使用
- [ ] 数组的遍历和访问
- [ ] 基本数据类型（int、std::string）

> **未掌握处理**：若未通过，请先复习 [数组基础](./09-array-basics.md)

## 2. 核心内容

### 2.1 概念理解

**std::vector**：C++ 标准库中的动态数组容器，可以自动调整大小，支持随时添加和删除元素。

> **类比教学**：`std::vector` 就像一个可以自动扩展的仓库，你不需要提前知道要存多少东西，随时可以往里放，也可以随时拿走。相比 C 风格数组的"固定大小的房子"，vector 就像"可伸缩的帐篷"，需要多少空间就展开多少空间。

### 2.2 基础语法

C++ 中的 vector 是模板类，需要包含头文件：

```cpp
#include <vector>  // vector 头文件
```

#### 2.2.1 vector 基本语法

```cpp
std::vector<类型> 变量名;
```

> 语法说明：声明一个 vector，类型可以是任何数据类型。`<类型>` 是模板参数，指定存储什么类型的数据。

**类比**：就像"我要一个可以装整数的袋子"或"我要一个可以装字符串的袋子"，`<>` 里指定装什么类型的东西。

#### 2.2.2 vector 初始化

```cpp
// 方式 1：声明空 vector（推荐）
std::vector<int> vec;  // 空的整数 vector

// 方式 2：指定初始大小
std::vector<int> vec(5);  // 5 个整数，初始值为 0

// 方式 3：指定初始大小和初始值
std::vector<int> vec(5, 10);  // 5 个整数，都是 10

// 方式 4：从数组初始化
int arr[] = {1, 2, 3, 4, 5};
std::vector<int> vec(arr, arr + 5);  // 从数组复制
```

**类比**：方式 1 就像"先拿个空袋子"，方式 2 就像"拿个能装 5 个东西的袋子（都是空的）"，方式 3 就像"拿个能装 5 个东西的袋子（都装 10）"，方式 4 就像"把现有盒子里的东西搬到袋子里"。

### 2.3 代码示例

#### 2.3.1 基础示例

以下代码演示了 vector 的各种使用场景：

```cpp
// 现代 C++ 示例 - vector 基础
#include <iostream>
#include <vector>

int main() {
    // 示例 1：声明和使用 vector
    std::cout << "=== 基本使用 ===" << std::endl;
    std::vector<int> vec;

    vec.push_back(10);  // 添加元素
    vec.push_back(20);
    vec.push_back(30);

    std::cout << "第一个元素: " << vec[0] << std::endl;
    std::cout << "向量大小: " << vec.size() << std::endl;

    // 示例 2：遍历 vector
    std::cout << "\n=== 遍历 vector ===" << std::endl;
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // 示例 3：访问和修改元素
    std::cout << "\n=== 修改元素 ===" << std::endl;
    vec[0] = 100;  // 修改第一个元素
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // 示例 4：删除元素
    std::cout << "\n=== 删除元素 ===" << std::endl;
    vec.pop_back();  // 删除最后一个元素
    std::cout << "删除后的大小: " << vec.size() << std::endl;
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // 示例 5：判断是否为空
    std::cout << "\n=== 判断是否为空 ===" << std::endl;
    if (!vec.empty()) {
        std::cout << "vector 不为空，包含 " << vec.size() << " 个元素" << std::endl;
    }

    return 0;
}
```

> **📌 重要提示**：vector 需要在 `<>` 中指定类型，如 `std::vector<int>`、`std::vector<std::string>`。

#### 2.3.2 配套代码文件

项目提供了配套的源代码文件：

- **文件位置**：`src/stage1/10-vector-stl/01-basic-vector.cpp`
- **文件内容**：与上面示例完全一致的 vector 程序

> **运行提示**：具体的编译运行方法请参考 [C++ 简介和快速入门](./01-cpp-introduction.md) 中的 `2.2.3 编译运行` 部分

#### 2.3.3 运行预期结果

```
=== 基本使用 ===
第一个元素: 10
向量大小: 3

=== 遍历 vector ===
10 20 30

=== 修改元素 ===
100 20 30

=== 删除元素 ===
删除后的大小: 2
100 20

=== 判断是否为空 ===
vector 不为空，包含 2 个元素
```

#### 2.3.4 代码详解

以下代码片段展示了基础示例中的核心用法：

```cpp
// 声明 vector
std::vector<int> vec;  // 声明一个整数 vector

// 添加元素
vec.push_back(10);
vec.push_back(20);
```

**详细说明**：

- **`std::vector<int>`**：声明一个存储整数的 vector
- **`push_back()`**：在 vector 末尾添加元素
- **类比**：就像往袋子里装东西，一个一个地放进去

```cpp
// 访问元素
std::cout << vec[0] << std::endl;  // 输出第一个元素
std::cout << vec.size() << std::endl;  // 输出大小
```

**详细说明**：

- **`vec[0]`**：访问第 0 个元素（与数组相同）
- **`vec.size()`**：返回 vector 中元素的数量
- **类比**：就像看袋子的大小，可以知道里面装了多少东西

```cpp
// 遍历 vector
for (int i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << " ";
}
```

**详细说明**：

- **循环条件**：`i < vec.size()` - 从 0 到大小减 1
- **访问方式**：`vec[i]` - 使用索引访问元素
- **动态大小**：`vec.size()` 会随着添加/删除元素而变化
- **类比**：就像从袋子里一个接一个地取出东西

**重要语法规则**：

1. **vector 是模板类**：必须用 `<>` 指定类型
   - `std::vector<int>` - 整数向量
   - `std::vector<std::string>` - 字符串向量
   - **类比**：就像说"我要装衣服的袋子"或"我要装书的袋子"

2. **动态大小**：可以随时添加和删除元素
   - `push_back()` - 在末尾添加元素
   - `pop_back()` - 删除最后一个元素
   - **类比**：袋子可以变大变小，随时调整

3. **常用方法**：
   - `size()` - 返回元素数量
   - `empty()` - 判断是否为空
   - `vec[i]` - 访问索引为 i 的元素

### 2.4 关键特性与设计原理

#### 2.4.1 关键特性

1. **动态大小**：可以随时添加和删除元素
2. **类型安全**：模板类型检查，避免类型错误
3. **自动内存管理**：自动分配和释放内存
4. **高效操作**：末尾添加/删除操作非常快速

#### 2.4.2 设计原理

- **为什么这样设计**：解决了 C 风格数组大小固定的问题，提供了更灵活的数据管理方式
- **解决了什么问题**：无需提前知道数据量，可以动态调整存储空间
- **有什么优势**：使用方便、内存自动管理、类型安全、代码简洁

## 3. 实践应用

### 3.1 项目场景

在 QtLanChat 项目中，vector 用于：

- **动态用户列表**：存储所有在线用户，数量随时变化
- **消息历史**：保存消息记录，可以动态添加
- **在线用户管理**：随时添加和删除用户

### 3.2 实际代码

以下代码展示了 vector 在 QtLanChat 项目中的实际应用：

```cpp
// 项目中的实际应用示例
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::cout << "=== QtLanChat 动态用户管理 ===" << std::endl;

    // 使用 vector 存储用户列表
    std::vector<std::string> users;

    // 添加用户
    std::cout << "\n用户上线..." << std::endl;
    users.push_back("张三");
    users.push_back("李四");
    users.push_back("王五");

    std::cout << "当前在线用户数: " << users.size() << std::endl;

    // 显示所有用户
    std::cout << "在线用户列表：" << std::endl;
    for (int i = 0; i < users.size(); i++) {
        std::cout << (i + 1) << ". " << users[i] << std::endl;
    }

    // 用户下线
    std::cout << "\n李四下线了" << std::endl;
    // 注意：实际项目中需要查找并删除特定元素，这里简化为删除最后一个
    users.pop_back();  // 简化为删除最后一个

    std::cout << "当前在线用户数: " << users.size() << std::endl;
    std::cout << "剩余用户：" << std::endl;
    for (int i = 0; i < users.size(); i++) {
        std::cout << (i + 1) << ". " << users[i] << std::endl;
    }

    return 0;
}
```

> **配套代码**：实际应用示例的完整代码位于 `src/stage1/10-vector-stl/02-project-example.cpp`

### 3.3 设计思路

- **为什么选择这种设计**：使用 vector 可以动态管理用户列表，无需提前知道用户数量
- **解决了什么问题**：实现了灵活的用户管理，可以随时添加和删除用户
- **有什么优势**：代码简洁、动态管理、易于维护

## 4. 练习与测试

### 4.1 练习题

#### 练习 1：动态成绩管理

**题目**：使用 vector 动态管理学生成绩

**要求**：

- 声明一个 `std::vector<int>` 存储成绩
- 使用 `push_back()` 添加 5 个成绩
- 使用 for 循环遍历并输出所有成绩
- 计算平均分

**参考答案**：

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> scores;

    // 添加成绩
    scores.push_back(85);
    scores.push_back(90);
    scores.push_back(78);
    scores.push_back(92);
    scores.push_back(88);

    // 遍历并计算平均分
    int sum = 0;
    std::cout << "成绩列表：" << std::endl;
    for (int i = 0; i < scores.size(); i++) {
        std::cout << "学生" << (i + 1) << ": " << scores[i] << std::endl;
        sum += scores[i];
    }

    double average = static_cast<double>(sum) / scores.size();
    std::cout << "\n平均分: " << average << std::endl;

    return 0;
}
```

> **配套代码**：练习 1 的完整代码位于 `src/stage1/10-vector-stl/03-exercise-scores.cpp`

#### 练习 2：动态数据管理

**题目**：使用 vector 动态添加和删除数据

**要求**：

- 创建一个整数 vector
- 使用循环添加 10 个数字（1 到 10）
- 删除所有偶数
- 输出剩余的数字

**参考答案**：

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;

    // 添加 1 到 10
    for (int i = 1; i <= 10; i++) {
        vec.push_back(i);
    }

    std::cout << "原始数据: ";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // 删除偶数（简化版：只删除最后几个）
    // 注意：实际的删除特定元素需要更复杂的逻辑
    while (!vec.empty() && vec[vec.size() - 1] % 2 == 0) {
        vec.pop_back();
    }

    std::cout << "删除偶数后: ";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

> **配套代码**：练习 2 的完整代码位于 `src/stage1/10-vector-stl/04-exercise-manage.cpp`

### 4.2 测试题（可选）

1. **关于 vector，下列说法正确的是：**
   A. vector 大小在声明时确定，不能改变

   B. vector 可以存储不同类型的数据

   C. vector 使用 `push_back()` 添加元素

   D. vector 索引从 1 开始
   **答案**：C

   **解析**：
   - **正确答案 C**：`push_back()` 在 vector 末尾添加元素
   - **错误答案 A**：vector 大小可以动态改变
   - **错误答案 B**：vector 只能存储相同类型的数据（由模板参数决定）
   - **错误答案 D**：vector 索引从 0 开始，与数组相同

### 4.3 常见问题 FAQ

- Q1：vector 和数组有什么区别？
  - **A：**数组大小固定，vector 大小可动态调整；数组不需要头文件，vector 需要 `#include <vector>`；数组分配在栈上，vector 分配在堆上。选择原则：确定大小用数组，不确定用 vector
- Q2：vector 什么时候会重新分配内存？
  - **A：**当添加元素导致容量不足时，vector 会自动分配更大的内存。类比：就像房子装不下时，搬家到更大的房子

## 5. 资源与扩展

### 5.1 基础资源

- **官方文档**：[C++ std::vector](https://en.cppreference.com/w/cpp/container/vector)
- **权威书籍**：《C++ Primer》- 第 3.3.2 节
- **在线教程**：[learncpp.com](https://www.learncpp.com/) - vector 教程

### 5.2 多媒体学习

- **视频资源**：[C++ vector 详解](https://www.youtube.com/results?search_query=C%2B%2B+vector+tutorial)
- **开发者资源**：[cppreference.com](https://en.cppreference.com/) - 权威参考

## 6. 课后作业及参考答案

### 6.1 学习检查清单

- [ ] 能够声明和使用 vector
- [ ] 掌握 `push_back()` 和 `pop_back()` 方法
- [ ] 理解 vector 的动态大小特性
- [ ] 能够遍历 vector

### 6.2 综合练习

**作业题目**：编写一个动态成绩管理系统

**要求**：

- 使用 vector 存储学生成绩
- 可以动态添加成绩
- 计算平均分、最高分、最低分
- 统计成绩分布

**时间估算**：30 分钟

**参考答案**：

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> scores;
    scores.push_back(85);
    scores.push_back(90);
    scores.push_back(78);
    scores.push_back(92);
    scores.push_back(88);

    int sum = 0;
    int max = scores[0];
    int min = scores[0];

    for (int i = 0; i < scores.size(); i++) {
        sum += scores[i];
        if (scores[i] > max) max = scores[i];
        if (scores[i] < min) min = scores[i];
    }

    double average = static_cast<double>(sum) / scores.size();

    std::cout << "=== 成绩管理系统 ===" << std::endl;
    std::cout << "平均分: " << average << std::endl;
    std::cout << "最高分: " << max << std::endl;
    std::cout << "最低分: " << min << std::endl;

    return 0;
}
```

**评分标准**：功能实现（40%）、vector 使用（30%）、代码质量（30%）

## 7. 下一步学习

**下一篇**：[11-string-advanced.md](./11-string-advanced.md)

**学习路径**：

1. ✅ C++ 简介和快速入门 - 已完成
2. ✅ 变量和常量 - 已完成
3. ✅ 数据类型详解 - 已完成
4. ✅ 运算符详解 - 已完成
5. ✅ if 分支详解 - 已完成
6. ✅ while 循环 - 已完成
7. ✅ for 循环 - 已完成
8. ✅ switch 分支 - 已完成
9. ✅ 数组基础 - 已完成
10. ✅ std::vector - 已完成
11. 🔄 字符串进阶 - 下一步

**技能树更新**：

```mermaid
graph TD
    A[C++ 技能树] --> B[基础语法 ⭐⭐]
    A --> C[STL 容器 ⭐⭐⭐]
    A --> D[面向对象 ⭐⭐⭐⭐]

    B --> B1[变量和常量 ✅]
    B --> B2[数据类型 ✅]
    B --> B3[控制结构 ✅]
    B --> B4[数组 ✅]
    B --> B5[函数基础 ⏳]

    C --> C1[vector ✅]
    C --> C2[其他容器 ⏳]

    style C1 fill:#4caf50
    style C2 fill:#ffeb3b
```

**学习成果**：

- **独立编写**：能够编写使用 vector 的程序
- **解释原理**：能够解释 vector 的动态大小机制
- **解决实际问题**：能够动态管理数据集合
- **应用到项目**：为后续更多 STL 容器学习打下基础
- **掌握度自评**：85%

### 学习成果指导

> **自评指导**：
>
> - **<50%**：建议复习 vector 基础，重新阅读文档核心内容
> - **50-80%**：继续学习，完成练习题巩固理解
> - **>80%**：可以进入下一阶段学习，开始字符串进阶
