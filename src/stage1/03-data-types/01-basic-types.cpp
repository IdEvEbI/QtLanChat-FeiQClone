// 现代 C++ 示例 - 数据类型基础
#include <iostream>
#include <string>
#include <iomanip>

int main() {
    // 整数类型 - 像不同大小的计数器
    int age = 25;                                   // 4字节，一般整数
    short year = 2025;                              // 2字节，小整数
    long population = 1400000000L;                  // 4-8字节，大整数
    long long bigNumber = 9223372036854775807LL;    // 8字节，超大整数

    // 浮点类型 - 像不同精度的测量工具
    float price = 19.99f;                           // 4字节，单精度
    double pi = 3.141592653589793;                  // 8字节，双精度
    long double precise = 3.141592653589793238L;    // 8-16字节，高精度

    // 字符类型 - 像单个字母卡片
    char grade = 'A';                               // 1字节，单个字符

    // 布尔类型 - 像开关
    bool isStudent = true;                          // 1字节，真/假
    bool isWorking = false;

    // 字符串类型 - 像文字标签
    std::string name = "张三";                      // 动态长度，现代字符串

    // 输出所有类型
    std::cout << "=== 数据类型示例 ===" << std::endl;
    std::cout << "年龄: " << age << std::endl;
    std::cout << "年份: " << year << std::endl;
    std::cout << "人口: " << population << std::endl;
    std::cout << "大数: " << bigNumber << std::endl;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "价格: " << price << std::endl;
    std::cout << "圆周率: " << pi << std::endl;
    std::cout << "精确值: " << precise << std::endl;

    std::cout << "等级: " << grade << std::endl;

    std::cout << std::boolalpha;
    std::cout << "是学生: " << isStudent << std::endl;
    std::cout << "在工作: " << isWorking << std::endl;

    std::cout << "姓名: " << name << std::endl;
    std::cout << "姓名长度: " << name.length() << std::endl;

    // 显示各数据类型占用的字节数
    std::cout << "\n=== 数据类型大小 ===" << std::endl;
    std::cout << "int 大小: " << sizeof(int) << " 字节" << std::endl;
    std::cout << "short 大小: " << sizeof(short) << " 字节" << std::endl;
    std::cout << "long 大小: " << sizeof(long) << " 字节" << std::endl;
    std::cout << "long long 大小: " << sizeof(long long) << " 字节" << std::endl;
    std::cout << "float 大小: " << sizeof(float) << " 字节" << std::endl;
    std::cout << "double 大小: " << sizeof(double) << " 字节" << std::endl;
    std::cout << "long double 大小: " << sizeof(long double) << " 字节" << std::endl;
    std::cout << "char 大小: " << sizeof(char) << " 字节" << std::endl;
    std::cout << "bool 大小: " << sizeof(bool) << " 字节" << std::endl;

    return 0;
}

