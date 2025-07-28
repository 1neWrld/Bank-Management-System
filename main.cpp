#include <iostream>

#include "BankAccount.cpp"


int main()
{

    BankAccount account("John Doe", "123456789", "1234");

    account.deposit(1000.0);
    std::cout << "Balance after deposit: " << account.getBalance() << std::endl;

    if (account.withdraw(500.0)) {
        std::cout << "Withdrawal successful. New balance: " << account.getBalance() << std::endl;
    } else {
        std::cout << "Withdrawal failed." << std::endl;
    }

    if (account.VerifyPin("124")) {
        std::cout << "PIN verified successfully." << std::endl;
    } else {
        std::cout << "PIN verification failed." << std::endl;
    }

    return 0;

}