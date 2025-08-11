
#include <iostream>

#include "BankAccount.h"

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    } else {
        std::cout<< "Insufficient Funds." << std::endl;
    }
}

bool BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        return true;
    } else {
        std::cout << "Insufficient Funds." << std::endl;
        return false;
    }
}

double BankAccount::getBalance() const {
    return balance;
}

std::string BankAccount::getAccountNumber() const {
    return accountNumber;
}

std::string BankAccount::getName() const {
    return name;
}

bool BankAccount::VerifyPin(const std::string& inputPin) const {
    return pin == inputPin;
}

void BankAccount::SaveToFile(std::ofstream& out) const {

    out << name << "|" << accountNumber << "|" << pin << "|" << balance << std::endl;

}

bool BankAccount::LoadFromFile(std::ifstream& in, const std::string& accountNumber, const std::string& pin) {
   std::string line;
    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string n, acc, p;
        double bal;

        std::getline(ss, n, '|');
        std::getline(ss, acc, '|');
        std::getline(ss, p, '|');
        ss >> bal;

        if (acc == accountNumber && p == pin) {
            name = n;
            this->accountNumber = acc;
            this->pin = p;
            balance = bal;
            return true;
        }
    }
    return false;
}