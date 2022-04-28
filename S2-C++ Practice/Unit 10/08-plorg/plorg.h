#ifndef PLORG_H_
#define PLORG_H_
#include<iostream>
#include<cstring>
using namespace std;
class Plorg
{	private:
		char name[20];
		int CI;
	public:
		Plorg();
		Plorg(const char * str);
		~Plorg();
		void show() const;
		void change(int n);                  
};
#endif
