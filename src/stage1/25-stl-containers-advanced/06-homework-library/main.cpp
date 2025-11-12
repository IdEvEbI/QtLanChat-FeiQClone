// main.cpp
#include <iostream>
#include "library.h"

int main() {
    Library library;

    // 添加图书
    library.addBook(Book("978-0-123456-78-9", "C++ Primer", "Stanley Lippman", 59.99));
    library.addBook(Book("978-0-987654-32-1", "Effective C++", "Scott Meyers", 49.99));
    library.addBook(Book("978-0-111111-11-1", "The C++ Programming Language", "Bjarne Stroustrup", 69.99));

    // 显示所有图书
    library.printAllBooks();

    // 借出图书
    library.borrowBook("978-0-123456-78-9");
    library.borrowBook("978-0-987654-32-1");

    // 显示已借出图书
    library.printBorrowedBooks();

    // 归还图书
    library.returnBook("978-0-123456-78-9");

    // 再次显示已借出图书
    std::cout << "\n=== After returning a book ===" << std::endl;
    library.printBorrowedBooks();

    return 0;
}
