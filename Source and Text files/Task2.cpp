#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    ifstream obj("secret.txt");
    if(obj.is_open()){
        char ch;
        int count=0;
        while(obj.get(ch)) {
            if(isupper(ch)) {
                count++;
            }
        }
        cout << "Total number of uppercase characters read: " << count << endl;
        obj.close();
    }
    else {
        cerr << "Error opening file\n";
        return 1;
    }
    return 0;
}