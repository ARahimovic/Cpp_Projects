
#include "AccountManager.hpp"
#include "TransactionManager.hpp"

class BankManager
{
    public:
    BankManager() = default;
    void createAccount(const std::string& name, const std::string& id, float balance);
    void deleteAccount(const std::string& accountId);
    void withdrawFromAccount(const std::string& accountId, float amount);
    void depositIntoAccount(const std::string& accountId, float amount);
    void transferFromToAccount(const std::string id1, const std::string id2, float amount);
    void listAllAccounts();

    private:
    AccountManager accountManager;
    TransactionManager transactionManager;
};