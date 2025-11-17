// 03-multiple-catch.cpp
#include <iostream>
#include <stdexcept>
#include <string>

void processNumber(int num) {
    if (num < 0) {
        throw std::invalid_argument("数字不能为负数");
    }
    if (num > 100) {
        throw std::out_of_range("数字不能大于 100");
    }
    if (num == 0) {
        throw std::runtime_error("数字不能为零");
    }
    std::cout << "处理数字: " << num << std::endl;
}

int main() {
    int numbers[] = {-5, 150, 0, 50};

    for (int num : numbers) {
        try {
            processNumber(num);
        } catch (const std::invalid_argument& e) {
            std::cout << "无效参数错误: " << e.what() << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "越界错误: " << e.what() << std::endl;
        } catch (const std::runtime_error& e) {
            std::cout << "运行时错误: " << e.what() << std::endl;
        } catch (...) {
            std::cout << "未知错误" << std::endl;
        }
    }

    return 0;
}

