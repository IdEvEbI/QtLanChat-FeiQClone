// book.cpp
#include "book.h"
#include <iostream>

Book::Book(const std::string& i, const std::string& t, const std::string& a, double p)
    : isbn(i), title(t), author(a), price(p) {}

std::string Book::getIsbn() const {
    return isbn;
}

void Book::printInfo() const {
    std::cout << "ISBN: " << isbn
              << ", Title: " << title
              << ", Author: " << author
              << ", Price: " << price << std::endl;
}
