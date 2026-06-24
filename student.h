#ifndef STUDENT_H
#define STUDENT_H

#include<vector>
#include<string>

using namespace std;

class Student{
    private:
        string name;
        int age;

    public:
        Student(): name(""),age(0){}
        Student(string newName , int newAge)
            : name(newName),age(newAge){}
        void setName(string newName){
            name = newName;
        }    
        string getName() const{
            return name;
        }
        void setAge(int newAge){
            age = newAge;
        }
        int getAge() const{
            return age;
        }
};

void saveStudents(const vector<Student>& students);
void loadStudents(vector<Student>& students);

void addStudent(vector<Student>& students);
void deleteStudent(vector<Student>& students);
void editStudent(vector<Student>& students);

void searchStudent(vector<Student>& students);
void showStudents(const vector<Student>& students);
void sortStudent(vector<Student>& students);
void sortAge(vector<Student>& students);
void filterByAge(const vector<Student>& students);
void filterBetweenAges(const vector<Student>& students);
bool studentExist(const vector<Student>& students , const string& name);

#endif