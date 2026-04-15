#include <iostream>
#include <string>
using namespace std;

class User {
    string id;
    string role;
    int accessLevel;
public:
    User(string Id,string Role,int level): id(Id), role(Role), accessLevel(level) {}
    void viewAccessibleDevices(){
        cout << id << "-Accessible Devices\n";
        if(accessLevel==2){
            cout << "Lights, Fans, ACs, Security System\n";
        }
        else{
            cout << "Lights, Fans, ACs\n";
        }
    }
    friend void accessSecurityLogs(User& user);
};

class Device {
protected:
    string id;
    string type;
    double powerRating;
    bool status;
public:
    Device(string Id, string Type, double rating) : id(Id), type(Type), powerRating(rating), status(false) {}
    virtual ~Device() {}
    string getType() const {
        return type;
    }
    virtual void turnOn() {
        status=true;
        cout << type  << " [ID:" << id << "] turned on.\n";
    }
    virtual void turnOff() {
        status=false;
        cout << type  << " [ID:" << id << "] turned off\n";
    }
    virtual double calculatePowerUsage(int hours) = 0;
};

class Light : public Device {
public:
    Light(string Id, string type, double rating) : Device(Id,type,rating) {}
    double calculatePowerUsage(int hours) override
    {
        return powerRating * hours;
    }
};

class Fan : public Device {
    int speedFactor;
public:
    Fan(string Id, string type, double rating, int factor) : Device(Id,type,rating), speedFactor(factor) {}
    void turnOn() override {
        status=true;
        cout << type  << " [ID:" << id << "] turned on at speed " << speedFactor << endl;
    }
    double calculatePowerUsage(int hours) override
    {
        return powerRating * hours * speedFactor;
    }
};

class AirConditioner : public Device {
    float currentTemp;
    float desiredTemp;
public:
    AirConditioner(string Id, string type, double rating, float temp) :  Device(Id,type,rating), currentTemp(temp), desiredTemp(temp) {}
    void turnOff() override {
        desiredTemp+=5;
        status=false;
    }
    void turnOn() override {
        desiredTemp-=5;
        status=true;
        cout << type  << " [ID:" << id << "] turned on cooling at " << currentTemp << " C\n";
    }
    double calculatePowerUsage(int hours) override
    {
        return powerRating * hours * (1 - (currentTemp - desiredTemp) / 100);
    }
};

class SecuritySystem : public Device {
    string securityCheck;
    bool alerts;
public:
    SecuritySystem(string Id, string type, double consumption): Device(Id, type, consumption), securityCheck("1234"), alerts(false) {}
    void turnOff() override {
        string s;
        cout << "Enter 4 digit pin to turn off security system\n";
        cin >> s;
        if(s==securityCheck){
            status=false;
            cout << "Security system deactivated\n";
        }
        else{
            cout << "Invalid pin\n";
        }
    }
    double calculatePowerUsage(int hours) override {
        cout << "Security Status: All sensors operational. No intrusions detected - "; 
        return powerRating * hours;
    }
    friend void accessSecurityLogs(User& user);
    friend class MaintenanceTool;
};

class MaintenanceTool {
public:
    void resetAlerts(SecuritySystem& ss) {
        ss.alerts=false;
        cout << "Security system alerts re-setted\n";
    }
};

void accessSecurityLogs(User& user){
    if(user.accessLevel==2){
        cout << "\n" << user.id << "-Security Logs:\nIntrusion Detected at 3:00 AM\nSystem Reset Required\n";
    }
    else{
        cout << "Restricted access\n";
    }
}

int main(){
    User user1("U001","Regular User",1),user2("U002","Maintenance Staff", 2);
    Device* devices[4]={new Light("L001","LED Light",10), new Fan("F001","Ceiling Fan",75,3), new AirConditioner("AC001","Split AC",1500,25), new SecuritySystem("S001","Home Alarm",100)};
    for(int a=0;a<4;a++){
        devices[a]->turnOn();
    }
    cout << "\nPower Consumption\n";
    cout << devices[0]->getType() << " = " << devices[0]->calculatePowerUsage(5) << " Watts\n";
    cout << devices[1]->getType() << " = " << devices[1]->calculatePowerUsage(3) << " Watts\n";
    cout << devices[2]->getType() << " = " << devices[2]->calculatePowerUsage(6) << " Watts\n";
    cout << devices[3]->getType() << ": " << devices[3]->calculatePowerUsage(24) << " Watts\n\n";
    user1.viewAccessibleDevices();
    accessSecurityLogs(user2);
    devices[3]->turnOff();  //PIN=1234
    for(int a=0;a<4;a++){
        delete devices[a];
    }   
}