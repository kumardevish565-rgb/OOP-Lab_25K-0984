#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string RollNo;
    string Name;
    int Marks[3];
    float CGPA;
} Student;

void InputDetails(Student *students, const int size){
    for(int a=0; a<size; a++){
        cout << "Enter the roll number for student " << a+1 << endl;
        cin >> students[a].RollNo;
        cout << "Enter the name for student \n";
        getline(cin >> ws, students[a].Name);
        cout << "Enter the marks for three subjects \n";
        cin >> students[a].Marks[0] >> students[a].Marks[1] >> students[a].Marks[2];
    }
}
void CalculateGpa(Student *students, const int size){
    for(int a=0; a<size; a++){
        float total=students[a].Marks[0]+students[a].Marks[1]+students[a].Marks[2];
        students[a].CGPA=total/30;
    }
}
void DisplayThreeGpa(Student *students, const int size){
    cout << "Students with more than 3 GPA\n";
    for(int a=0; a<size; a++){
        if(students[a].CGPA>=3){
            cout << "Name: " << students[a].Name << "\tGPA: " << students[a].CGPA << endl;
        }
    }
}
void TopPerformer(Student *students, const int size){
    float max=-1;
    int index;
    for(int a=0; a<size; a++){
        if(students[a].CGPA>max){
            index=a;
            max=students[a].CGPA;
        }
    }
    cout << "The top performer is " << students[index].Name << " with CGPA of " << students[index].CGPA << endl;
}

int main(){
    int studentsCount;
    cout << "Enter the number of students \n";
    cin >> studentsCount;
    Student *students= new Student[studentsCount];
    InputDetails(students,studentsCount);
    CalculateGpa(students,studentsCount);
    DisplayThreeGpa(students,studentsCount);
    TopPerformer(students,studentsCount);
    delete[] students;
    return 0;
}