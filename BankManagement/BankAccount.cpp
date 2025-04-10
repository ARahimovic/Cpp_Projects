#include "BankAccount.hpp"
#include "BankException.hpp"
#include <iostream>

BankAccount::BankAccount(const std::string& name, const std::string& account, float balance):accountName(name), accountId(account),accountBalance(balance)
{
    if(name.empty() || account.empty())
    {
        throw BankException("name and ID must not be empty");
    }
    if(name.length() < 3)
    {
        throw BankException("Name must be at least three characters long");
    }
    
    if (balance < 0) {
        throw BankException("Balance cannot be negative.");
    }
}
BankAccount::BankAccount() : accountName(""), accountId(""), accountBalance(0.0f) {}

const std::string& BankAccount::getAccountName() const {return this->accountName; }
const std::string& BankAccount::getAccountID() const {return this->accountId; }
float BankAccount::getBalance() const {return this->accountBalance; }
void BankAccount::withdraw(float amount)
{
    if(amount <= 0)
    {
        throw BankException("Withdrawal amount must be positive");
    }
    if(accountBalance < amount)
    {
        std::cout << "NO sufficient funds" << std::endl;
        throw InsufficientFunds();
    }
    accountBalance -= amount;
}

void BankAccount::deposit(float amount)
{
    if(amount <= 0)
    {
        throw BankException("Deposit amount must be positive");
    }
    accountBalance += amount;
}


void BankAccount::setName(const std::string& name)
{
    if(name.empty())
    {
        throw BankException("Name cannot be empty");
    }

    if (name.length() < 3)  
    {
        throw BankException("Name must be at least 3 characters long");
    }

    accountName = name;
}

void BankAccount::displayAccount() const
{
    std::cout << "Account Name: " << accountName << std::endl;
    std::cout << "Account ID: " << accountId << std::endl;
    std::cout << "Balance: $" << accountBalance << std::endl;
}