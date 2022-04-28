#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class Student{
	public:
		static int girl_num;
		static int boy_num;
		static int person_num;
		Student(int gender, string name);
		~Student();
		void sayHi();
	private:
		string name;
		int gender;
};

void total();

#endif