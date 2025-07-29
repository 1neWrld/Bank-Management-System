#include <iostream>

#include "BankAccount.h"


int main()
{

    using namespace std;

    std::string name;
    std::string accountNumber;
    std::string pin;

    cout << "---------------------------" << endl;
    cout << "Welcome to the 1neWrld Bank!" << endl;
    cout << "---------------------------" << endl;

    cout << "Please enter your Full Name." << endl;
    std::getline(cin, name);
    std::cout << "Enter your desired account number: ";
    std::cin >> accountNumber;
    std::cout << "Set a 4-digit PIN: ";
    std::cin >> pin;

    BankAccount account(name, accountNumber, pin);

    cout << "Your Wrld has been created successfully!" << endl;

    int option;
    double amount;
    
    do {
        std::cout << "\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit\nSelect: ";
        std::cin >> option;
        
        switch (option)
        {
        case 1:
            std::cout << "Enter amount to deposit: ";
            std::cin >> amount;
            account.deposit(amount);
            
            break;

        case 2:
            std::cout << "Enter amount to withdraw: ";
            std::cin >> amount;
            account.withdraw(amount);

            break;

        case 3:
            std::cout << "Current balance: " << account.getBalance() << std::endl;
            
            break;

        case 4:
            std::cout << "Exiting the program." << std::endl;
            
            break;

        default:
             std::cout << "Invalid option. Please try again." << std::endl;
            
             break;
        }


    } while (option != 4);

        cout << "----------------------------------" << endl;
    std::cout << "Thank you for using 1neWrld Bank!" << std::endl;
        cout << "----------------------------------" << endl;
        
    return 0;


    return 0;

}