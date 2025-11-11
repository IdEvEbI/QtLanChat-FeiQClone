// 练习 1：员工管理系统
#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Employee {
protected:
    std::string name;
    int age;
    double baseSalary;

public:
    Employee(const std::string& n, int a, double s)
        : name(n), age(a), baseSalary(s) {}

    virtual ~Employee() {}

    std::string getName() const { return name; }
    int getAge() const { return age; }

    // 纯虚函数：计算总工资
    virtual double calculateSalary() const = 0;

    // 纯虚函数：显示信息
    virtual void displayInfo() const = 0;
};

class Manager : public Employee {
private:
    double managementBonus;

public:
    Manager(const std::string& n, int a, double s, double b)
        : Employee(n, a, s), managementBonus(b) {}

    double calculateSalary() const override {
        return baseSalary + managementBonus;
    }

    void displayInfo() const override {
        std::cout << "=== 经理 ===" << std::endl;
        std::cout << "姓名: " << name << std::endl;
        std::cout << "年龄: " << age << std::endl;
        std::cout << "基本工资: ¥" << baseSalary << std::endl;
        std::cout << "管理津贴: ¥" << managementBonus << std::endl;
        std::cout << "总工资: ¥" << calculateSalary() << std::endl;
    }
};

class Developer : public Employee {
private:
    double projectBonus;

public:
    Developer(const std::string& n, int a, double s, double b)
        : Employee(n, a, s), projectBonus(b) {}

    double calculateSalary() const override {
        return baseSalary + projectBonus;
    }

    void displayInfo() const override {
        std::cout << "=== 开发者 ===" << std::endl;
        std::cout << "姓名: " << name << std::endl;
        std::cout << "年龄: " << age << std::endl;
        std::cout << "基本工资: ¥" << baseSalary << std::endl;
        std::cout << "项目奖金: ¥" << projectBonus << std::endl;
        std::cout << "总工资: ¥" << calculateSalary() << std::endl;
    }
};

class EmployeeManager {
private:
    std::vector<std::unique_ptr<Employee>> employees;

public:
    void addEmployee(std::unique_ptr<Employee> emp) {
        employees.push_back(std::move(emp));
    }

    void displayAll() const {
        for (size_t i = 0; i < employees.size(); i++) {
            std::cout << "\n[" << (i + 1) << "] ";
            employees[i]->displayInfo();  // 多态
        }
    }

    double calculateTotalSalary() const {
        double total = 0;
        for (const auto& emp : employees) {
            total += emp->calculateSalary();  // 多态
        }
        return total;
    }
};

int main() {
    EmployeeManager manager;

    manager.addEmployee(std::make_unique<Manager>("张三", 35, 10000, 5000));
    manager.addEmployee(std::make_unique<Developer>("李四", 28, 8000, 3000));
    manager.addEmployee(std::make_unique<Developer>("王五", 30, 9000, 4000));

    manager.displayAll();

    std::cout << "\n总工资支出: ¥" << manager.calculateTotalSalary() << std::endl;

    return 0;
}
