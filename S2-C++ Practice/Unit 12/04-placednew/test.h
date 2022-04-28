#ifndef TEST_H_
#define TEST_H_
#include<iostream>
#include<new>
using namespace std;
class Test
{	private:	
		string word;
		int num;
	public:
		Test(const string & str="Just Testing",int n=0);
		~Test();
		void show() const;
};
#endif
