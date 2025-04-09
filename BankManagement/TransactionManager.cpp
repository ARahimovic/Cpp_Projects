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