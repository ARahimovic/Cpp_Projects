🔁 Key Relationships:
BankSystem

Acts as a facade.

Coordinates actions between AccountManager and TransactionManager.

AccountManager

Owns and manages multiple BankAccount instances.

Allows fast access via ID or name (via two maps or a bidirectional lookup).

TransactionManager

Communicates with AccountManager to apply changes (e.g., withdraw).

Creates Transaction records and may store them in memory or database.

BankAccount

Basic entity that holds balance and info.

Contains methods for deposit, withdraw, setName, etc.

Transaction

Keeps track of each operation.

May be stored per-account or globally in a log.



                    +---------------------+
                    |     BankSystem      |  <-- High-level controller
                    +---------------------+
                       |            |
         uses ---------+            +-------- uses
                       ↓                          ↓
        +----------------------+      +--------------------------+
        |   AccountManager     |<---->|   TransactionManager     |
        +----------------------+      +--------------------------+
        | - accountsById       |      | - transactionLog         |
        | - accountsByName     |      +--------------------------+
        |                      |      |                          |
        | +addAccount()        |      | +processDeposit()        |
        | +getAccountById()    |      | +processWithdrawal()     |
        | +removeAccount()     |      | +getTransactionHistory() |
        +----------------------+      +--------------------------+
                  |                                 |
                  |                                 |
            owns  |                                 | creates
                  ↓                                 ↓
        +-------------------+         +--------------------------+
        |    BankAccount    |         |       Transaction        |
        +-------------------+         +--------------------------+
        | - id              |         | - transactionId          |
        | - name            |         | - amount                 |
        | - balance         |         | - type (deposit/withdraw)|
        |                   |         | - timestamp              |
        | +deposit()        |         +--------------------------+
        | +withdraw()       |
        | +getBalance()     |
        +-------------------+

