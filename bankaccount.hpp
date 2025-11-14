#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class bankSystem;

using namespace std;

class bankAccount
{

private:
    string _accountHolderName;
    int _accountNumber;
    int _pin;
    double _balance;     

public:

    bankAccount() 
    : _balance(0.0), _accountHolderName(""), _accountNumber(0), _pin(0) {};
       
    bankAccount(string name, int accountNumber, int pin) 
    : _balance(0.0), _accountHolderName(name), _accountNumber(accountNumber), _pin(pin) {};

    friend class bankSystem;

    //core functionalities
    void deposit();
    void withdraw();
    void viewBalance() const;
    void bankMenu();

    //File I/O
    void SaveToFile(std::ofstream& out) const;
    bool LoadFromFile(std::ifstream& in, const std::string& accountNumber, const std::string& pin);
    void updateAccountInFile(); // Update a single account

    //Getters
    int getAccountNumber() const { return _accountNumber; }
    int getPin() const { return _pin; }
    double getBalance() const { return _balance; }
    const string& getName() const { return _accountHolderName; }

    // Setters  
    void setBalance(double balance) { _balance = balance; }

    friend std::ostream& operator<< (std::ostream& out, const bankAccount& bankAccount);
    
        
};

#endif // BANKACCOUNT_HPP