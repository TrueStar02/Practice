#include<cstring>
#include<iostream>
using namespace std;
 class Student 
 {
    public:
        int id;
        char name[50]; // Data field
        int age; // Data field
        Student(){}
        Student(int pid, const char* s= "No Name", int a= 0)
        {id=pid;strcpy(name,s);age=a;}
       
};
 void set(Student & s, int pid, const char* st, int a)
  {s.id=pid;strcpy(s.name,st);s.age=a;}
        void print(Student & s)
        {
            cout<<s.name<<" ("<<s.id<<") is "<<s.age<<" years old.\n";
        }