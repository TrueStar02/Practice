#include<iostream>
#include "golf.h"
#include<cstring>
using namespace std;
void setgolf(golf& g,const char* name,int hc)
{	strcpy(g.fullname,name);
	g.handicap=hc;
}
int setgolf(golf& g)
{	cout<<"Enter the name:";
	cin.getline(g.fullname,40);
	if(!strlen(g.fullname))
		return 0;
	cout<<"Enter the score:";
	cin>>g.handicap;
	cin.get();
		return 1;
}
void handicap(golf& g,int hc)
{	g.handicap=hc;
}
void showgolf(const golf& g)
{	cout<<g.fullname<<" "<<g.handicap<<endl;
}
