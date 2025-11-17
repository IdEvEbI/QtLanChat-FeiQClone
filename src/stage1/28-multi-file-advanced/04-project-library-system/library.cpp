#include "library.h"
#include "book.h"               // 实现时需要完整定义
#include <iostream>
#include <algorithm>

namespace LibrarySystem {
    void Library::addBook(Book* book) {
        books.push_back(book);
    }

    void Library::borrowBook(const std::string& title) {
        for (Book* book : books) {
            if (book->title == title && !book->isBorrowed) {  // 友元类可以访问私有成员
                book->isBorrowed = true;
                std::cout << "借出图书: " << title << std::endl;
                return;
            }
        }
        std::cout << "未找到可借阅的图书: " << title << std::endl;
    }

    void Library::returnBook(const std::string& title) {
        for (Book* book : books) {
            if (book->title == title && book->isBorrowed) {
                book->isBorrowed = false;
                std::cout << "归还图书: " << title << std::endl;
                return;
            }
        }
        std::cout << "未找到需要归还的图书: " << title << std::endl;
    }

    void Library::printAllBooks() const {
        std::cout << "=== 所有图书 ===" << std::endl;
        for (const Book* book : books) {
            std::cout << book->title << " - " << book->author;
            if (book->isBorrowed) {
                std::cout << " [已借出]";
            }
            std::cout << std::endl;
        }
    }

    int Library::getBookCount() const {
        return static_cast<int>(books.size());
    }
}

