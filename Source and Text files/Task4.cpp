#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    fstream obj("draft.txt",ios::in | ios::out);
    if(!obj.is_open()){
        cerr << "Error opening file\n";
        return 1;
    }
    string temp;
    bool found=false;
    while(obj >> temp) {
        if(temp=="teh"){
            int pos=obj.tellg();
            obj.clear();
            obj.seekp(pos-3);
            obj << "the";
            found=true;
            break;
        }    
    }
    if(!found) {
        cout << "No typo 'teh' exists in the file\n";
    }
    else{
        cout << "Successfully replace 'teh' with 'the'\n";
    }
    obj.close();
    return 0;
}