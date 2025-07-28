
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

