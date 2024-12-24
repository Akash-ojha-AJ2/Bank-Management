#include <iostream>
#include <vector>
#include <string>
using namespace std;


class BankAccount {
private:
    string accountHolderName;
    int accountNumber;
    double balance;

public:
    
    BankAccount(string name, int accNumber, double initialBalance)
        : accountHolderName(name), accountNumber(accNumber), balance(initialBalance) {}

   
    int getAccountNumber() const {
        return accountNumber;
    }

    
    void displayAccountDetails() const {
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
    }


    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }


    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: $" << balance << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }
};


int main() {
    vector<BankAccount> accounts;
    int choice;

    while (true) {
        cout << "\n--- Bank Management System ---" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. View Account Details" << endl;
        cout << "3. Deposit Money" << endl;
        cout << "4. Withdraw Money" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            int accNumber;
            double initialBalance;
            cout << "Enter account holder name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter account number: ";
            cin >> accNumber;
            cout << "Enter initial balance: ";
            cin >> initialBalance;

            BankAccount newAccount(name, accNumber, initialBalance);
            accounts.push_back(newAccount);
            cout << "Account created successfully!" << endl;
        } else if (choice == 2) {
            int accNumber;
            cout << "Enter account number: ";
            cin >> accNumber;

            bool found = false;
            for (const auto& account : accounts) {
                if (account.getAccountNumber() == accNumber) {
                    account.displayAccountDetails();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Account not found!" << endl;
            }
        } else if (choice == 3) {
            int accNumber;
            double amount;
            cout << "Enter account number: ";
            cin >> accNumber;
            cout << "Enter amount to deposit: ";
            cin >> amount;

            bool found = false;
            for (auto& account : accounts) {
                if (account.getAccountNumber() == accNumber) {
                    account.deposit(amount);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Account not found!" << endl;
            }
        } else if (choice == 4) {
            int accNumber;
            double amount;
            cout << "Enter account number: ";
            cin >> accNumber;
            cout << "Enter amount to withdraw: ";
            cin >> amount;

            bool found = false;
            for (auto& account : accounts) {
                if (account.getAccountNumber() == accNumber) {
                    account.withdraw(amount);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Account not found!" << endl;
            }
        } else if (choice == 5) {
            cout << "Thank you for using the Bank Management System. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
