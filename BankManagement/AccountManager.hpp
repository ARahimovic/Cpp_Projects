#ifndef ACCOUNT_MANAGER
#define ACCOUNT_MANAGER

#include "BankAccount.hpp"
#include <unordered_map>
#include <vector>

class AccountManager
{
    public :
        AccountManager() = default;
        void addAccount(const BankAccount& bankAccount);
        void addAccount(const std::string& name, const std::string& id, float balance);
        void removeAccount(const std::string& accountId);
        const BankAccount* getAccount(const std::string& accountId) const;
        std::vector<const BankAccount*> getAllAccounts() const;
        bool accountExists(const std::string& accountId);
        std::unordered_map<std::string, BankAccount>::const_iterator findAccount(const std::string& accountId) const;


    private:
        std::unordered_map<std::string, BankAccount> bankAccounts;

};

#endif // ACCOUNT_MANAGER