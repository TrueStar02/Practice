#include "student.h"
int main(void)
{	int x,y;
	Student stu[3]={Student(5),Student(5),Student(5)};
	for(x=0;x<3;x++)
	{	cout<<"Student "<<x<<":\n";
		cout<<"Name:";
		cin>>stu[x];
		cout<<"Score:";
		for(y=0;y<=4;y++)
			cin>>stu[x][y];
		while(cin.get()!='\n')
			continue;
	}
	for(x=0;x<3;x++)
	{	cout<<stu[x];
		cout<<"Average:"<<stu[x].Average()<<endl;
	}
	return 0;
}
