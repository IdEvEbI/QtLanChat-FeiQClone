// library.cpp
#include "library.h"
#include <iostream>

void Library::addBook(const Book& book) {
    books.emplace(book.getIsbn(), book);
}

Book* Library::findBook(const std::string& isbn) {
    auto it = books.find(isbn);
    if (it != books.end()) {
        return &(it->second);
    }
    return nullptr;
}

const Book* Library::findBook(const std::string& isbn) const {
    auto it = books.find(isbn);
    if (it != books.end()) {
        return &(it->second);
    }
    return nullptr;
}

bool Library::borrowBook(const std::string& isbn) {
    Book* book = findBook(isbn);
    if (book != nullptr && borrowedBooks.find(isbn) == borrowedBooks.end()) {
        borrowedBooks.insert(isbn);
        return true;
    }
    return false;
}

bool Library::returnBook(const std::string& isbn) {
    if (borrowedBooks.find(isbn) != borrowedBooks.end()) {
        borrowedBooks.erase(isbn);
        return true;
    }
    return false;
}

void Library::printAllBooks() const {
    std::cout << "=== All Books ===" << std::endl;
    for (const auto& pair : books) {
        pair.second.printInfo();
    }
}

void Library::printBorrowedBooks() const {
    std::cout << "\n=== Borrowed Books ===" << std::endl;
    for (const auto& isbn : borrowedBooks) {
        const Book* book = findBook(isbn);
        if (book != nullptr) {
            book->printInfo();
        }
    }
}
