/*Yes, a friend function can be used to overload the += operator as it has access to class's private data and can modify it. It takes two arguments. The second argument is the modifier value.
The first argument usually represents the invoking object(passed by non-const refrence) which can be modifed as required inside the function definiton similar to how it would be modified inside a member function. The main difference is it is passed as an argument rather than an implict this pointer and called as regular function rather than member fucntion.
*/
#include <iostream>
using namespace std;

class Warehouse {
    int packageCount;
public:
    Warehouse(int count): packageCount(count) {}
    int getCount() const {
        return packageCount;
    }
    friend Warehouse& operator+=(Warehouse& w, const int count);
};

Warehouse& operator+=(Warehouse& w, const int count){
    w.packageCount+=count;
    return w;
}

int main(){
    Warehouse w1(50);
    cout << "Package count after subtraction: " << (w1+=30).getCount() << endl;
    return 0;
}