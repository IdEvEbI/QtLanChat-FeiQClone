#include <iostream>
#include <string>

class Account {
protected:
    std::string accountNumber;

private:
    double balance;

public:
    Account(const std::string& accNum, double bal) : accountNumber(accNum), balance(bal) {}

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "存款 " << amount << " 元，余额: " << balance << std::endl;
        }
    }

    void printInfo() {
        std::cout << "账号: " << accountNumber << std::endl;
        std::cout << "余额: " << balance << std::endl;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(const std::string& accNum, double bal, double rate)
        : Account(accNum, bal), interestRate(rate) {}

    void calculateInterest() {
        double interest = getBalance() * interestRate / 100.0;
        std::cout << "利息: " << interest << " 元" << std::endl;
    }

    void printSavingsInfo() {
        printInfo();
        std::cout << "利率: " << interestRate << "%" << std::endl;
    }
};

int main() {
    SavingsAccount account("ACC001", 1000.0, 3.5);
    account.deposit(500.0);
    account.calculateInterest();
    account.printSavingsInfo();

    return 0;
}
