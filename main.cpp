#include<iostream>
#include<string>
#include<vector>
#include<limits>

#include "student.h"

using namespace std;


void showMenu(){
    cout<<"\n=== student manager ==="<<endl;
    cout<<"1. Add Student"<<endl;
    cout<<"2. Show students"<<endl;
    cout<<"3. Delete student"<<endl;
    cout<<"4. Search student"<<endl;
    cout<<"5. Edit student"<<endl;
    cout<<"6. Exit"<<endl;
}


int main(){
    int choice;
    vector<Student> students;
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
