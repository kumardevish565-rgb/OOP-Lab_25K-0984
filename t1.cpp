#include <iostream>
#include <string>
using namespace std;
#define START_ID 1001

class Employee {
    int Id;
    string Name;
    float Salary;
public:
    static int count;
    Employee(string n, float s) : Name(n), Salary(s) {
        Id=START_ID+count;
        count++;
    }
    void DisplayDetails() const{
        cout << "Employee Details\nName: " << Name << "\nId: " << Id << "\nSalary: " << Salary << endl;
    }
};

int Employee::count=0;

int main(){
    Employee e1("Vivek",20000.0),e2("Devish",40000.0),e3("Ali",31000.0),e4("Vainkut",20000.0);
    e1.DisplayDetails();
    e2.DisplayDetails();
    e3.DisplayDetails();
    e4.DisplayDetails();
    cout << "Total number of employees is " << Employee::count << endl;
    Employee e5("Sarim",27000);
    e5.DisplayDetails();
    cout << "Total number of employees is " << Employee::count << endl;
    return 0;
}