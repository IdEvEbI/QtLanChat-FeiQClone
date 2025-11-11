#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream outFile("input.txt");

    if (outFile.is_open()) {
        std::cout << "请输入内容（输入 'end' 结束）：" << std::endl;
        std::string line;

        while (std::getline(std::cin, line) && line != "end") {
            outFile << line << std::endl;
        }

        outFile.close();
        std::cout << "内容已保存到文件" << std::endl;
    }

    // 读取文件
    std::ifstream inFile("input.txt");
    if (inFile.is_open()) {
        std::cout << "\n文件内容：" << std::endl;
        std::string line;
        while (std::getline(inFile, line)) {
            std::cout << line << std::endl;
        }
        inFile.close();
    }

    return 0;
}
