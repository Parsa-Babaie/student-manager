#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

void loadStudents(vector<string>& students){
    ifstream file("students.txt");

    string student;
    while(getline(file,student)){
        students.push_back(student);
    }
    file.close();
}

void saveStudents(vector<string>& students){
    ofstream file("students.txt");
    for(string student: students){
        file<< student <<endl;
    }
    file.close();
}

int main(){
    int choice;
    string studentName;
    vector<string> students;
    loadStudents(students);
    int studentNumber;
    while(true){
    cout<< "=== student manager ==="<<endl;
    cout<<"1. Add Student"<<endl;
    cout<<"2. Show students"<<endl;
    cout<<"3. Delete student"<<endl;
    cout<<"4. Exit"<<endl;

    cout<<"Enter your choice: ";
    cin>>choice;
    
    if(choice==1){
        cout<<"Enter student name: ";
        cin>>studentName;
        students.push_back(studentName);
        saveStudents(students);
        cout<<"Student "<<studentName<<" added succesfully!"<<endl;
       
    }
    else if(choice==2){
        if(students.empty()){
            cout<<"No student found."<<endl;
        }
        else{
            cout<<"\nStudent list: "<<endl;
            for(int i=0; i < students.size(); i++){
                cout<<i+1<<". "<< students[i] <<endl;
            }
        }
    }
    else if(choice == 3){
        if(students.empty()){
            cout<<"No student to delete."<<endl;
        }
        else{
            cout<<"\nstudents list: "<<endl;
            for(int i=0;i < students.size();i++){
                cout<<i+1<<". "<<students[i]<<endl;
            }
            cout<<"Enter student number to delete: ";
            cin>>studentNumber;
            if(studentNumber >= 1 && studentNumber <= students.size()){
                students.erase(students.begin()+studentNumber-1);
                saveStudents(students);
                cout<<"student earse successfully"<<endl;
            }
            else{
                cout<<"Invalid student number!"<<endl;
            }
        }
    }
    else if(choice==4){
        cout<<"Goodbye!"<<endl;
        break;
    }
    else{
        cout<<"Invalid choice!"<<endl;
    }
    }
    return 0;
}
