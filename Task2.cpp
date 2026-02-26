#include <iostream>
#include <string>
using namespace std;

class MedicationEntry {
    string drugName;
    int dose;
    float timeGiven;
public:
    MedicationEntry(string name="Unknown",int Dose=0,float time=0): drugName(name), dose(Dose), timeGiven(time) {}
    void Display() const {
        cout << "Medication Details\nDrug Name: " << drugName << "\tDose: " << dose << "\t Time since medicine last given(hours) " << timeGiven << endl;
    } 
};

class VitalSignsCheck {
    float temperature;
    float heartRate;
    float timeChecked;
public:
    VitalSignsCheck(float temp=0,float rate=0,float time=0): temperature(temp), heartRate(rate), timeChecked(time) {}
    void Display() const {
        cout << "Vital Signs Details\nTemperature: " << temperature << "F\tHeart Rate: " << heartRate << "  \t Time since last checkup(hours) " << timeChecked << endl;
    } 
};

class DiagnosisNote {
    string noteText;
    string doctorName;
    string date;
public:
    DiagnosisNote(string note=" ",string name="Unknown",string Date="00/00/00"): noteText(note), doctorName(name), date(Date) {}
    void Display() const {
        cout << "Diagnosis Details\nText Note: " << noteText << "\t  Doctor Name: " << doctorName << "\t Date: " << date << endl;
    } 
};

class PatientRecord {
    int patientId;
    string name;
    string dob;
    MedicationEntry *medicnePtr;
    VitalSignsCheck *vitalsignsPtr;
    DiagnosisNote *diagnosisPtr;
public:
    PatientRecord(int id,string pName,string Dob,string mName,int Dose,float time,float temp,float rate,float lastTime,string note,string date,string doctor): patientId(id), name(pName), dob(Dob){
        medicnePtr=new MedicationEntry(mName,Dose,time);
        vitalsignsPtr=new VitalSignsCheck(temp,rate,lastTime);
        diagnosisPtr=new DiagnosisNote(note,doctor,date);
    }
    PatientRecord(const PatientRecord& obj){
        patientId=obj.patientId;
        name=obj.name;
        dob=obj.dob;
        medicnePtr=new MedicationEntry;
        vitalsignsPtr=new VitalSignsCheck;
        diagnosisPtr=new DiagnosisNote;
    }
    ~PatientRecord(){
        delete medicnePtr;
        delete vitalsignsPtr;
        delete diagnosisPtr;
        cout << "Patient record and its entries deleted\n";
    }
    void Display() const {
        cout << "Patient Details\nName: " << name << "\tId: " << patientId << "\tDate of Birth: " << dob << endl;
        medicnePtr->Display();
        vitalsignsPtr->Display();
        diagnosisPtr->Display();
    }
};

int main(){
    PatientRecord p1(1001,"Lily Smith","24/02/2003","Panadol",2,3,100.4,124,1.5,"Needs bed rest for atleast six days","28/2/2026","Sam");
    p1.Display();
    return 0;
}