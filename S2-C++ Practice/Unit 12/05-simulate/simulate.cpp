#include<cstdlib>
#include<ctime>
#include "queue.h"
int main(void)
{	int t,max,fre,x,wait=0;
	srand((unsigned int)time(0));
	cout<<"Simulation:\n";
	cout<<"Simulation Hours:";
	cin>>t;
	cout<<"Maxium size of the queue:";
	cin>>max;
	cout<<"Average number of cuntomers per hour:";
	cin>>fre;
	Queue line(max);
	Item temp;
	long joined=0,served=0,turnaway=0,tot_size=0,tot_wait=0;
	for(x=1;x<=t*60;x++)
	{	if(rand()%60<fre)
		{	temp.arrive=x;
			temp.time=rand()%3+1;
			if(line.isfull())
				turnaway++;
			else
			{	joined++;
				line.enqueue(temp);
			}
		}
		if(!line.isempty()&&wait==0)
		{	line.dequeue(temp);
			wait=temp.time;
			tot_wait+=x-temp.arrive;
			served++;
		}
		tot_size+=line.count();
		if(wait)
			wait--;
	}
	if(joined)
	{	cout<<"customers accepted: "<<joined<<endl;
        cout<<"  customers served: "<<served<<endl;
        cout<< "         turnaways: "<<turnaway<<endl;
        cout<< "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) tot_size /(t*60)<< endl;
        cout << " average wait time: "<< (double) tot_wait / served << " minutes\n";
	}
	else
		cout<<"No Customers!\n";
	cout<<"Bye~";
	return 0;
}
