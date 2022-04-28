#include<iostream>
using namespace std;
void subdivide(char *str,int low,int high,int level);
int main(void)
{	char str[130];
	int x,y;
	for(x=1;x<=127;x++)
		str[x]=' ';
	str[0]=str[128]='|';
	str[129]='\0';
	for(y=0;y<=7;y++)
	{	subdivide(str,0,128,y);
		cout<<str<<endl;
		for(x=1;x<=127;x++)
			str[x]=' ';
	}
	return 0;
}
void subdivide(char *str,int low,int high,int level)
{	if(level>0)
	{	int mid=(low+high)/2;
		str[mid]='|';
		subdivide(str,low,mid,level-1);
		subdivide(str,mid,high,level-1);
	}
}
