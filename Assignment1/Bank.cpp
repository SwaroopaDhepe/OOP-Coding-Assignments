/*Operations on Bank Account
Data members:
i. Name of the customer
ii. Account Type
iii. Account Number
iv. Available balance amount in the account
Member Functions:
i. Assign initial values using constructors.
ii. Deposit an amount in account
iii. Withdraw an amount
iv. Display account details*/


#include<iostream>
using namespace std;
class bank_acc{
private:
    string name, acctype;
    int acc_no;
    float balance;
public:
    // Constructor
    bank_acc(string n, string type, int acc, float bal){
        name = n;
        acctype = type;
        acc_no = acc;
        balance = bal;
    }
    void display(){
        cout<<"Name: "<<name<<"\n";
        cout<<"Account type: "<<acctype<<"\n";
        cout<<"Account no: "<<acc_no<<"\n";
        cout<<"Account balance: "<<balance<<"\n";
    }
    void deposit(float amount){
        if(amount > 0){
            balance += amount;
            cout<<"Amount deposited: "<<amount<<"\n";
            cout<<"New balance: "<<balance<<"\n";
        }else{
            cout<<"The amount must be positive.\n";
        }
    }
    void withdraw(float amount){
        if(amount <= 0){
            cout<<"The amount must be positive.\n";
        }else if(amount > balance){
            cout<<"Insufficient balance.\n";
        } else{
            balance -= amount;
            cout<< "Amount withdrawn: "<<amount<<"\n";
            cout<< "New balance: "<<balance<<"\n";
        }
    }
};
int main(){
    string name, acctype;
    int acc_no;
    float balance;
    cout<<"Enter your name: ";
    getline(cin, name);
    cout<<"Enter the Account type: ";
    getline(cin, acctype);
    cout<<"Enter the Account no.: ";
    cin>>acc_no;
    cout<<"Enter the Account balance: ";
    cin>>balance;
    bank_acc obj(name, acctype, acc_no, balance);
    int choice;
    float amount;
    do{
        cout<<"\n\nWelcome to the Bank!\n";
        cout<<"1. Deposit\n2. Withdraw\n3. Display account details\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter the amount to deposit: ";
                cin>>amount;
                obj.deposit(amount);
                break;
            case 2:
                cout<<"Enter the amount to withdraw: ";
                cin>>amount;
                obj.withdraw(amount);
                break;
            case 3:
                obj.display();
                break;
            default:
                cout<<"Invalid choice. Try again.\n";
        }
    } while(choice != 3);
    return 0;
}
