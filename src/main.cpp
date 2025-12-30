#include <iostream>
#include <vector>
using namespace std;
class Account {
public:
    int AccountNumber;
    string Name;
private:
    int Balance = 0;
public:
    Account(int AccountNumber, string Name, int Balance) {
        this->AccountNumber = AccountNumber;
        this->Balance = Balance;
        this->Name = Name;
    }
    void withdraw(int amount) {
        if (amount > Balance) {
            cout<<"Insufficient balance! Current Balance: " <<Balance<<endl;
            return;
        }
        Balance=Balance-amount;
        cout<<"Withdrawal successful: "<<amount<<endl;
    }
    void deposit(int amount) {
        if (amount <= 0) {
            cout<<"Transaction failed: deposit amount must be greater than zero."<<endl;
            return;
        }
        Balance=Balance+amount;
        cout<<"Deposit successful: "<<amount<<endl;
    }

    void checkBalance() {
        cout<<"Current Balance: "<<Balance<<endl;
    }
};

int findAccountIndex(vector<Account> &accounts, int accountNumber) {
    for (int i=0;i<accounts.size(); i++) {
        if (accounts[i].AccountNumber==accountNumber) {
            return i;
        }
    }
    return -1;
}
int main() {
    vector<Account> accounts;
    accounts.push_back(Account(101, "Biraj Achrejee", 10000));
    accounts.push_back(Account(102, "Subhajit Das", 20000));
    accounts.push_back(Account(103, "Kushal Ghose", 30000));
    int choice;
    while (true) {
        cout<<"\nWelcome to Simple Banking System"<<endl;
        cout<<"1. Create New Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

       if (choice==1) {
        int accNo, initialBalance;
        string name;
        cout<<"Enter Account Number: ";
        cin>>accNo;
        cout<<"Enter Name (no spaces): ";
        cin>>name;
        cout<<"Enter Initial Balance: ";
        cin>>initialBalance;
        accounts.push_back(Account(accNo, name, initialBalance));
        cout<<"Account created successfully!"<<endl;
       }
        else if(choice>=2&&choice<=4) {
            int accNo;
            cout<<"Enter Your Account Number: ";
            cin>>accNo;
            int index=findAccountIndex(accounts, accNo);
            if (index==-1) {
                cout<<"Invalid Account Number!"<<endl;
                continue;
            }

            int amount;
            switch (choice) {
                case 2:
                    cout<<"Enter amount to deposit: ";
                    cin>>amount;
                    accounts[index].deposit(amount);
                    break;
                case 3:
                    cout<<"Enter amount to withdraw: ";
                    cin>>amount;
                    accounts[index].withdraw(amount);
                    break;
                case 4:
                    accounts[index].checkBalance();
                    break;
            }
        } 
        else if (choice==5) {
            cout<<"Exiting. Thank you for using Simple Banking System!"<<endl;
            break;
        } 
        else {
            cout<<"Invalid choice! Please try again."<<endl;
        }
    }
    return 0;
}
