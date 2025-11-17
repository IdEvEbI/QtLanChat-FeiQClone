#include <iostream>
#include <vector>
#include <string>
#include "file_reader.h"

int main() {
    FileReader reader;
    std::string filenames[] = {"test.txt", "nonexistent.txt"};

    for (const std::string& filename : filenames) {
        try {
            std::vector<std::string> lines = reader.readFile(filename);
            std::cout << "文件 " << filename << " 读取成功，共 " << lines.size() << " 行" << std::endl;
            for (const std::string& line : lines) {
                std::cout << line << std::endl;
            }
        } catch (const std::runtime_error& e) {
            std::cout << "错误: " << e.what() << std::endl;
        }
    }

    return 0;
}

