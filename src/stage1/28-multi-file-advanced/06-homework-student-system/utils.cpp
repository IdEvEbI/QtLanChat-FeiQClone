#include "utils.h"

namespace StudentSystem {
    namespace Utils {
        std::string formatStudentInfo(const std::string& name, int age) {
            return name + " (" + std::to_string(age) + " 岁)";
        }
    }
}

