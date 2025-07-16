#include <stdio.h>

// ADT Definition
typedef struct {
    int account_number;
    char holder_name[100];
    double balance;
} BankAccount;

// Operation 1: Initialize Account
void init_account(BankAccount *account, int acc_no, const char *name, double initial_balance) {
    account->account_number = acc_no;
    snprintf(account->holder_name, sizeof(account->holder_name), "%s", name);
    account->balance = initial_balance;
}

// Operation 2: Deposit
void deposit(BankAccount *account, double amount) {
    if (amount > 0) {
        account->balance += amount;
        printf("₹%.2f deposited. New Balance: ₹%.2f\n", amount, account->balance);
    } else {
        printf("Deposit amount must be positive.\n");
    }
}

// Operation 3: Withdraw
void withdraw(BankAccount *account, double amount) {
    if (amount <= 0) {
        printf(" Withdrawal amount must be positive.\n");
    } else if (amount > account->balance) {
        printf("Insufficient balance. Available: ₹%.2f\n", account->balance);
    } else {
        account->balance -= amount;
        printf("₹%.2f withdrawn. New Balance: ₹%.2f\n", amount, account->balance);
    }
}

// Operation 4: Check Balance
double get_balance(const BankAccount *account) {
    return account->balance;
}

// Demo usage
int main() {
    BankAccount my_account;

    // Initialize the account
    init_account(&my_account, 1001, "Agneay Nair", 5000.00);

    printf("Account Holder: %s\n", my_account.holder_name);
    printf("Initial Balance: ₹%.2f\n\n", get_balance(&my_account));

    // Perform operations
    deposit(&my_account, 1500.00);
    withdraw(&my_account, 2000.00);
    withdraw(&my_account, 6000.00); // Should show insufficient funds

    printf("\nFinal Balance: ₹%.2f\n", get_balance(&my_account));

    return 0;
}
