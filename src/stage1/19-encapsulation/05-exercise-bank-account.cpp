#include <iostream>
#include <string>

class BankAccount {
private:
    double balance;
    int transactionCount;

public:
    BankAccount(double initialBalance) {
        balance = initialBalance;
        transactionCount = 0;
    }

    double getBalance() const {
        return balance;
    }

    int getTransactionCount() const {
        return transactionCount;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transactionCount++;
            std::cout << "存款 " << amount << " 元，余额: " << balance << std::endl;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            transactionCount++;
            std::cout << "取款 " << amount << " 元，余额: " << balance << std::endl;
            return true;
        } else {
            std::cout << "余额不足或金额无效" << std::endl;
            return false;
        }
    }
};

int main() {
    BankAccount account(1000.0);

    std::cout << "初始余额: " << account.getBalance() << std::endl;

    account.deposit(500.0);
    account.withdraw(200.0);
    account.withdraw(2000.0);  // 余额不足

    std::cout << "最终余额: " << account.getBalance() << std::endl;
    std::cout << "交易次数: " << account.getTransactionCount() << std::endl;

    return 0;
}
