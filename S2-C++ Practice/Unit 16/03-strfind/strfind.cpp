#include<iostream>
using namespace std;
int main(void)
{	string t("isnrjdnfidfnfisnhuishfeicuisn");
	string f("isn");
	char *str="fi";
	int pos;
	pos=t.find(96+9);
	cout<<pos<<endl;
	pos=t.find(f);
	cout<<pos<<endl;
	pos=t.rfind(str);
	cout<<pos<<endl;
	pos=t.find_first_of("jfe");
	cout<<pos<<endl;
	pos=t.find_first_not_of("isnjd");
	cout<<pos<<endl;
	pos=t.find(str,15,2);
	cout<<pos<<endl;
	pos=t.find(f,5);
	cout<<pos<<endl;
	return 0;
}
