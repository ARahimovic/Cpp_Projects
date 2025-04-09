#include "BankAccount.hpp"
#include "BankException.hpp"
#include <iostream>

BankAccount::BankAccount(const std::string& name, const std::string& account, float balance):accountName(name), accountId(account),accountBalance(balance){}
BankAccount::BankAccount() : accountName(""), accountId(""), accountBalance(0.0f) {}

const std::string& BankAccount::getAccountName() const {return this->accountName; }
const std::string& BankAccount::getAccountID() const {return this->accountId; }
float BankAccount::getBalance() const {return this->accountBalance; }
void BankAccount::withdraw(uint16_t amount)
{
    if(accountBalance < amount)
    {
        std::cout << "NO sufficient funds" << std::endl;
        throw InsufficientFunds();
    }
    accountBalance -= amount;
}

void BankAccount::deposit(uint16_t amount)
{
    accountBalance += amount;
}


void BankAccount::setName(const std::string& name)
{
    if(name.empty())
    {
        throw BankException("Name cannot be empty");
    }
    accountName = name;
}
