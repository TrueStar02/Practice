#include "test.h"
Test::Test(const string & str,int n)
{	word=str;
	num=n;
	cout<<word<<" constructed\n";
}
Test::~Test()
{	cout<<word<<" destroyed\n";
}
void Test::show() const
{	cout<<word<<" "<<num<<endl;
}
