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

void showMenu(){
    cout<<"\n=== student manager ==="<<endl;
    cout<<"1. Add Student"<<endl;
    cout<<"2. Show students"<<endl;
    cout<<"3. Delete student"<<endl;
    cout<<"4. Exit"<<endl;
}

void addStudent(vector<string>& students){
    string studentName;

    cout<<"Enter student name: ";
    cin>> studentName;

    students.push_back(studentName);
    saveStudents(students);

    cout<<"student "<<studentName<<" added successfully!"<<endl;
}

void deleteStudent(vector<string>& students){
    int studentNumber;
    if(students.empty()){
        cout<<"NO student to delete!"<<endl;
    }
    else{
        cout<<"\nStudents list: "<<endl;
        for(int i=0 ; i < students.size() ; i++){
            cout<<i+1<<". "<<students[i]<<endl;
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

void showStudents(const vector<string>& students){
    if(students.empty()){
        cout<<"No student found!"<<endl;
    }
    else{
        cout<<"\nStudents list: "<<endl;
        for(int i=0;i<students.size();i++){
            cout<<i+1<<". "<<students[i]<<endl;
        }
    }
}
int main(){
    int choice;
    vector<string> students;
    loadStudents(students);
    while(true){
    showMenu();    
    cout<<"Enter your choice: ";
    cin>>choice;
    
    if(choice==1){
        addStudent(students);
    }   
    else if(choice==2){
        showStudents(students);
    }    
    else if(choice == 3){
        deleteStudent(students);
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
