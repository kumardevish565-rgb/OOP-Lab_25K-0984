#include <iostream>
#include <string>
using namespace std;

class Account {
    string accountNumber;
    string accountHolder;
    double balance;
public:
    Account(string accountNo,string holder,double b=0): accountNumber(accountNo), accountHolder(holder), balance(b) {}
    double getBalance() const {
        return balance;
    }
    string getHolderName() const {
        return accountHolder;
    }
    void deposit(const double amount){
        balance+=amount;
    }
    Account operator+(const Account &other){
        return Account("Total","None",balance+other.balance);
    }    
    Account& operator-=(const double amount){
        if(balance>=amount){
            balance-=amount;
        }
        else{
            cout << "Insufficient fund for the transfer\n";
        }
        return *this;
    }
    bool operator>(const Account& other){
        return balance>other.balance;
    }
    Account& operator+=(const double amount){
        balance+=amount;
        return *this;
    }
    friend ostream& operator<<(ostream&os, const Account& account);
};

ostream& operator<<(ostream& os, const Account& account){
    os << "Account Number: " << account.accountNumber << "  | Account Holder: " << account.accountHolder << " | Current Balance: " << account.balance << endl;
    return os;
}

int main(){
    Account a1("101","John Doe",5000),a2("102","Alice Smith",3000);
    cout << "Total Balance(after additon): " << (a1+a2).getBalance() << endl;
    cout << a1.getHolderName() << " Balance: " << (a1-=2000).getBalance() << "\n" << a2.getHolderName () << " Balance: " << (a2+=2000).getBalance() << endl;
    if(a1>a2){
        cout << a1.getHolderName() << " has higher balance than " << a2.getHolderName() << endl;
    }
    else{
        cout << a1.getHolderName() << " has lower balance than " << a2.getHolderName() << endl;
    }
    cout << "Final Account Details\n" << a1 << a2;
}