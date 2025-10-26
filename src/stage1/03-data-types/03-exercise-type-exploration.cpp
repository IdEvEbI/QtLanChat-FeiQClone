// 练习 1：类型探索
#include <iostream>
#include <climits>

int main() {
    std::cout << "=== 数据类型探索 ===" << std::endl;

    // 整数类型大小和范围
    std::cout << "整数类型信息:" << std::endl;
    std::cout << "int 大小: " << sizeof(int) << " 字节" << std::endl;
    std::cout << "int 范围: " << INT_MIN << " 到 " << INT_MAX << std::endl;
    std::cout << "short 大小: " << sizeof(short) << " 字节" << std::endl;
    std::cout << "long 大小: " << sizeof(long) << " 字节" << std::endl;
    std::cout << "long long 大小: " << sizeof(long long) << " 字节" << std::endl;

    // 浮点类型精度
    std::cout << "\n浮点类型信息:" << std::endl;
    std::cout << "float 大小: " << sizeof(float) << " 字节" << std::endl;
    std::cout << "double 大小: " << sizeof(double) << " 字节" << std::endl;
    std::cout << "long double 大小: " << sizeof(long double) << " 字节" << std::endl;

    // 其他类型
    std::cout << "\n其他类型信息:" << std::endl;
    std::cout << "char 大小: " << sizeof(char) << " 字节" << std::endl;
    std::cout << "bool 大小: " << sizeof(bool) << " 字节" << std::endl;

    return 0;
}

