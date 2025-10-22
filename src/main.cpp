#include <iostream>
#include <string>

/**
 * @brief HelloWorld 类 - 用于测试 C++ 编译和调试
 */
class HelloWorld {
public:
    /**
     * @brief 构造函数
     * @param name 要问候的名字
     */
    HelloWorld(const std::string& name) : name_(name) {}
    
    /**
     * @brief 打印问候信息
     */
    void sayHello() {
        std::cout << "Hello, " << name_ << "!" << std::endl;
        std::cout << "欢迎使用 Cursor 开发 C++ 项目！" << std::endl;
    }
    
    /**
     * @brief 获取名字
     * @return 名字字符串
     */
    std::string getName() const {
        return name_;
    }

private:
    std::string name_;
};

/**
 * @brief 主函数 - 程序入口点
 * @return 程序退出状态码
 */
int main() {
    // 创建 HelloWorld 对象
    HelloWorld hello("World");
    
    // 打印问候信息
    hello.sayHello();
    
    // 测试调试功能 - 设置断点
    std::cout << "当前名字: " << hello.getName() << std::endl;
    
    // 测试循环
    for (int i = 1; i <= 3; ++i) {
        std::cout << "计数: " << i << std::endl;
    }
    
    std::cout << "程序执行完成！" << std::endl;
    return 0;
}
