#include "Transaction.hpp"
#include "BankException.hpp"
#include <iostream>

uint16_t Transaction::staticTransactionId = 1;


Transaction::Transaction(float amount, TransactionType type):amount(amount), transactionType(type)
{
    
    if(amount <= 0 )
    {
        throw BankException("Transaction : amount to deposit or withdraw must be 5 euros or more");
    }
    
    this->amount = amount;
    
    transactionId =  staticTransactionId++;
    timestamp = std::chrono::system_clock::now();
}




uint16_t Transaction::getTransactionId() const { return transactionId; }

std::chrono::system_clock::time_point Transaction::getTransactionTime() const { return timestamp; }

void Transaction::displayTransaction() const
{
    std::cout << "Transaction ID : " << transactionId << "\nType : " << (transactionType == TransactionType::DEPOSIT ? "DEPOSIT" : "WITHDRAWAL") << "\nAmount : " << amount;
    std::time_t timestamp_time_t = std::chrono::system_clock::to_time_t(timestamp);
    std::cout << "Timestamp: " << std::ctime(&timestamp_time_t);  // Automatically adds newline
}


float Transaction::getTransactionAmount() const
{
    return amount;
}

TransactionType Transaction::getType()const
{
    return transactionType;
}