#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

void logMessage(const std::string& message) {
    std::ofstream file("app.log", std::ios::app);
    if (file.is_open()) {
        // 获取当前时间（简化版）
        time_t now = time(0);
        file << "[" << now << "] " << message << std::endl;
        file.close();
        std::cout << "日志已记录" << std::endl;
    }
}

void readAllLogs() {
    std::ifstream file("app.log");
    if (file.is_open()) {
        std::cout << "\n=== 日志记录 ===" << std::endl;
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cout << "没有日志记录" << std::endl;
    }
}

int main() {
    logMessage("程序启动");
    logMessage("用户登录");
    logMessage("执行操作");
    logMessage("程序关闭");

    readAllLogs();

    return 0;
}
