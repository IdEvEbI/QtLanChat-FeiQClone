// library.h
#pragma once

#include "book.h"
#include <map>
#include <set>
#include <string>

class Library {
private:
    std::map<std::string, Book> books;           // ISBN -> Book
    std::set<std::string> borrowedBooks;         // 已借出的 ISBN

public:
    void addBook(const Book& book);
    Book* findBook(const std::string& isbn);
    const Book* findBook(const std::string& isbn) const;
    bool borrowBook(const std::string& isbn);
    bool returnBook(const std::string& isbn);
    void printAllBooks() const;
    void printBorrowedBooks() const;
};
