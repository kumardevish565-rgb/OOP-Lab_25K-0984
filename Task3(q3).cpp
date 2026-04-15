/*No, a friend function cannot access non-staticdata of an object if it is not passed as function argument.
Friend function is not a member function and so does not have an implict this pointer pointing to an object. It always requires explictly passing the object as argument to access non-static data.
However, it can access static members as they are not associated with any specific object but with the class
*/

#include <iostream>
using namespace std;

class Demo {
    string data;
    static string data2;
public:
    Demo(string d): data(d) {}
    friend void accessData();  //No object passed as argument
    friend void accessData(Demo& d); //Object passed as argument
};

string Demo::data2="C++";
void accessData(){
    // cout << Demo::data << endl; Compilation Error: a nonstatic member reference must be relative to a specific object
    cout << "Data2(static)= " << Demo::data2 << endl;
}

void accessData(Demo& d){
    cout << "Data: " << d.data << endl;
}

int main(){
    Demo d("Hello World");
    accessData(d);
    accessData();
    return 0;
}