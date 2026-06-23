#include "student.h"

#include<iostream>
#include<fstream>

using namespace std;

void loadStudents(vector<Student>& students){
    ifstream file("students.txt");

    Student temp;
    string ageStr;

    while(getline(file , temp.name)){
        getline(file , ageStr);

        temp.age = stoi(ageStr);

        students.push_back(temp);
    }
    file.close();
}
void saveStudents(vector<Student>& students){
    ofstream file("students.txt");
    for(Student student: students){
        file<< student.name <<endl;
        file<< student.age << endl;
    }
    file.close();
}

void addStudent(vector<Student>& students){
    Student newStudent;

    cout<<"Enter student name: ";

    cin.ignore();
    getline(cin , newStudent.name);

    cout<<"Enter student age: ";
    cin>>newStudent.age;
    
  /*  if(studentExist(students,studentName)){
        cout<< "student already exist!" <<endl;
        return;
    }*/

    students.push_back(newStudent);
    saveStudents(students);

    cout<<"student "<<newStudent.name<<" added successfully!"<<endl;
}
void deleteStudent(vector<Student>& students){
    int studentNumber;
    if(students.empty()){
        cout<<"NO student to delete!"<<endl;
    }
    else{
        cout<<"\nStudents list: "<<endl;
        for(int i=0 ; i < students.size() ; i++){
            cout<<i+1<<". "<<students[i].name<<" | Age: "<<students[i].age<<endl;
        }
        cout<<"Enter student number to delete:";
        cin>>studentNumber;
        if(studentNumber >= 1 && studentNumber <= students.size()){
            students.erase(students.begin() + studentNumber - 1);
            saveStudents(students);
            cout<<"student deleted successfully"<<endl;
        } 
        else{
            cout<<"Invalid student number!"<<endl;
        }
    }
}
void editStudent(vector<Student>& students){
    int studentNUmber;
    string newName;
    if(students.empty()){
        cout<<"No student found!"<<endl;
        return;
    }
    else{
        cout<<"\nstudents list: "<<endl;
        for(int i=0;i<students.size();i++){
            cout<<i+1<<". "<<students[i].name<<" | Age: "<<students[i].age<<endl;
        }
        cout<<"Enter student number to edit: ";
        cin>>studentNUmber;
        if(studentNUmber>=1 && studentNUmber<=students.size()){
            cout<<"Enter new name: ";
            cin.ignore();
            getline(cin , newName);
            students[studentNUmber - 1].name = newName;
            saveStudents(students);
            cout<<"Student updated successfully!"<<endl;
        }
        else{
            cout<<"Invalid student number"<<endl;
        }
    }
}

void searchStudent(vector<Student>& students){
    string name;
    bool found = false;
    cout<<"Enter student name:";
    cin>>name;

    for(Student student: students){
        if(student.name==name){
            found = true;
            break;
        }
    }
    if(found){
        cout<<"Student found!"<<endl;
    }
    else{
        cout<<"Student not found!"<<endl;
    }

}
void showStudents(const vector<Student>& students){
    if(students.empty()){
        cout<<"No student found!"<<endl;
    }
    else{
        cout<<"\nStudents list: "<<endl;
        for(int i=0;i<students.size();i++){
            cout<<i+1<<". "<<students[i].name<<" | Age: "<<students[i].age<<endl;
        }
    }
}
bool studentExist(const vector<Student>& students , const string& name){
    for(Student student : students){
        if(student.name == name){
            return true;
        }
    }
    return false;
}
