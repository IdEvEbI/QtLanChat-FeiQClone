#include <iostream>
#include <string>

class Book {
protected:
    std::string title;
    std::string author;
    double price;

public:
    Book(const std::string& t, const std::string& a, double p)
        : title(t), author(a), price(p) {}

    void printInfo() {
        std::cout << "《" << title << "》" << std::endl;
        std::cout << "  作者: " << author << std::endl;
        std::cout << "  价格: " << price << " 元" << std::endl;
    }
};

class EBook : public Book {
private:
    double fileSize;  // MB

public:
    EBook(const std::string& t, const std::string& a, double p, double size)
        : Book(t, a, p), fileSize(size) {}

    void printDetailInfo() {
        printInfo();
        std::cout << "  文件大小: " << fileSize << " MB" << std::endl;
    }
};

class PaperBook : public Book {
private:
    int pages;

public:
    PaperBook(const std::string& t, const std::string& a, double p, int pgs)
        : Book(t, a, p), pages(pgs) {}

    void printDetailInfo() {
        printInfo();
        std::cout << "  页数: " << pages << " 页" << std::endl;
    }
};

int main() {
    EBook ebook("C++ Primer", "Stanley B. Lippman", 128.0, 15.5);
    ebook.printDetailInfo();

    std::cout << std::endl;

    PaperBook paperbook("Effective C++", "Scott Meyers", 89.0, 320);
    paperbook.printDetailInfo();

    return 0;
}
