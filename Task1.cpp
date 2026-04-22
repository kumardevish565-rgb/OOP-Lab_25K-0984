#include <iostream>
#include <string>
using namespace std;

class CoffeMachine {
    float waterLevel;
    string coffeBeans;
public:
    CoffeMachine(float w,string c): waterLevel(w), coffeBeans(c) {}
    void makeCoffe() {
        if(waterLevel<100) {
            cout << "Insufficient water\n";
        }
        else {
            waterLevel-=10;
            cout << "Coffee is ready!\n";
        }
    }

};

int main(){ 
    CoffeMachine c1(105,"Arabica");
    c1.makeCoffe();
    return 0;
}