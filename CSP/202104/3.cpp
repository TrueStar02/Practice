#include<iostream>
using namespace std;
class Addr
{	public:
		string posi;
		int badtime;
		int situ;//0-no 1-wait 2-pos 3-old
};
int main()
{	int n,tdef,tmax,tmin,tasks,x,y;
	string name;
	cin>>n>>tdef>>tmax>>tmin>>name>>tasks;
	Addr ap[n+1];
	for(x=1;x<=n;x++)
	{	ap[x].posi="";
		ap[x].badtime=0;
		ap[x].situ=0;
	}
	int time,ip,offset,tar;
	string from,to,req;
	for(x=0;x<tasks;x++)
	{	tar=0;
		cin>>time>>from>>to>>req>>ip>>offset;
		if(to!="*"&&to!=name) continue;
		if(req!="DIS"&&req!="REQ") continue;
		if(to=="*"&&req!="DIS") continue;
		if(to==name&&req!="REQ") continue;
		for(y=1;y<=n;y++)
			if((ap[y].situ==1||ap[y].situ==2)&&ap[y].badtime<=time)
			{	ap[y].badtime=0;
				if(ap[y].situ==1)
				{	ap[y].situ=0;
					ap[y].posi="";
				}
				else
					ap[y].situ=3;
			}
		if(req=="DIS")
		{	for(y=1;y<=n;y++)
				if(ap[y].posi==from)
				{	tar=y;
					break;
				}
			if(!tar)
				for(y=1;y<=n;y++)
				if(ap[y].situ==0)
				{	tar=y;
					break;
				}
			if(!tar)
			{	for(y=1;y<=n;y++)
				if(ap[y].situ==3)
				{	tar=y;
					break;
				}
			}
			if(!tar)
				continue;
			ap[tar].situ=1;
			ap[tar].posi=from;
			if(offset)
			{	if(offset>time+tmax)
					ap[tar].badtime=time+tmax;
				else if(offset<time+tmin)
					ap[tar].badtime=time+tmin;
				else
					ap[tar].badtime=offset;
			}
			else
				ap[tar].badtime=time+tdef;
			cout<<name<<" "<<ap[tar].posi<<" OFR "<<tar<<" "<<ap[tar].badtime<<endl;
		}
		else if(req=="REQ")
		{	if(to!=name)
			{	for(y=1;y<=n;y++)
					if(ap[y].posi==from&&ap[y].situ==1)
					{	ap[y].situ=0;
						ap[y].badtime=0;
						ap[y].posi="";
					}	
				continue;
			}
			if(ip>n||(ap[ip].posi!=from))
			{	cout<<name<<" "<<from<<" NAK "<<ip<<" "<<0<<endl;
				continue;
			}
			ap[ip].situ=2;
			if(offset)
			{	if(offset>time+tmax)
					ap[ip].badtime=time+tmax;
				else if(offset<time+tmin)
					ap[ip].badtime=time+tmin;
				else
					ap[ip].badtime=offset;
			}
			else
				ap[ip].badtime=time+tdef;
			cout<<name<<" "<<from<<" ACK "<<ip<<" "<<ap[ip].badtime<<endl;
		}
	}
	return 0;
}