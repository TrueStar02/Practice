#include <iostream>
#include "Student.h"
using namespace std;


Student::Student(int gender, string name):gender(gender), name(name){
	if(gender == 1){
		boy_num++;
	}
	else{
		girl_num++;
	}
	person_num++;
}
Student::~Student(){
	if(gender == 1){
		boy_num--;
	}
	else{
		girl_num--;
	}
	person_num--;
};

void Student::sayHi(){
	int student_num = boy_num+girl_num;
	if(student_num <= 1) 
		cout << "Hi! My name is " << name << ". I have no classmates here." << endl;
	else if(student_num == 2){
		cout << "Hi! My name is " << name << ". I have only 1 classmate here." << endl;
	}
	else{
		cout << "Hi! My name is " << name << ". I have " << student_num-1 << " classmates here." << endl;

	}
}


int Student::boy_num = 0;
int Student::girl_num = 0;
int Student::person_num = 0;

void total(){
	
	if(Student::person_num != 0){
		cout << "The number of people is " << Student::person_num << ". ";
		cout << "The number of students is " << Student::boy_num + Student::girl_num << ". ";
		cout << "The number of girls is " << Student::girl_num << ". ";
		cout << "The number of boys is " << Student::boy_num << "." << endl;
	}
	else{
		cout << "There is nobody here." << endl;
	}
}