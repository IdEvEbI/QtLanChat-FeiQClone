#pragma once

#include <vector>
#include <string>

namespace LibrarySystem {
    class Book;                 // 前向声明

    class Library {
    private:
        std::vector<Book*> books;   // 使用指针，前向声明足够

    public:
        void addBook(Book* book);
        void borrowBook(const std::string& title);
        void returnBook(const std::string& title);
        void printAllBooks() const;
        int getBookCount() const;
    };
}

