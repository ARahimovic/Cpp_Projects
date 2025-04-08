#include "AccountManager.hpp"
#include <iostream>

void AccountManager::addAccount(BankAccount account)
{
    if(account == nullptr)
    {
        std::cout << " error, bank account null" << std::endl;
        throw BankException("Account is null");
    }

    auto it = bankAccounts.find(account.getAccountID())
    if(it != bankAccounts.end())
    {
        std::cout << "Bank account alreay exists" << std::endl;
        throw AccountAlreadyExistException();
    }

    bankAccounts[account.getAccountID()] = account;
}

void AccountManager::addAccount(std::string name, std::string id, float balance);
{
    BankAccount account(name, id, balance);
    bankAccounts[id] = account;
}

BankAccount* AccountManager::getAccount(std::string accountId) const
{
    if(accountId.empty())
    {
        std::cout << " account Id cannot be empty" << std::endl;
    }

    auto it = bookAccounts.find(accountId);

    return it == bookAccount.end() ? nullptr : &(it->second);
}

std::vector<const BankAccount*> AccountManager::getAllAccounts() const
{
    std::vector<const BankAccount*> allAccounts;

    for(const auto& account : bankAccounts)
    {
        allAccounts.push_back(&account.second);
    }

    return allAccounts;
}


void AccountManager::removeAccount(std::string accountId)
{
    auto it = bankAccounts.find(accountId);
    if(it == bankAccounts.end())
        throw AccountNotFoundException();

    bankAccounts.erase(it);
}
