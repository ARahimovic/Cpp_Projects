#include "Transaction.hpp"
#include "BankAccount.hpp"
#include <unordered_map>
#include <vector>


class TransactionManager
{
    public:
        TransactionManager() = default;
        
        void createTransaction(const std::string& accountId, const Transaction&transaction);
        
    
    private :
        std::unordered_map<std::string, std::vector<Transaction>> transactionMap;    
    
};