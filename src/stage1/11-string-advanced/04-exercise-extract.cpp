#include <iostream>
#include <string>

int main() {
    std::string email;

    std::cout << "请输入邮箱地址: ";
    std::cin >> email;

    // 查找 @ 符号位置
    size_t atPos = email.find("@");  // find() 返回 size_t 类型
    if (atPos != std::string::npos) {
        // 提取用户名（@ 之前的部分）
        std::string username = email.substr(0, atPos);
        // 提取域名（@ 之后的部分）
        std::string domain = email.substr(atPos + 1);

        std::cout << "用户名: " << username << std::endl;
        std::cout << "域名: " << domain << std::endl;
    } else {
        std::cout << "无效的邮箱格式" << std::endl;
    }

    return 0;
}

