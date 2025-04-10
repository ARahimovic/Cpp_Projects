#ifndef TRANSACTION_MANAGER_HPP
#define TRANSACTION_MANAGER_HPP

#include "Transaction.hpp"
#include "BankAccount.hpp"
#include <unordered_map>
#include <vector>


class TransactionManager
{
    public:
        TransactionManager() = default;
        
        void createTransaction(const std::string& accountId, const Transaction& transaction);
        std::vector<Transaction>& getAccountTransactions(const std::string& accountId);
    private :
        std::unordered_map<std::string, std::vector<Transaction>> transactionMap;    
    
};

#endif //TRANSACTION_MANAGER_HPP