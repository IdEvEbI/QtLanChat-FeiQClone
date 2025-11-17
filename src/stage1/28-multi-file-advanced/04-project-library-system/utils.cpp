#include "utils.h"

namespace LibrarySystem {
    namespace Utils {
        std::string formatBookInfo(const std::string& title, const std::string& author) {
            return title + " by " + author;
        }
    }
}

