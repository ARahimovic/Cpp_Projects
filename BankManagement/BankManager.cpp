#include "BankManager.hpp"
#include "commonType.hpp"
#include "BankException.hpp"


void BankManager::createAccount(const std::string& name, const std::string& id, float balance)
{
    if(name.empty() || id.empty())
    {
        throw BankException("name or ID cannot be empty");
    }

    accountManager.addAccount(name, id, balance);
}

void BankManager::deleteAccount(const std::string& accountId)
{
    if(accountId.empty())
    {
        throw BankException("ID cannot be empty");
    }

    accountManager.removeAccount(accountId);

}

void BankManager::withdrawFromAccount(const std::string& accountId, float amount)
{
    if(accountId.empty())
    {
        throw BankException("ID cannot be empty");
    }

    accountManager.withdrawFromAccount(accountId, amount);
    Transaction transaction(amount, TransactionType::WITHDRAW);
    transactionManager.createTransaction(accountId, transaction);
}

void BankManager::depositIntoAccount(const std::string& accountId, float amount)
{
    if(accountId.empty())
    {
        throw BankException("ID cannot be empty");
    }

    accountManager.depositIntoAccount(accountId, amount);
    Transaction transaction(amount, TransactionType::DEPOSIT);
    transactionManager.createTransaction(accountId, transaction);
}


void BankManager::transferFromToAccount(const std::string id1, const std::string id2, float amount)
{
    if(id1.empty() || id2.empty())
    {
        throw BankException("ID cannot be empty");
    }

    //withdraw from account 1
    accountManager.withdrawFromAccount(id1, amount);
    
    Transaction withdrawTransaction(amount, TransactionType::WITHDRAW);

    transactionManager.createTransaction(id1, withdrawTransaction);

    //Deposit into account 2
    accountManager.depositIntoAccount(id2, amount);
    Transaction depositTransaction(amount, TransactionType::DEPOSIT);
    transactionManager.createTransaction(id2, depositTransaction);
    
}


void BankManager::listAllAccounts()
{
    auto accounts = accountManager.getAllAccounts();
    for(const auto& account : accounts)
    {
        account->displayAccount();
    }
}