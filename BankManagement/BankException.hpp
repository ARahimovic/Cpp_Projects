#ifndef BANK_EXCEPTION
#define BANK_EXCEPTION
#include <stdexcept>

class BankException : public std::runtime_error
{
    public:
        BankException(const std::string& msg) : std::runtime_error(msg){}

};

class AccountNotFoundException : public BankException
{
    public:
        AccountNotFoundException() : BankException("Account not Found"){}
};

class AccountAlreadyExistException : public BankException
{
    public:
    AccountAlreadyExistException() : BankException("Account Already Exists : cant create Again"){}
};

class InsufficientFunds : public BankException
{
    public :
    
    InsufficientFunds():BankException("InsufficientFunds : cannot withdraw"){}
};


#endif // BANK_EXCEPTION