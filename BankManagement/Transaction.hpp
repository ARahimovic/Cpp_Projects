#include <chrono>
#include "commonType.hpp"


class Transaction
{
    public :
        Transaction(float amount, TransactionType type);
        uint16_t getTransactionId() const;
        std::chrono::system_clock::time_point getTransactionTime() const;
        void displayTransaction() const;
        float getTransactionAmount() const;
        TransactionType getType() const;

    private:
        uint16_t transactionId;
        float amount;
        TransactionType transactionType;
        std::chrono::system_clock::time_point timestamp;
        static uint16_t staticTransactionId; 
};