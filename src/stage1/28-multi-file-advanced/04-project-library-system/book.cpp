#include "book.h"

namespace LibrarySystem {
    // 静态成员变量定义
    int Book::totalBooks = 0;

    Book::Book(const std::string& title, const std::string& author)
        : title(title), author(author), isBorrowed(false) {
        totalBooks++;           // 每创建一个 Book 对象，总数加 1
    }

    int Book::getTotalBooks() {
        return totalBooks;
    }

    std::string Book::getTitle() const {
        return title;
    }

    std::string Book::getAuthor() const {
        return author;
    }

    bool Book::getIsBorrowed() const {
        return isBorrowed;
    }
}

