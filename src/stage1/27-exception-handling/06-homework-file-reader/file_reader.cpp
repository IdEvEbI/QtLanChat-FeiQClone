#include "file_reader.h"
#include <fstream>
#include <stdexcept>

std::vector<std::string> FileReader::readFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("无法打开文件: " + filename);
    }

    std::vector<std::string> lines;
    std::string line;

    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    if (file.bad()) {
        throw std::runtime_error("读取文件时发生错误: " + filename);
    }

    return lines;
}

