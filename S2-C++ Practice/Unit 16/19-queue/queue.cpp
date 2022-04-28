#include<queue>
#include<iostream>
#include<algorithm>
#include<iterator>
#include<cstdlib>
#include<ctime>
using namespace std;
class Customer
{	public:
		int arrive;
		int time;
		explicit Customer(int arr):arrive(arr),time(rand()%3+1){}
};
int main()
{	srand((unsigned int)time(0));
	queue<Customer> q;
	int x,accepted=0,served=0,turnaway=0,tot_wait=0,hours,per_hour,wait_time=0,tot_len,max;
	cout<<"Enter the time:";
	cin>>hours;
	cout<<"Enter how many customers per hour:";
	cin>>per_hour;
	cout<<"Enter the max size of the queue:";
	cin>>max;
	for(x=1;x<=60*hours;x++)
	{	if(rand()%60<per_hour)
		{	if(q.size()==max)
				turnaway++;
			else
			{	q.push(Customer(x));
				accepted++;
			}	
		}
		if(q.size()&&wait_time==0)
		{	served++;
			wait_time=q.front().time;
			tot_wait+=x-q.front().arrive;
			q.pop();
		}
		if(wait_time)
			wait_time--;
		tot_len+=q.size();
	}
	cout<<"Customers accepted:"<<accepted<<endl;
	cout<<"Customers served:"<<served<<endl;
	cout<<"Customers turned-away:"<<turnaway<<endl;
	cout<<"Average queue size:"<<(double)tot_len/(60*hours)<<endl;
	cout<<"Average waiting time:"<<(double)tot_wait/accepted<<endl;
	return 0;
}
