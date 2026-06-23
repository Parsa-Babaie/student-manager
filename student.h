#ifndef STUDENT_H
#define STUDENT_H

#include<vector>
#include<string>

using namespace std;

struct Student{
    string name;
    int age;
};

void saveStudents(vector<Student>& students);
void loadStudents(vector<Student>& students);

void addStudent(vector<Student>& students);
void deleteStudent(vector<Student>& students);
void editStudent(vector<Student>& students);

void searchStudent(vector<Student>& students);
void showStudents(const vector<Student>& students);
bool studentExist(const vector<Student>& students , const string& name);

#endif