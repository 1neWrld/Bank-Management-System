#include <iostream>
#include <fstream>
#include <string>
#include <limits>

#include "bankaccount.hpp"
#include "banksystem.hpp"

using namespace std;

void bankAccount::deposit()
{
    double amount;
    
    do
    {
        cout<< "==============================" << endl;
        cout << "Enter deposit amount: R";
        //cout<< "==============================" << endl;

        cin >> amount;
        if (amount <= 0)
        {
            cout << "Deposit amount must be positive." << endl;
        }
    }
    while (amount <= 0);

    _balance += amount;

    cout << "Deposited: R" << amount << endl;
    cout << "Balance: R" << _balance << endl;

    updateAccountInFile();
}

void bankAccount::withdraw()
{
    double amount;

    do
    {
        
        cout<< "==============================" << endl;
        cout << "Enter withdrawal amount: R";
        
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Withdrawal amount must be positive." << endl;
        }
        else if (amount > _balance)
        {
            cout << "Insufficient funds for this withdrawal. " << endl;
            cout << "Current Balance: R" << _balance << endl;
        }
    } 
    while(amount <= 0 || amount > _balance);

    _balance -= amount;
    cout << "Withdrew: R" << amount << endl;
    cout << "Balance: R" << _balance << endl;

    updateAccountInFile();
}

void bankAccount::viewBalance() const
{
    cout << "Current Balance: R" << _balance << endl;
}

void bankAccount::bankMenu()
{
    /*
    bankSystem system;

    if(!system.verifyAccount(*this))
    {
        cout<< "==============================" << endl;
        cout<< "Account not found. Creating new account." << endl;
        cout<< "==============================" << endl;
        
        system.createAccount();
        system.verifyAccount(*this);
    }
    */

    int choice;
    do
    {

        cout<< "==============================" << endl;
        cout<< "        Bank Menu            " << endl;
        cout<< "==============================" << endl;
        cout<< "1. View Balance              " << endl;
        cout<< "2. Deposit                   " << endl;
        cout<< "3. Withdraw                  " << endl;
        cout<< "4. Exit                      " << endl;
        cout<< "==============================" << endl;
        cout << "Enter your choice (1-4): ";
        
        cin >> choice;
        
        switch (choice)
        {
            case 1:
                viewBalance();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                cout << "Exiting the bank menu." << endl;
                break;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    } 
    while (choice != 4);
    
}

void bankAccount::SaveToFile(std::ofstream& out) const
{
    out << _accountHolderName << "|" << _accountNumber << "|" << _pin << "|" << _balance << endl;
}

bool bankAccount::LoadFromFile(std::ifstream& in, const std::string& accountNumber, const std::string& pin)
{
    
    std::string line;
    while (std::getline(in, line))
    {
        std::istringstream iss(line);
        std::string name, accNumStr, pinStr, balanceStr;
        if (std::getline(iss, name, '|') &&
            std::getline(iss, accNumStr, '|') &&
            std::getline(iss, pinStr, '|') &&
            std::getline(iss, balanceStr))
        {
            if (accNumStr == accountNumber && pinStr == pin)
            {
                _accountHolderName = name;
                _accountNumber = std::stoi(accNumStr);
                _pin = std::stoi(pinStr);
                _balance = std::stod(balanceStr);
                return true;
            }
        }
    }

    return false;
}

void bankAccount::updateAccountInFile()
{

    //read all lines from file and update the matching account
    std::ifstream inFile("bankdata.txt");
    std::vector<string> lines;
    string line;

    if(!inFile)
    {
        cout << "Error opening file for reading." << endl;
        return;
    }

    //while there are lines in the file
    while(std::getline(inFile, line))
    {
        std::istringstream iss(line);
        std::string name, accNumStr, pinStr, balanceStr;
        /*
            iss - input string stream to parse each line... iss will contain the characters of the current line
            name, accNumStr, pinStr, balanceStr - variables to hold parsed data
        */
        if(getline(iss, name, '|') &&
           getline(iss, accNumStr, '|') &&
           getline(iss, pinStr, '|') &&
           getline(iss, balanceStr))
        {
            //update matching account if accnumber and pin match 
            if(std::stoi(accNumStr) == _accountNumber && std::stoi(pinStr) == _pin)
            {
                std::ostringstream updated;
                updated << _accountHolderName << "|" << _accountNumber << "|" 
                << _pin << "|" << _balance;
                // add updated line to lines vector
                lines.push_back(updated.str());
            }
            else
            {
                // add original line to lines vector
                lines.push_back(line);
            }
        }
    }
    inFile.close();

    std::ofstream outFile("bankdata.txt", std::ios::trunc);
    for(const auto& l : lines)
    {
        outFile << l << endl;
    }
}

std::ostream& operator<<(std::ostream& out, const bankAccount& bankAccount)
{
    out << "Account Holder Name: " << bankAccount._accountHolderName << endl;
    out << "Account Number: " << bankAccount._accountNumber << endl;
    out << "Balance: R" << bankAccount._balance << endl;
    return out;
}
