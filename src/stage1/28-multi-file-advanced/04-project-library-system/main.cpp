#include <iostream>
#include "book.h"
#include "library.h"
#include "utils.h"

int main() {
    using namespace LibrarySystem;

    // 创建图书
    Book book1("C++ Primer", "Stanley Lippman");
    Book book2("Effective C++", "Scott Meyers");
    Book book3("The C++ Programming Language", "Bjarne Stroustrup");

    std::cout << "图书总数: " << Book::getTotalBooks() << std::endl;

    // 创建图书馆
    Library library;
    library.addBook(&book1);
    library.addBook(&book2);
    library.addBook(&book3);

    // 显示所有图书
    library.printAllBooks();

    // 借阅图书
    library.borrowBook("C++ Primer");
    library.borrowBook("Effective C++");

    // 显示所有图书
    library.printAllBooks();

    // 归还图书
    library.returnBook("C++ Primer");

    // 显示所有图书
    library.printAllBooks();

    return 0;
}

