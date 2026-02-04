#include "header.h"

int main(){
    Employee e1;
    e1.SetName("Ahmed");
    e1.SetId("25K-0000");
    e1.SetSalary(15);
    e1.SetHours(38.5);
    e1.Display();
    cout << "\n";
    Employee e2("Ali","25K-0001",14.5,42);
    e2.Display();
    cout << "\n";
    Employee::Compare(e1,e2);
    return 0;
}