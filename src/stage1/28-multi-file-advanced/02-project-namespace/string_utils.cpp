#include "string_utils.h"
#include <algorithm>
#include <cctype>

namespace StringUtils {
    std::string add(const std::string& a, const std::string& b) {
        return a + b;
    }

    std::string toUpper(const std::string& str) {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(), ::toupper);
        return result;
    }
}

