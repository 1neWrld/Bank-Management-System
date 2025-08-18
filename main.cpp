#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <sstream>

#include "BankAccount.h"

using namespace std;

int main() {

    BankAccount account("", "", "");
    char choice;

    cout << "---------------------------" << endl;
    cout << "Welcome to the 1neWrld Bank!" << endl;
    cout << "---------------------------" << endl;

    cout << "(C)reate or (L)oad existing account? ";
    cin >> choice;
    cin.ignore();  // clear newline from buffer
    choice = std::tolower(choice);  // convert to lowercase for easier comparison

    if (choice == 'l') {
        string accountNumber, pin;
        cout << "Enter your account number: ";
        getline(cin, accountNumber);
        cout << "Enter your PIN: ";
        getline(cin, pin);

        ifstream inFile("accounts.txt");
        if (!inFile) {
            cerr << "Could not open accounts file." << endl;
            return 1;
        }

        if (!account.LoadFromFile(inFile, accountNumber, pin)) {
            cout << "Account not found or wrong PIN. Exiting." << endl;
            return 1;
        }

        cout << "Account loaded successfully!" << endl;

        cout << "Welcome back, " << account.getName() << "!" << endl;
    }

    else if(choice == 'c') {
       // Create new account flow (same as your existing code)
        string name, accountNumber, pin;
        cout << "Please enter your Full Name: ";
        getline(cin, name);
        cout << "Enter your desired account number: ";
        getline(cin, accountNumber);
        cout << "Set a 4-digit PIN: ";
        getline(cin, pin);

        account = BankAccount(name, accountNumber, pin);
        cout << account.getName() << "'s" << " Wrld has been created successfully!" << endl;
    }
    else {
               cout << "Invalid Option" << endl;
               return 1;
    }

    int option;
    double amount;

    do {
        cout << "\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit\nSelect: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "------------------------------------------" << endl;
                cout << "Enter amount to deposit: " << endl;
                cin >> amount;
                cout << "------------------------------------------" << endl;
                account.deposit(amount);
                break;

            case 2:
                cout << "------------------------------------------" << endl;
                cout << "Enter amount to withdraw: " << endl;
                cin >> amount;
                cout << "------------------------------------------" << endl;
                account.withdraw(amount);
                break;

            case 3:
                cout << "------------------------------------------" << endl;
                cout << "Current balance: " << account.getBalance() << endl;
                cout << "------------------------------------------" << endl;
                break;

            case 4:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }

    } while (option != 4);

   // 1. Load existing accounts from file
std::vector<BankAccount> accounts;
{
    std::ifstream inFile("accounts.txt");
    std::string line;
    while (std::getline(inFile, line)) 
    {
        std::stringstream ss(line);
        std::string n, accNum, pin;
        double bal;
        std::getline(ss, n, '|');
        std::getline(ss, accNum, '|');
        std::getline(ss, pin, '|');
        ss >> bal;

        accounts.emplace_back(n, accNum, pin);
        accounts.back().deposit(bal); // or set balance directly if you add setter
    }
}

// 2. Update or insert current account
bool found = false;
for (auto &acc : accounts) {
    if (acc.getAccountNumber() == account.getAccountNumber()) {
        acc = account;
        found = true;
        break;
    }
}
if (!found) {
    accounts.push_back(account);
}

// 3. Rewrite file
std::ofstream outFile("accounts.txt", std::ios::trunc); // trunc -> overwrite
for (const auto &acc : accounts) 
{
    acc.SaveToFile(outFile);
}


    cout << "----------------------------------" << endl;
    cout << "Thank you for using 1neWrld Bank!" << endl;
    cout << "----------------------------------" << endl;

    return 0;
}
