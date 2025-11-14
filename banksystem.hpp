#ifndef BANKSYSTEM_HPP
#define BANKSYSTEM_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include <memory>

#include "bankaccount.hpp"

using namespace std;

class bankSystem
{
private:
    
    std::vector<bankAccount> _accounts;

public:

    bankSystem() = default;

    friend class bankAccount;

    // === File Operations ===
    void loadAccountsFromFile();                // Load all accounts into _accounts
    void saveAccountsToFile() const;            // Save all accounts back to file

    //Account Management
    void run();               // Main system loop
    bool verifyAccount(bankAccount& account);   //check if account exists
    void createAccount();   //admin creates new account
    
    // Admin utility
    void showAllAccounts() const;
    
private:

    std::unique_ptr<bankAccount> findAccount(int accountNumber, int pin);
};

#endif // BANKSYSTEM_CLASS_HPP