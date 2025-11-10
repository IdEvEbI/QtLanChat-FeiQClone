#include <iostream>
#include <string>
#include <vector>

class Book {
public:
    std::string title;
    std::string author;
    double price;
    int stock;

    // 构造函数
    Book(const std::string& bookTitle, const std::string& bookAuthor,
         double bookPrice, int bookStock) {
        title = bookTitle;
        author = bookAuthor;
        price = bookPrice;
        stock = bookStock;
    }

    // 打印图书信息
    void printInfo() {
        std::cout << "《" << title << "》" << std::endl;
        std::cout << "  作者: " << author << std::endl;
        std::cout << "  价格: " << price << " 元" << std::endl;
        std::cout << "  库存: " << stock << " 本" << std::endl;
    }

    // 更新库存
    void updateStock(int newStock) {
        stock = newStock;
        std::cout << "《" << title << "》的库存已更新为: " << stock << " 本" << std::endl;
    }
};

int main() {
    std::vector<Book> books;

    // 创建图书对象
    books.push_back(Book("C++ Primer", "Stanley B. Lippman", 128.0, 10));
    books.push_back(Book("Effective C++", "Scott Meyers", 89.0, 5));
    books.push_back(Book("The C++ Programming Language", "Bjarne Stroustrup", 158.0, 8));

    // 显示所有图书
    std::cout << "=== 图书列表 ===" << std::endl;
    for (size_t i = 0; i < books.size(); i++) {
        std::cout << (i + 1) << ". ";
        books[i].printInfo();
        std::cout << std::endl;
    }

    // 更新库存
    std::cout << "=== 更新库存 ===" << std::endl;
    books[0].updateStock(15);
    books[0].printInfo();

    return 0;
}
