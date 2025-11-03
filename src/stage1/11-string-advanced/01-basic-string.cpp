// 现代 C++ 示例 - 字符串操作
#include <iostream>
#include <string>

int main() {
    // 示例 1：字符串基础操作
    std::cout << "=== 字符串基础 ===" << std::endl;
    std::string name = "张三";

    std::cout << "姓名: " << name << std::endl;
    std::cout << "长度: " << name.length() << std::endl;
    std::cout << "是否为空: " << (name.empty() ? "是" : "否") << std::endl;

    // 示例 2：字符串拼接
    std::cout << "\n=== 字符串拼接 ===" << std::endl;
    std::string firstName = "张";
    std::string lastName = "三";

    std::string fullName = firstName + lastName;  // 拼接
    std::cout << "全名: " << fullName << std::endl;

    firstName += "伟";  // 修改
    std::cout << "修改后: " << firstName << std::endl;

    // 示例 3：字符串比较
    std::cout << "\n=== 字符串比较 ===" << std::endl;
    std::string str1 = "Hello";
    std::string str2 = "World";

    if (str1 == str2) {
        std::cout << "相等" << std::endl;
    } else {
        std::cout << "不相等" << std::endl;
    }

    if (str1 < str2) {
        std::cout << str1 << " 在 " << str2 << " 前面" << std::endl;
    }

    // 示例 4：访问字符
    std::cout << "\n=== 访问字符 ===" << std::endl;
    std::string text = "Hello";

    std::cout << "第一个字符: " << text[0] << std::endl;
    std::cout << "最后一个字符: " << text[text.length() - 1] << std::endl;

    // 遍历所有字符（注意：这种方式对于英文字符正常，对于中文字符需要特殊处理）
    for (size_t i = 0; i < text.length(); i++) {
        std::cout << text[i] << " ";
    }
    std::cout << std::endl;

    // 示例 5：字符串查找
    std::cout << "\n=== 字符串查找 ===" << std::endl;
    std::string message = "Hello World";

    size_t pos = message.find("World");  // find() 返回 size_t 类型
    if (pos != std::string::npos) {
        std::cout << "找到了 'World'，位置: " << pos << std::endl;
    } else {
        std::cout << "未找到" << std::endl;
    }

    return 0;
}

