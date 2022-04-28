#include "Student.h"
#include<iostream>
using namespace std;
int Student::girl_num=0;
int Student::boy_num=0;
int Student::person_num=0;
Student::Student(int g, string n):gender(g),name(n)
{   person_num++;
    if(g) 
        boy_num++;
    else
       girl_num++; 
}
Student::~Student()
{   person_num--;
    if(gender) 
        boy_num--;
    else
       girl_num--; 
}
void Student::sayHi()
{   cout<<"Hi! My name is "<<name<<". I have ";
    if(boy_num+girl_num==1)
        cout<<"no classmates here.\n";
    else if(boy_num+girl_num==2) 
        cout<<"only 1 classmate here.\n";
    else
        cout<<boy_num+girl_num-1<<" classmates here.\n";
}

void total()
{   if(Student::person_num)
    {   cout<<"The number of people is "<<Student::person_num<<". ";
        cout<<"The number of students is "<<Student::boy_num+Student::girl_num<<". ";
        cout<<"The number of girls is "<<Student::girl_num<<". ";
        cout<<"The number of boys is "<<Student::boy_num<<".\n";
    }
    else
        cout<<"There is nobody here.\n";
}