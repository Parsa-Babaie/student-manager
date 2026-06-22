#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<limits>

using namespace std;

void saveStudents(vector<string>& students){
    ofstream file("students.txt");
    for(string student: students){
        file<< student <<endl;
    }
    file.close();
}

void editStudent(vector<string>& students){
    int studentNUmber;
    string newName;
    if(students.empty()){
        cout<<"No student found!"<<endl;
        return;
    }
    else{
        cout<<"\nstudents list: "<<endl;
        for(int i=0;i<students.size();i++){
            cout<<i+1<<". "<<students[i]<<endl;
        }
        cout<<"Enter student number to edit: ";
        cin>>studentNUmber;
        if(studentNUmber>=1 && studentNUmber<=students.size()){
            cout<<"Enter new name: ";
            cin.ignore();
            getline(cin , newName);
            students[studentNUmber - 1] = newName;
            saveStudents(students);
            cout<<"Student updated successfully!"<<endl;
        }
        else{
            cout<<"Invalid student number"<<endl;
        }
    }
}

void searchStudent(vector<string>& students){
    string name;
    bool found = false;
    cout<<"Enter student name:";
    cin>>name;

    for(string student: students){
        if(student==name){
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

void loadStudents(vector<string>& students){
    ifstream file("students.txt");

    string student;
    while(getline(file,student)){
        students.push_back(student);
    }
    file.close();
}

void showMenu(){
    cout<<"\n=== student manager ==="<<endl;
    cout<<"1. Add Student"<<endl;
    cout<<"2. Show students"<<endl;
    cout<<"3. Delete student"<<endl;
    cout<<"4. Search student"<<endl;
    cout<<"5. Edit student"<<endl;
    cout<<"6. Exit"<<endl;
}

bool studentExist(const vector<string>& students , const string& name){
    for(string student : students){
        if(student == name){
            return true;
        }
    }
    return false;
}

void addStudent(vector<string>& students){
    string studentName;

    cout<<"Enter student name: ";
    cin.ignore();
    getline(cin , studentName);
    
    if(studentExist(students,studentName)){
        cout<< "student already exist!" <<endl;
        return;
    }

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
    if(cin.fail()){
        cin.clear();

        cin.ignore(numeric_limits<streamsize>::max() , '\n');

        cout<<"Please enter a valid number!"<<endl;
        continue;
    }
    
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
        searchStudent(students);
    }
    else if(choice==5){
        editStudent(students);
    }
    else if(choice==6){
        cout<<"Goodbye!"<<endl;
        break;
    }
    else{
        cout<<"Invalid choice!"<<endl;
    }
    }
    return 0;
}
