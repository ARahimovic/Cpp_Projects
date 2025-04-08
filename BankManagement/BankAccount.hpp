#ifndef BANK_ACOUNT
#define BANK_ACCOUNT

#include <string>

class BankAccount
{
    public:
        BankAccount(std::string name, std::string account, float balance);
        std::string getAccountName() const;
        std::string getAccountID() const;
        float getBalance() const;
        void deposit(uint16_t amount);
        void withdraw(uint16_t amount);

    private:
        std::string accountName;
        std::string accountId;
        float accountBalance;
};

#endif // BANK_ACCOUNT