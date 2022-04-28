#include<iostream>
#include<sstream>
using namespace std;
int main()
{	string temp,str="Black Lives Matter Zero-dollar Purchasing Festival!";
	istringstream strin(str);
	while(strin>>temp)
		cout<<temp<<endl;
	return 0;
}
