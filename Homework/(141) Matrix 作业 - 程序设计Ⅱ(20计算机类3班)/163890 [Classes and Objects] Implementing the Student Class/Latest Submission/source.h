#include<iostream>
#include<cstring>
using namespace std;
class Student
 {  public:
        Student(int i=0, const char*s="No Name", int a=0)
        {id=i;strcpy(name,s);age=a;}
        void set(int i, const char* s, int a)
        {id=i;strcpy(name,s);age=a;}
        void print() const
        {cout<<name<<" ("<<id<<") is "<<age<<" years old.\n";}
    private:
        int id;
        char name[50]; 
        int age; 
};