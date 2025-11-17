#pragma once

#include <string>
#include <vector>

class FileReader {
public:
    std::vector<std::string> readFile(const std::string& filename);
};

