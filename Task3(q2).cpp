/*Yes, it is possible to overload operator using friend function if one of the operand is of primitve data type like int provided the other operand is non-primitve like a class object.
The implementation involves declaring the function as a friend inside the class and defining it outside the class to take two arguments: the class object and the primitive data type.
*/

#include <iostream>
using namespace std;

class Example {
    int a;
    int b;
public:
    Example(int A, int B): a(A), b(B) {}
    friend Example operator+(const Example& e, const int value);
    void display() const {
        cout << "a=" << a << "\tb=" << b << endl;
    }
};

Example operator+(const Example& e, const int value){
    return Example(e.a+value,e.b+value);
}

int main(){
    Example e1(5,7);
    (e1+3).display();
    return 0;
}