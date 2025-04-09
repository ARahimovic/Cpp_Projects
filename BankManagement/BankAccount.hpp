#ifndef BANK_ACOUNT
#define BANK_ACCOUNT

#include <string>
#include <cstdint>

class BankAccount
{
    public:
        BankAccount();
        BankAccount(const std::string& name, const std::string& account, float balance);
        const std::string& getAccountName() const;
        const std::string& getAccountID() const;
        float getBalance() const;
        void deposit(uint16_t amount);
        void withdraw(uint16_t amount);
        void setName(const std::string& name);

    private:
        std::string accountName;
        std::string accountId;
        float accountBalance;
};

#endif // BANK_ACCOUNT