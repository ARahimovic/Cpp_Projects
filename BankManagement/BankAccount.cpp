#include "BankAccount.hpp"

BankAccount::BankAccount(std::string name, std::string account, float balance):accountName(name), accountId(account),accountBalance(balance){}

std::string getAccountName() const {return this->accountName; }
std::string getAccountID() const {return this->accountId; }
float getBalance() const {return this->accountBalance; }
void withdraw(uint16_t amount)
{
    if(accountBalance < amount)
    {
        std::cout << "NO sufficient funds" << std::endl;
        throw BANK_EXCEPTION
    }
    accountBalance -= amount;
}

void deposit(uint16_t amount)
{
    accountBalance += amount;
}