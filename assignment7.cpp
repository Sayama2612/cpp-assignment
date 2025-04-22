#include<iostream>
#include<exception>
using namespace std;

// Custom Exception Classes
class InsufficientFundsException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Insufficient funds!";
    }
};

class InvalidTransactionException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Invalid transaction! Please enter a valid amount.";
    }
};

class DivideByZeroException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Cannot divide by zero!";
    }
};

class BankAccount {
private:
    string ownerName; //Stores the account holder's name
    double balance;  // Stores the account balance in INR

public:
    BankAccount(string name, double deposit_amt) {  //Constructor to initialize an account
        if (deposit_amt < 0)
            throw InvalidTransactionException();

        ownerName = name;
        balance = deposit_amt;
        cout << "Creating Account for " << ownerName << " with Initial Deposit: INR " << balance << endl;
    }

    void deposit(double amount) {  //Deposits money into the account
        cout << "Depositing INR " << amount << " into " << ownerName << "'s Account" << endl;
        
        if (amount < 0)
            throw InvalidTransactionException();

        balance += amount;
    }

    void withdraw(double amount) {  //Withdraws money from the account
        cout << "Withdrawing INR " << amount << " from " << ownerName << "'s Account" << endl;
        
        if (amount < 0)
            throw InvalidTransactionException();
        if (amount > balance)
            throw InsufficientFundsException();

        balance -= amount;
    }

    void transfer(BankAccount& to, double amount) {  // Transfers money between accounts.
        if (amount < 0)
            throw InvalidTransactionException();
        if (amount > balance)
            throw InsufficientFundsException();

        balance -= amount;
        to.balance += amount;
        cout << "Transferring INR " << amount << " from " << ownerName << " to " << to.ownerName << endl;
        cout << "New Balance of " << ownerName << ": INR " << balance << endl;
        cout << "New Balance of " << to.ownerName << ": INR " << to.balance << endl;
    }

    void divideBalance(double divisor) {  // Divides balance by a number
        if (divisor == 0){
            cout<<"Dividing Balance by 0"<<endl;
             throw DivideByZeroException();   
        }

        balance /= divisor;
        cout << "Balance of " << ownerName << " after division: INR " << balance << endl;
    }

    void display() {  // Displays account details.
        cout << "Account Holder: " << ownerName << "\nBalance: INR " << balance << endl;
    }
};

int main() {
    try {
        BankAccount acc1("Rahul Sharma", 5000);
        BankAccount acc2("Priya Verma", 5000);

        acc1.deposit(1000);

        try {
            acc1.withdraw(7000); // Will throw InsufficientFundsException
        } catch (const exception& e) {
            cout << e.what() << endl;
        }

        try {
            acc1.transfer(acc2, 3000); 
        } catch (const exception& e) {
            cout << e.what() << endl;
        }

        try {
            acc1.divideBalance(0); // Will throw DivideByZeroException
        } catch (const exception& e) {
            cout << e.what() << endl;
        }

        cout << "\nFinal Account Details:\n";
        acc1.display();
        acc2.display();
    }
    catch (const exception& e) {
        cout << "Exception during account creation or general failure: " << e.what() << endl;
    }

    return 0;
}
