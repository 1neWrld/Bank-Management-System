#include <iostream>
#include <fstream>
#include <string>
#include <limits>

#include "banksystem.hpp"
#include "bankaccount.hpp"

using namespace std;

void bankSystem::run()
{
    bankAccount account;

    if(!verifyAccount(account))
    {
        cout<< "==============================" << endl;
        cout<< "Account not found. Creating new account." << endl;
        cout<< "==============================" << endl;
        
        createAccount();
        verifyAccount(account);
    }
    
    account.bankMenu();
}

// check if user has an account in the bank file i/o
bool bankSystem::verifyAccount(bankAccount& account)
{
    cout << "Enter Account Number: ";
    string accountNumber;
    cin >> accountNumber;
    cout << endl;

    cout << "Enter PIN: ";
    string pin;
    cin >> pin;
    cout << endl;
    
    auto found = findAccount(std::stoi(accountNumber), std::stoi(pin));

    if(found)
    {
        //store object data into the current account
        account = *found;
        cout<< "==============================" << endl;
        cout<< "Welcome, " << account.getName() << "!" << endl;
        return true;
    }
    
    cout << "Account verification failed. Please check your account number and PIN." << endl;
    return false;
}

void bankSystem::createAccount()
{
    string name;
    int accountNumber;
    int pin;

    //Get data
    cout << "Enter Account Holder Name: ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, name);

    cout << "Enter Account Number: ";
    cin >> accountNumber;
    cout << "Enter PIN: ";
    cin >> pin;

    //create new account object
    bankAccount newAccount(name, accountNumber, pin);

    //Save to file
    std::ofstream outFile("bankdata.txt", std::ios::app);
    if(!outFile)
    {
        cout << "Error opening file for writing." << endl;
        return;
    }

    newAccount.SaveToFile(outFile);
    outFile.close();

    cout << "Account created successfully!" << endl;
}

std::unique_ptr<bankAccount> bankSystem::findAccount(int accountNumber, int pin)
{
    std::ifstream inFile("bankdata.txt");
    if(!inFile)
    {
        cout << "Error opening file." << endl;
        return nullptr;
    }

    auto account = std::make_unique<bankAccount>();
    if(account->LoadFromFile(inFile, std::to_string(accountNumber), std::to_string(pin)))
    {
        return account;
    }
    return nullptr;
}


