#include "SecuritySystem.h"

int main(){
    BiometricScanner bs;
    SecurityDevice* s1=&bs;
    s1->authenticate();
    return 0;
}