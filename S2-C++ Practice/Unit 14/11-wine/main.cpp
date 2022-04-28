#include "wine.h"
int main(void)
{	cout<<"Enter the name:";
	char name[51];
	cin.getline(name,51);
	int n;
	cout<<"Enter number of years:";
	cin>>n;
	Wine holding(name,n);
	holding.GetBottles();
	holding.Show();
	int y[3]={1993,1995,1998};
	int b[3]={48,60,72};
	Wine more("NB",3,y,b);
	more.Show();
	cout<<"Total of "<<more.Label()<<":"<<more.sum()<<endl;
	return 0;
}
