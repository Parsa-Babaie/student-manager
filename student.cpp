#include "student.h"

#include<iostream>
#include<algorithm>
#include<fstream>

using namespace std;

void loadStudents(vector<Student>& students){
    ifstream file("students.txt");

    Student temp;
    string name;
    string ageStr;

    while(getline(file , name)){
        temp.setName(name);
        getline(file , ageStr);

        temp.setAge(stoi(ageStr));

        students.push_back(temp);
    }
    file.close();
}
void saveStudents(const vector<Student>& students){
    ofstream file("students.txt");
    for(const Student& student: students){
        file<< student.getName() <<endl;
        file<< student.getAge() << endl;
    }
    file.close();
}

void addStudent(vector<Student>& students){
    string name;
    int age;

    cout<<"Enter student name: ";

    cin.ignore();
    getline(cin , name);

    cout<<"Enter student age: ";
    cin>>age;

    
    if(studentExist(students,name)){
        cout<< "student already exist!" <<endl;
        return;
    }

    students.emplace_back(name , age);
    saveStudents(students);

    cout<<"student "<<name<<" added successfully!"<<endl;
}
void deleteStudent(vector<Student>& students){
    int studentNumber;
    if(students.empty()){
        cout<<"NO student to delete!"<<endl;
    }
    else{
        cout<<"\nStudents list: "<<endl;
        for(int i=0 ; i < students.size() ; i++){
            cout<<i+1<<". "<<students[i].getName()<<" | Age: "<<students[i].getAge()<<endl;
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
            cout<<i+1<<". "<<students[i].getName()<<" | Age: "<<students[i].getAge()<<endl;
        }
        cout<<"Enter student number to edit: ";
        cin>>studentNUmber;
        if(studentNUmber>=1 && studentNUmber<=students.size()){
            cout<<"Enter new name: ";
            cin.ignore();
            getline(cin , newName);
            students[studentNUmber - 1].setName(newName);
            saveStudents(students);
            cout<<"Student updated successfully!"<<endl;
        }
        else{
            cout<<"Invalid student number!"<<endl;
        }
    }
}

void searchStudent(vector<Student>& students){
    string name;
    bool found = false;
    cout<<"Enter student name:";
    cin.ignore();
    getline(cin , name);

    for(const Student& student: students){
        if(student.getName()==name){
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
            cout<<i+1<<". "<<students[i].getName()<<" | Age: "<<students[i].getAge()<<endl;
        }
    }
}

void sortStudent(vector<Student>& students){
    sort(students.begin() , students.end(),
        [](const Student& a ,const Student& b){
            return a.getName() < b.getName();
        });
    saveStudents(students);
    cout<<"Student sort successfully!"<<endl;    
}
void sortAge(vector<Student>& students){
    sort(students.begin() , students.end(),
         [](const Student& a , const Student& b){
            return a.getAge() < b.getAge();
        });
    saveStudents(students);    
    cout<<"Student sort by age successfully!"<<endl;    
}
void filterBetweenAges(const vector<Student>& students){
    int minAge;
    int maxAge;
    cout<<"Enter minimum age: ";
    cin>>minAge;
    cout<<"Enter maximum age: ";
    cin>>maxAge;
    if(minAge > maxAge){
        cout<<"Invalid age range!"<<endl;
        return;
    }
    cout<<"\nStudents:\n";
    bool found = false;
    for(const Student& student : students){
        if(student.getAge() >= minAge && student.getAge() <= maxAge){
            cout<<student.getName()
                <<" | Age: "
                <<student.getAge()
                <<endl;
                found = true;
        }
    }
    if(!found){
        cout<<"No students found!"<<endl;
    }
}

bool studentExist(const vector<Student>& students, const string& name){
    for(const Student& student : students){
        if(student.getName() == name){
            return true;
        }
    }
    return false;
}
void filterByAge(const vector<Student>& students){
    int minAge;
    cout<<"Enter a minimum age: ";
    cin>>minAge;
    bool found = false;

    cout<<"\nStudents:\n";
    for(const Student& student : students){
        if(student.getAge() >= minAge){
            cout<<student.getName()
                <<" | Age: "
                <<student.getAge()
                <<endl;
            found = true;
        }
    }
    if(!found){
        cout<<"No students found!"<<endl;
    }
}
