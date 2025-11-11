// OOP 综合练习 - 图书管理系统
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

// 图书基类（抽象类）
class Book {
protected:
    std::string title;      // 书名
    std::string author;     // 作者
    double price;           // 价格
    int stock;              // 库存数量

public:
    Book(const std::string& t, const std::string& a, double p, int s)
        : title(t), author(a), price(p), stock(s) {}

    virtual ~Book() {}  // 虚析构函数

    // Getter 方法
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    double getPrice() const { return price; }
    int getStock() const { return stock; }

    // Setter 方法（带验证）
    void setPrice(double p) {
        if (p >= 0) {
            price = p;
        }
    }

    void setStock(int s) {
        if (s >= 0) {
            stock = s;
        }
    }

    // 借阅图书
    bool borrow() {
        if (stock > 0) {
            stock--;
            return true;
        }
        return false;
    }

    // 归还图书
    void returnBook() {
        stock++;
    }

    // 纯虚函数：显示图书信息（不同图书类型有不同的显示方式）
    virtual void displayInfo() const = 0;

    // 纯虚函数：获取图书类型
    virtual std::string getType() const = 0;

    // 虚函数：保存到文件（可以被子类重写）
    virtual void saveToFile(std::ofstream& file) const {
        file << getType() << " " << title << " " << author 
             << " " << price << " " << stock << std::endl;
    }
};

// 普通图书类
class RegularBook : public Book {
public:
    RegularBook(const std::string& t, const std::string& a, double p, int s)
        : Book(t, a, p, s) {}

    void displayInfo() const override {
        std::cout << "=== 普通图书 ===" << std::endl;
        std::cout << "书名: " << title << std::endl;
        std::cout << "作者: " << author << std::endl;
        std::cout << "价格: ¥" << price << std::endl;
        std::cout << "库存: " << stock << " 本" << std::endl;
    }

    std::string getType() const override {
        return "Regular";
    }
};

// 电子图书类
class EBook : public Book {
private:
    std::string format;  // 格式（PDF、EPUB 等）

public:
    EBook(const std::string& t, const std::string& a, double p, int s, 
          const std::string& f)
        : Book(t, a, p, s), format(f) {}

    std::string getFormat() const { return format; }

    void displayInfo() const override {
        std::cout << "=== 电子图书 ===" << std::endl;
        std::cout << "书名: " << title << std::endl;
        std::cout << "作者: " << author << std::endl;
        std::cout << "价格: ¥" << price << std::endl;
        std::cout << "格式: " << format << std::endl;
        std::cout << "库存: " << stock << " 份" << std::endl;
    }

    std::string getType() const override {
        return "EBook";
    }

    void saveToFile(std::ofstream& file) const override {
        file << getType() << " " << title << " " << author 
             << " " << price << " " << stock << " " << format << std::endl;
    }
};

// 有声图书类
class AudioBook : public Book {
private:
    int duration;  // 时长（分钟）

public:
    AudioBook(const std::string& t, const std::string& a, double p, int s, 
              int d)
        : Book(t, a, p, s), duration(d) {}

    int getDuration() const { return duration; }

    void displayInfo() const override {
        std::cout << "=== 有声图书 ===" << std::endl;
        std::cout << "书名: " << title << std::endl;
        std::cout << "作者: " << author << std::endl;
        std::cout << "价格: ¥" << price << std::endl;
        std::cout << "时长: " << duration << " 分钟" << std::endl;
        std::cout << "库存: " << stock << " 份" << std::endl;
    }

    std::string getType() const override {
        return "Audio";
    }

    void saveToFile(std::ofstream& file) const override {
        file << getType() << " " << title << " " << author 
             << " " << price << " " << stock << " " << duration << std::endl;
    }
};

// 图书管理类
class BookManager {
private:
    std::vector<std::unique_ptr<Book>> books;  // 使用智能指针管理图书
    const std::string filename = "books.txt";

public:
    // 添加图书（使用多态）
    void addBook(std::unique_ptr<Book> book) {
        books.push_back(std::move(book));
        std::cout << "添加图书成功！" << std::endl;
    }

    // 显示所有图书（使用多态）
    void displayAllBooks() const {
        if (books.empty()) {
            std::cout << "图书库为空" << std::endl;
            return;
        }

        std::cout << "\n=== 图书列表 ===" << std::endl;
        for (size_t i = 0; i < books.size(); i++) {
            std::cout << "\n[" << (i + 1) << "] ";
            books[i]->displayInfo();  // 多态：根据实际类型调用相应的函数
        }
    }

    // 借阅图书
    bool borrowBook(int index) {
        if (index >= 0 && index < static_cast<int>(books.size())) {
            if (books[index]->borrow()) {
                std::cout << "借阅成功！" << std::endl;
                return true;
            } else {
                std::cout << "库存不足，无法借阅" << std::endl;
                return false;
            }
        } else {
            std::cout << "无效的图书编号" << std::endl;
            return false;
        }
    }

    // 归还图书
    void returnBook(int index) {
        if (index >= 0 && index < static_cast<int>(books.size())) {
            books[index]->returnBook();
            std::cout << "归还成功！" << std::endl;
        } else {
            std::cout << "无效的图书编号" << std::endl;
        }
    }

    // 保存图书到文件
    void saveToFile() const {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& book : books) {
                book->saveToFile(file);  // 多态：根据实际类型调用相应的函数
            }
            file.close();
            std::cout << "图书数据已保存到文件" << std::endl;
        } else {
            std::cout << "无法保存文件" << std::endl;
        }
    }

    // 从文件加载图书
    void loadFromFile() {
        std::ifstream file(filename);
        if (file.is_open()) {
            books.clear();
            std::string type, title, author, format;
            double price;
            int stock, duration;

            while (file >> type) {
                if (type == "Regular") {
                    file >> title >> author >> price >> stock;
                    books.push_back(std::make_unique<RegularBook>(title, author, price, stock));
                } else if (type == "EBook") {
                    file >> title >> author >> price >> stock >> format;
                    books.push_back(std::make_unique<EBook>(title, author, price, stock, format));
                } else if (type == "Audio") {
                    file >> title >> author >> price >> stock >> duration;
                    books.push_back(std::make_unique<AudioBook>(title, author, price, stock, duration));
                }
            }
            file.close();
            std::cout << "图书数据已从文件加载" << std::endl;
        } else {
            std::cout << "文件不存在，将创建新文件" << std::endl;
        }
    }
};

int main() {
    std::cout << "=== 图书管理系统 ===" << std::endl;

    BookManager manager;

    // 从文件加载数据
    std::cout << "\n=== 加载数据 ===" << std::endl;
    manager.loadFromFile();

    // 添加图书（使用多态）
    std::cout << "\n=== 添加图书 ===" << std::endl;
    manager.addBook(std::make_unique<RegularBook>("C++ Primer", "Stanley Lippman", 128.0, 5));
    manager.addBook(std::make_unique<EBook>("Effective C++", "Scott Meyers", 68.0, 10, "PDF"));
    manager.addBook(std::make_unique<AudioBook>("设计模式", "四人帮", 88.0, 3, 360));

    // 显示所有图书（使用多态）
    manager.displayAllBooks();

    // 借阅图书
    std::cout << "\n=== 借阅图书 ===" << std::endl;
    manager.borrowBook(0);  // 借阅第一本书

    // 显示更新后的信息
    manager.displayAllBooks();

    // 保存数据到文件
    std::cout << "\n=== 保存数据 ===" << std::endl;
    manager.saveToFile();

    return 0;
}
