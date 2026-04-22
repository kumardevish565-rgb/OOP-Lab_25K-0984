#include <iostream>
#include <string>
using namespace std;

class Payment {
public:
    virtual void processPayment(double amount)=0;
};

class CreditCard : public Payment {
    void processPayment(double amount) override {
        cout << "Processing Credit Card payment of $" << amount*1.02 << endl;
    }
};

class PayPal : public Payment {
    void processPayment(double amount) override {
        if(amount>500){
            cout << "Processing PayPal payment of $" << amount-10 << endl;
        }
        else{
            cout << "Processing PayPal payment of $" << amount << " after $10 discount\n";
        }
    }
};

int main() {
    CreditCard c1;
    PayPal pp1;
    Payment* p1=&c1;
    p1->processPayment(100);
    p1=&pp1;
    p1->processPayment(600);
    return 0;
}