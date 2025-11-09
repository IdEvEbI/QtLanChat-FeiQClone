#include <iostream>
#include <string>
#include <vector>

struct Book {
    std::string title;      // 书名
    std::string author;     // 作者
    double price;           // 价格
    int stock;              // 库存
};

// 使用 const 引用打印图书信息
void printBook(const Book& book) {
    std::cout << "《" << book.title << "》" << std::endl;
    std::cout << "  作者: " << book.author << std::endl;
    std::cout << "  价格: " << book.price << " 元" << std::endl;
    std::cout << "  库存: " << book.stock << " 本" << std::endl;
}

// 显示所有图书
void printAllBooks(const std::vector<Book>& books) {
    std::cout << "=== 图书列表 ===" << std::endl;
    for (size_t i = 0; i < books.size(); i++) {
        std::cout << (i + 1) << ". ";
        printBook(books[i]);
        std::cout << std::endl;
    }
}

// 查找图书（按书名）
void findBook(const std::vector<Book>& books, const std::string& title) {
    bool found = false;
    for (const auto& book : books) {
        if (book.title == title) {
            std::cout << "找到图书：" << std::endl;
            printBook(book);
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "未找到图书: " << title << std::endl;
    }
}

int main() {
    std::vector<Book> books;

    // 添加图书
    books.push_back({"C++ Primer", "Stanley B. Lippman", 128.0, 10});
    books.push_back({"Effective C++", "Scott Meyers", 89.0, 5});
    books.push_back({"The C++ Programming Language", "Bjarne Stroustrup", 158.0, 8});

    // 显示所有图书
    printAllBooks(books);

    // 查找图书
    std::cout << "\n=== 查找图书 ===" << std::endl;
    findBook(books, "C++ Primer");
    findBook(books, "不存在的书");

    return 0;
}
