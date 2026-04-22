#include <iostream>
#include "SecuritySystem.h"
using namespace std;

BiometricScanner::BiometricScanner(): attempts(0) {}

void BiometricScanner::authenticate()  {
    if(attempts>=3){
        cout << "System Locked\n";
    }
    else{
        int fingerprintId;
        while(attempts<3){
            cout << "Enter fingerprint id " << endl;
            cin >> fingerprintId;
            if(fingerprintId==1234){
                cout << "Access Granted\n";
                return ;
            }
            attempts++;
        }
        cout << "System Locked\n";
    }
}