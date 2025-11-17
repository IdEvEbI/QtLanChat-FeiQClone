#pragma once

#include <string>

namespace LibrarySystem {
    class Library;              // 前向声明

    class Book {
    private:
        std::string title;
        std::string author;
        bool isBorrowed;

        // 静态成员变量：统计图书总数
        static int totalBooks;

        // 友元函数：允许 Library 访问私有成员
        friend class Library;

    public:
        Book(const std::string& title, const std::string& author);

        // 静态成员函数：获取图书总数
        static int getTotalBooks();

        std::string getTitle() const;
        std::string getAuthor() const;
        bool getIsBorrowed() const;
    };
}

