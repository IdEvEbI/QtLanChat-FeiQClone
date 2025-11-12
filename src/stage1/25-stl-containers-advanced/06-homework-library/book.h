// book.h
#pragma once

#include <string>

class Book {
private:
    std::string isbn;
    std::string title;
    std::string author;
    double price;

public:
    Book(const std::string& i, const std::string& t, const std::string& a, double p);
    std::string getIsbn() const;
    void printInfo() const;
};
