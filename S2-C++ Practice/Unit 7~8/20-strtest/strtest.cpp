#include <iostream>
using namespace std;
#include <cstring>
struct stringy {
    char * str;
    int ct;
};
void set(stringy & ref,const char * cstr);
void show(const stringy sty,int n=1);
void show(const char * str,int n=1);
int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";

    set(beany, testing); 
    show(beany); 
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");
    delete [] beany.str;
    return 0;
}
void set(stringy & ref,const char * cstr)
{	ref.ct=strlen(cstr);
	ref.str=new char[ref.ct+1];
	strcpy(ref.str,cstr);
}
void show(const stringy sty,int n)
{	cout<<sty.str<<endl;
}
void show(const char * str,int n)
{	cout<<str<<endl;
}
