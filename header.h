#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
using namespace std;

class Employee {
    string name;
    string empId;
    float baseSalary;
    float hours;
public:
    Employee(){
        name="Unknown";
        empId="0";
        baseSalary=0;
        hours=0;
    }
    Employee(string n,string e,float b,float h){
        name=n;
        empId=e;
        baseSalary=b;
        hours=h;
    }
    void SetName(string Name){
        name=Name;
    }
    void SetId(string Id){
        empId=Id;
    }
    void SetSalary(float Salary){
        baseSalary=Salary;
    }
    void SetHours(float Hours){
        hours=Hours;
    }
    float RegularPay() const {
        if(hours<=40){
            return hours*baseSalary;
        }
        else{
            return 40*baseSalary;
        }
    }
    float OverTimePay() const {
        if(hours>40){
            return (hours-40)*1.5*baseSalary;
        }
        else{
            return 0;
        }
    }
    float TotalSalary() const {
        return RegularPay()+OverTimePay();
    }
    static void Compare(const Employee &e1,const Employee &e2){
        if(e1.TotalSalary() > e2.TotalSalary()){
            cout << "Employee with Id: " << e1.empId << " has higher total salary than employee with ID: " << e2.empId << endl;
        }
        else if(e1.TotalSalary() < e2.TotalSalary()){
            cout << "Employee with Id: " << e2.empId << " has higher total salary than employee with ID: " << e1.empId << endl;
        }
        else{
            cout << "Both employees have equal salaries\n";
        }
    }
    void Display() const {
        cout << "Employee Details\n";
        cout << "Name: " << name << endl;
        cout << "Id: " << empId << endl;
        cout << "Hours Worked: " << hours << endl;
        cout << "Base Salary: " << baseSalary << endl;
        cout << "Regular Pay(excluding overtime): " << RegularPay() << endl;
        cout << "Over Time Pay: " << OverTimePay() << endl;
        cout << "Total Salary: " << TotalSalary() << endl;
    }
};
#endif