#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream outFile("backup_log.txt",ios::app);
    if(outFile.is_open()) {
        std::cout << "Enter log messages (enter 0 to quit):" << std::endl;
        string message;
        while (true) {
            getline(cin,message);
            if(message=="0"){
                break;
            }
            outFile << message << endl;
            int size=outFile.tellp();
            cout << "Current file size: " << size << " bytes" << endl;
        }
        outFile.close();
    }
    else {
        cout << "Error opening file\n";
        return 1;
    }
    return 0;
}