#include <iostream>
#include "Student.h"
using namespace std;

void clear(){
	Student::person_num = 0;
	total();
}

int main(){
	int curr_people = 0, student_num = 0;
	cin >> curr_people >> student_num;
	Student* student_list[student_num];
	Student::person_num += curr_people;
	for(int i = 0; i < student_num; ++i){
		string name = "";
		int isBoy = 0;
		cin >> isBoy >> name;
		student_list[i] = new Student(isBoy, name);
		student_list[i]->sayHi();
	}
	total();
	// 学生退场
	cout << endl;
	for(int i = 0; i < student_num; ++i){
		delete student_list[i];
		total();
	}
	clear(); // 嘉宾以及举办方离场
	return 0;
}