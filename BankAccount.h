
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

using namespace std;

class BankAccount
{
    
    private:
        std::string accountNumber;
        std::string name;
        std::string pin;
        double balance;

    public:
        BankAccount(string name, string accountNumber, std::string pin)
            : name(name), accountNumber(accountNumber), pin(pin), balance(0.0) {}


        void deposit(double amount);
        bool withdraw(double amount);
        double getBalance() const;

        string getAccountNumber() const;
        string getName() const; 
        
        bool VerifyPin(const std::string& inputPin) const;
};


#endif