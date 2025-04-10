#include "AccountManager.hpp"
#include "BankException.hpp"
#include <iostream>

void AccountManager::addAccount(const BankAccount& account)
{
    
    auto it = bankAccounts.find(account.getAccountID());
    if(it != bankAccounts.end())
    {
        std::cout << "Bank account alreay exists" << std::endl;
        throw AccountAlreadyExistException();
    }

    bankAccounts[account.getAccountID()] = account;
}

void AccountManager::addAccount(const std::string& name, const std::string& id, float balance)
{
    BankAccount account(name, id, balance);
    addAccount(account);
}

const BankAccount* AccountManager::getAccount(const std::string& accountId)
{
    if(accountId.empty())
    {
        throw BankException("Account ID cannot be empty");
    }

    auto it = findAccount(accountId);
    
    if(it == bankAccounts.end())
    {
        return nullptr;
    }
    return &(it->second);
}

std::vector<const BankAccount*> AccountManager::getAllAccounts()
{
    std::vector<const BankAccount*> allAccounts;

    for(const auto& account : bankAccounts)
    {
        allAccounts.push_back(&account.second);
    }

    return allAccounts;
}


void AccountManager::removeAccount(const std::string& accountId)
{
    
    auto it = findAccount(accountId);
    if(it == bankAccounts.end())
        throw BankException("Account not found");
    
    bankAccounts.erase(it);
}


std::unordered_map<std::string, BankAccount>::iterator AccountManager::findAccount(const std::string& accountId)
{
    return bankAccounts.find(accountId);
}

bool AccountManager::accountExists(const std::string& accountId)
{
    auto it = findAccount(accountId);
    return it != bankAccounts.end();
}

void AccountManager:: withdrawFromAccount(const std::string& accountId, float amount)
{
    auto it = findAccount(accountId);
    if(it == bankAccounts.end())
        throw BankException("Account not found");

    it->second.withdraw(amount);
}


void AccountManager::depositIntoAccount(const std::string& accountId, float amount)
{
    auto it = findAccount(accountId);
    if(it == bankAccounts.end())
        throw BankException("Account not found");

    it->second.deposit(amount);
}