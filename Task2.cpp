#include <iostream>
#include <string>
using namespace std;

class Account {
    int Number;
    string HolderName;
    float Balance;
public:
    Account(int n,string s,float b): Number(n),HolderName(s),Balance(b) {};
    int ValidateBalance(){
        if(Balance<0){
            cout << "Account Balance cannot be negative\n";
            return 0;
        }
        else{
            return 1;
        }
    }
    void SetName(string Name){
        HolderName=Name;
    }
    void Deposit(float amount){
        if(amount<0){
            cout << "Deposit Amount cannot be negative\n";
        }
        else{
            Balance+=amount;
            cout << "Amount successfully deposited\n";
        }
    }
    void Withdraw(float amount){
        if(amount<0){
            cout << "Withdrawal amount cannot be negative\n";
        }
        else if(amount>Balance){
            cout << "Withdrawal Amount cannot exceed current balance\n";
        }
        else{
            Balance-=amount;
            cout << "Amount successfully withdrawed\n";
        }
    }
    void DisplayAccount(){
        cout << "Account Number: " << Number << endl;
        cout << "Account Holder Name: " << HolderName << endl;
    }
    void DisplayBalance(){
        cout << "Current Balance: " << Balance << endl;
    }
};

int main(){
    int num;
    float balance;
    string name;
    cout << "Enter account number and current balance \n";
    cin >> num >> balance;
    cout << "Enter account holder name \n";
    getline(cin >> ws, name);
    Account a1(num,name,balance);
    if(a1.ValidateBalance()==0){
        return 1;
    }
    float amount;
    cout << "Enter amount to deposit \n";
    cin >> amount;
    a1.Deposit(amount);
    a1.DisplayBalance();
    cout << "Enter amount to withdraw \n";
    cin >> amount;
    a1.Withdraw(amount);
    a1.DisplayBalance();
    a1.Withdraw(1000);
    a1.DisplayBalance();
    a1.Deposit(1000);
    a1.DisplayAccount();
    a1.DisplayBalance();
    return 0;
}