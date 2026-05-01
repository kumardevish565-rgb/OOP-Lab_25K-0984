#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream obj("signup.txt",ios::app);
    if(obj.is_open()) {
        string data;
        cout << "Enter name ";
        getline(cin,data);
        obj << data << ",";
        cout << "Enter email address ";
        getline(cin,data);
        obj << data << endl;
        obj.close();
    }
    else{
        cerr << "Error opening file\n";
        return 1;
    }
    return 0;
}
