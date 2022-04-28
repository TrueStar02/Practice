#include<iostream>
#include<stdexcept>
using namespace std;
class bad_hmean:public logic_error
{	public:
		explicit bad_hmean(const string & s="Input is invalid for harmonic mean!\n"):logic_error(s){}
};
class bad_gmean:public logic_error
{	public:
		explicit bad_gmean(const string & s="Input is invalid for geometric mean!\n"):logic_error(s){}
};

