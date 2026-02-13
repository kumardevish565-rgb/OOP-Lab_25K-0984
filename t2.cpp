#include <iostream>
#include <string>
using namespace std;

class Satellite {
    const string Date;
    const int Id;
    float OrbitRadius;
public:
    static int count;
    Satellite(string date, int id, float radius) : Date(date), Id(id), OrbitRadius(radius){}
    void viewReport() const {
        count++;
        cout << "Satellite Details\nDate: " << Date << "\nId: " << Id << "\nOrbit Radius: " << OrbitRadius << "\nTotal number of times this report has been viewed(including current instance) " << count << endl;
    } 
    void calibrate(float r){
        OrbitRadius+=r;
    }
};

int Satellite::count=0;

int main(){
    Satellite s1("26/10/26",1000,200000),s2("08/05/24",1001,100000);
    s1.viewReport();
    s2.viewReport();
    s1.calibrate(1800);
    s1.viewReport();
    return 0;
}