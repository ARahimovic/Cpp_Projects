#include "TransactionManager.hpp"
#include "BankException.hpp"


void TransactionManager::createTransaction(const std::string& accountId, const Transaction&transaction)
{
    if(accountId.empty())
    {
        throw BankException("Account ID cannot be empty");
    }
    
    transactionMap[accountId].push_back(transaction);
}

std::vector<Transaction>&TransactionManager::getAccountTransactions(const std::string& accountId)
{
    if(accountId.empty())
    {
        throw BankException("Account ID cannot be empty");
    }
    auto it = transactionMap.find(accountId);
    if (it == transactionMap.end())
    {
        throw BankException("No transactions found for this account");
    }
    return it->second;
}