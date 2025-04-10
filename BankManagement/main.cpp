#include <iostream>
#include <cassert>
#include "BankAccount.hpp"
#include "AccountManager.hpp"
#include "TransactionManager.hpp"
#include "BankException.hpp"

void testCreateAccount() {
    AccountManager accountManager;

    // Create account
    BankAccount account("John Doe", "12345", 1000.0f);
    accountManager.addAccount(account);

    // Retrieve the account
    const BankAccount* retrievedAccount = accountManager.getAccount("12345");

    // Assert the account exists
    assert(retrievedAccount != nullptr);
    assert(retrievedAccount->getAccountID() == "12345");
    assert(retrievedAccount->getBalance() == 1000.0f);

    std::cout << "testCreateAccount passed!" << std::endl;
}

void testDeposit() {
    AccountManager accountManager;

    // Create account and deposit money
    BankAccount account("John Doe", "12345", 1000.0f);
    accountManager.addAccount(account);
    accountManager.depositIntoAccount("12345", 500.0f);

    // Retrieve the account
    const BankAccount* retrievedAccount = accountManager.getAccount("12345");

    // Assert the new balance
    assert(retrievedAccount != nullptr);
    assert(retrievedAccount->getBalance() == 1500.0f);

    std::cout << "testDeposit passed!" << std::endl;
}

void testWithdraw() {
    AccountManager accountManager;

    // Create account and withdraw money
    BankAccount account("John Doe", "12345", 1000.0f);
    accountManager.addAccount(account);
    accountManager.withdrawFromAccount("12345", 300.0f);

    // Retrieve the account
    const BankAccount* retrievedAccount = accountManager.getAccount("12345");

    // Assert the new balance
    assert(retrievedAccount != nullptr);
    assert(retrievedAccount->getBalance() == 700.0f);

    std::cout << "testWithdraw passed!" << std::endl;
}

void testTransaction() {
    AccountManager accountManager;
    TransactionManager transactionManager;

    // Create account
    BankAccount account("John Doe", "12345", 1000.0f);
    accountManager.addAccount(account);

    // Deposit and create transaction
    accountManager.depositIntoAccount("12345", 500.0f);
    Transaction depositTransaction(500.0f, TransactionType::DEPOSIT);
    transactionManager.createTransaction("12345", depositTransaction);

    // Verify the transaction was created
    std::vector<Transaction> transactions = transactionManager.getAccountTransactions("12345");
    assert(transactions.size() == 1);
    assert(transactions[0].getTransactionAmount() == 500.0f);
    assert(transactions[0].getType() == TransactionType::DEPOSIT);

    std::cout << "testTransaction passed!" << std::endl;
}

void testDeleteAccount() {
    AccountManager accountManager;

    // Create account
    BankAccount account("John Doe", "12345", 1000.0f);
    accountManager.addAccount(account);

    // Delete the account
    accountManager.removeAccount("12345");

    // Verify the account no longer exists
    const BankAccount* retrievedAccount = accountManager.getAccount("12345");
    assert(retrievedAccount == nullptr);

    std::cout << "testDeleteAccount passed!" << std::endl;
}

int main() {
    try {
        testCreateAccount();
        testDeposit();
        testWithdraw();
        testTransaction();
        testDeleteAccount();
    } catch (const std::exception& e) {
        std::cout << "Test failed: " << e.what() << std::endl;
    }
    return 0;
}
