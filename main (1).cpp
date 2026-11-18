#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string customerName;
    double balance;

public:

    BankAccount()
    {
        accountNumber = 0;
        customerName = "";
        balance = 0;
    }

    void createAccount()
    {
        cout << "\nEnter Account Number: ";
        cin >> accountNumber;

        cin.ignore();

        cout << "Enter Customer Name: ";
        getline(cin, customerName);

        cout << "Enter Initial Deposit: ";
        cin >> balance;

        if (balance < 0)
        {
            cout << "Invalid initial deposit!\n";
            balance = 0;
            accountNumber = 0;
            customerName = "";
            return;
        }

        saveToFile();

        cout << "\nAccount Created Successfully!\n";
    }

    void deposit()
    {
        double amount;

        cout << "\nEnter Deposit Amount: ";
        cin >> amount;

        if (amount > 0)
        {
            balance += amount;
            saveToFile();
            cout << "Deposit Successful!\n";
            cout << "Current Balance: Rs." << balance << endl;
        }
        else
        {
            cout << "Invalid Amount!\n";
        }
    }

    void withdraw()
    {
        double amount;

        cout << "\nEnter Withdrawal Amount: ";
        cin >> amount;

        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            saveToFile();

            cout << "Withdrawal Successful!\n";
            cout << "Remaining Balance: Rs." << balance << endl;
        }
        else
        {
            cout << "Invalid Amount or Insufficient Balance!\n";
        }
    }

    void checkBalance()
    {
        cout << "\nAvailable Balance: Rs." << balance << endl;
    }

    void displayDetails()
    {
        cout << "\n===== CUSTOMER DETAILS =====\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Customer Name: " << customerName << endl;
        cout << "Balance: Rs." << balance << endl;
    }

    void saveToFile()
    {
        ofstream file("bank.txt");

        if (file.is_open())
        {
            file << accountNumber << endl;
            file << customerName << endl;
            file << balance << endl;

            file.close();
        }
        else
        {
            cout << "Unable to save customer records!\n";
        }
    }

    void loadFromFile()
    {
        ifstream file("bank.txt");

        if (file.is_open())
        {
            file >> accountNumber;
            file.ignore();
            getline(file, customerName);
            file >> balance;

            file.close();
        }
    }
};

int main()
{
    BankAccount customer;
    customer.loadFromFile();

    int choice;

    do
    {
        cout << "\n================================\n";
        cout << "     BANK MANAGEMENT SYSTEM     \n";
        cout << "================================\n";

        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Customer Details\n";
        cout << "6. Exit\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                customer.createAccount();
                break;

            case 2:
                customer.deposit();
                break;

            case 3:
                customer.withdraw();
                break;

            case 4:
                customer.checkBalance();
                break;

            case 5:
                customer.displayDetails();
                break;

            case 6:
                cout << "\nThank You for Using Our Bank!\n";
                break;

            default:
                cout << "\nInvalid Choice! Try Again.\n";
        }

    } while (choice != 6);

    return 0;
}