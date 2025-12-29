#include <cmath>
#include <iostream>

class BankAccount {
    double balance;
    std::string name;

    double roundToTwo(double newBalance) {
        return round(newBalance * 100.0) / 100.0;
    }

public:
    BankAccount(double _balance, std::string _name) {
        balance = _balance;
        name = _name;
    }

    void deposit(double amount) {
        if (amount < 0) {
            std::cout << "Error: amount is negative";
            return;
        }

        balance = roundToTwo(balance + amount);
    }

    bool withdraw(double amount) {
        if (amount > balance) {
            std::cout << "Error: not enough funds";
            return false;
        }
        if (amount < 0) {
            std::cout << "Error: amount is negative";
            return false;
        }

        balance = roundToTwo(balance - amount);
        return true;
    }

    void printInfo() const {
        std::cout << "Current balance: " << balance << " " << "Card name: "<< name << std::endl;
    }
};

// lgtm - looks good to me
// btw - by the way
// asap - as soon as possible
int main(){

    BankAccount card(14.236, "Maxim Gurali");

    card.deposit(12);
    card.withdraw(15);
    card.printInfo();


    return 0;
}