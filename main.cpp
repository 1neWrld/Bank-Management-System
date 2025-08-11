#include <iostream>
#include <fstream>
#include "BankAccount.h"

int main() {
    using namespace std;

    BankAccount account("", "", "");
    char choice;

    cout << "---------------------------" << endl;
    cout << "Welcome to the 1neWrld Bank!" << endl;
    cout << "---------------------------" << endl;

    cout << "Do you want to (L)oad an existing account or (C)reate new? ";
    cin >> choice;
    cin.ignore();  // clear newline from buffer

    if (choice == 'L' || choice == 'l') {
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
    }
    else {
        // Create new account flow (same as your existing code)
        string name, accountNumber, pin;
        cout << "Please enter your Full Name: ";
        getline(cin, name);
        cout << "Enter your desired account number: ";
        getline(cin, accountNumber);
        cout << "Set a 4-digit PIN: ";
        getline(cin, pin);

        account = BankAccount(name, accountNumber, pin);
        cout << "Your Wrld has been created successfully!" << endl;
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

    // Save account data before exit
    ofstream outFile("accounts.txt", ios::app);  // append mode
    if (!outFile) {
        cerr << "Failed to open accounts file for saving." << endl;
    } else {
        account.SaveToFile(outFile);
    }

    cout << "----------------------------------" << endl;
    cout << "Thank you for using 1neWrld Bank!" << endl;
    cout << "----------------------------------" << endl;

    return 0;
}
