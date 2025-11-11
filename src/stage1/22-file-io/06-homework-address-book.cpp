#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Contact {
    std::string name;
    std::string phone;
    std::string email;
};

class AddressBook {
private:
    std::vector<Contact> contacts;
    const std::string filename = "contacts.txt";

public:
    // 从文件加载联系人
    void loadContacts() {
        std::ifstream file(filename);
        if (file.is_open()) {
            contacts.clear();
            std::string name, phone, email;

            while (file >> name >> phone >> email) {
                contacts.push_back({name, phone, email});
            }

            file.close();
            std::cout << "加载了 " << contacts.size() << " 个联系人" << std::endl;
        }
    }

    // 保存联系人到文件
    void saveContacts() {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& contact : contacts) {
                file << contact.name << " " << contact.phone
                     << " " << contact.email << std::endl;
            }
            file.close();
            std::cout << "联系人已保存" << std::endl;
        }
    }

    // 添加联系人
    void addContact(const std::string& name, const std::string& phone,
                    const std::string& email) {
        contacts.push_back({name, phone, email});
        std::cout << "添加联系人: " << name << std::endl;
    }

    // 显示所有联系人
    void displayAll() {
        std::cout << "\n=== 通讯录 ===" << std::endl;
        if (contacts.empty()) {
            std::cout << "通讯录为空" << std::endl;
            return;
        }

        for (size_t i = 0; i < contacts.size(); i++) {
            std::cout << (i + 1) << ". " << contacts[i].name
                      << ", 电话: " << contacts[i].phone
                      << ", 邮箱: " << contacts[i].email << std::endl;
        }
    }

    // 搜索联系人
    void searchContact(const std::string& name) {
        std::cout << "\n=== 搜索结果 ===" << std::endl;
        bool found = false;

        for (const auto& contact : contacts) {
            if (contact.name == name) {
                std::cout << "姓名: " << contact.name << std::endl;
                std::cout << "电话: " << contact.phone << std::endl;
                std::cout << "邮箱: " << contact.email << std::endl;
                found = true;
                break;
            }
        }

        if (!found) {
            std::cout << "未找到联系人: " << name << std::endl;
        }
    }
};

int main() {
    AddressBook book;

    // 加载联系人
    book.loadContacts();

    // 添加联系人
    book.addContact("张三", "13800138000", "zhangsan@example.com");
    book.addContact("李四", "13900139000", "lisi@example.com");
    book.addContact("王五", "13700137000", "wangwu@example.com");

    // 显示所有联系人
    book.displayAll();

    // 搜索联系人
    book.searchContact("李四");

    // 保存联系人
    book.saveContacts();

    return 0;
}
