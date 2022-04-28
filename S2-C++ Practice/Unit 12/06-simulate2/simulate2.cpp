#include<cstdlib>
#include<ctime>
#include "queue.h"
int main(void)
{	int t,max,fre,x,l,y,flag,flagt=11;
	srand((unsigned int)time(0));
	cout<<"Simulation:\n";
	cout<<"Simulation Hours:";
	cin>>t;
	cout<<"Number of queues:";
	cin>>l;
	cout<<"Maxium size of the queue:";
	cin>>max;
	cout<<"Average number of cuntomers per hour:";
	cin>>fre;
	int wait[l]={0};
	Queue line[l];
	for(y=0;y<l;y++)
		line[y]=Queue(max);
	Item temp;
	long joined=0,served=0,turnaway=0,tot_size=0,tot_wait=0;
	for(x=1;x<=t*60;x++)
	{	if(rand()%60<fre)
		{	temp.arrive=x;
			temp.time=rand()%5+1;
			flag=-1;
			flagt=99999;
			for(y=0;y<l;y++)
				if(!line[y].isfull()&&line[y].count()<flagt)
				{	flag=y;
					flagt=line[y].count();
				}
			if(flag==-1)
				turnaway++;
			else
			{	joined++;
				line[flag].enqueue(temp);
			}
		}
		for(y=0;y<l;y++)
		{	if(!line[y].isempty()&&wait[y]==0)
			{	line[y].dequeue(temp);
				wait[y]=temp.time;
				tot_wait+=x-temp.arrive;
				served++;
			}
			tot_size+=line[y].count();
			if(wait[y])
				wait[y]--;
		}
	}
	if(joined)
	{	cout<<"customers accepted: "<<joined<<endl;
        cout<<"  customers served: "<<served<<endl;
        cout<< "         turnaways: "<<turnaway<<endl;
        cout<< "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) tot_size /(t*60*l)<< endl;
        cout << " average wait time: "<< (double) tot_wait / served << " minutes\n";
	}
	else
		cout<<"No Customers!\n";
	cout<<"Bye~";
	return 0;
}
