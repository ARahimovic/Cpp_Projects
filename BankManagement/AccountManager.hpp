#ifndef ACCOUNT_MANAGER
#define ACCOUNT_MANAGER

#include "BankAccount.hpp"
#include <unordered_map>

class AccountManager
{
    public :
        AccountManager() = default;
        void addAccount(BankAccount bankAccount);
        void addAccount(std::string name, std::string id, float balance);
        void removeAccount(std::string accountId);
        BankAccount* getAccount(std::string accountId) const;
        std::vector<const BankAccount*> getAllAccounts() const;


    private:
        std::unordered_map<std::string, BankAcount> bankAccounts;

};

#endif // ACCOUNT_MANAGER