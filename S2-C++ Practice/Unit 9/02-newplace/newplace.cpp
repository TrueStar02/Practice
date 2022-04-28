#include<iostream>
#include<new>
using namespace std;
char buffer[512];
int main()
{	double *pd1,*pd2,*pd3,*pd4;
	int x;
	pd1=new double[5];
	pd2=new (buffer) double[5];
	cout<<"Address"<<endl;
	cout<<"Heap:"<<pd1<<" Buffer:"<<pd2<<endl<<endl;
	for(x=0;x<5;x++)
		pd1[x]=pd2[x]=10+1.00*x;
	for(x=0;x<5;x++)
	{	cout<<pd1[x]<<" at "<<pd1+x<<"   ";
		cout<<pd2[x]<<" at "<<pd2+x<<endl;
	}
	cout<<endl;
	pd3=new double[5];
	pd4=new (buffer) double[5];
	for(x=0;x<5;x++)
		pd3[x]=pd4[x]=20+1.00*x;
	for(x=0;x<5;x++)
	{	cout<<pd3[x]<<" at "<<pd3+x<<"   ";
		cout<<pd4[x]<<" at "<<pd4+x<<endl;
	}
	delete [] pd1;
	cout<<endl;
	pd1=NULL;
	pd1=new double[5];
	pd2=new (buffer+5*sizeof(double)) double[5];
	for(x=0;x<5;x++)
		pd1[x]=pd2[x]=30+1.00*x;
	for(x=0;x<5;x++)
	{	cout<<pd1[x]<<" at "<<pd1+x<<"   ";
		cout<<pd2[x]<<" at "<<pd2+x<<endl;
	}
	delete [] pd1;
	delete [] pd3;
	return 0;
}
