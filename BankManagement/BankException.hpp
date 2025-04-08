#ifndef BANK_EXCEPTION
#define BANK_EXCEPTION

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


#endif // BANK_EXCEPTION