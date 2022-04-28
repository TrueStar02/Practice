#include "arraytp.h"
#include<ctime>
int main(void)
{	srand((unsigned int)time(0));
	ArrayTP<int,5> a1(7);
	ArrayTP<double,6> a2(6.16);
	int x,y,sum=0;
	for(x=0;x<5;x++)
		sum+=a1[x];
	cout<<"Sum of a1 is "<<sum<<endl;
	cout<<"Here is a2\n";
	for(x=0;x<6;x++)
		cout<<a2[x]<<" ";
	cout<<endl;
	ArrayTP<ArrayTP<int,8>,10> arr;
	for(x=0;x<10;x++)
	for(y=0;y<8;y++)
		arr[x][y]=rand()%99+1;
	cout<<"Two Dimension:\n";
	for(x=0;x<10;x++)
	{	for(y=0;y<8;y++)
		{	cout.width(3);
			cout<<arr[x][y];
		}
		cout<<endl;
	}
	return 0;
}
