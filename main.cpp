#include<iostream>

using namespace std;

int main(){
    int choice;
    
    cout<< "=== student manager ==="<<endl;
    cout<<"1. Add Student"<<endl;
    cout<<"2. Show students"<<endl;
    cout<<"3. Exit"<<endl;

    cout<<"Enter your choice: ";
    cin>>choice;

    if(choice==1){
        cout<<"Add Student selected."<<endl;
    }
    else if(choice==2){
        cout<<"Show Students selected."<<endl;
    }
    else if(choice==3){
        cout<<"Goodbye!"<<endl;
    }
    else{
        cout<<"Invalid choice!"<<endl;
    }
    return 0;
}
