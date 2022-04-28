#include<iostream>
#include<vector>
using namespace std;
struct runner
{	unsigned long strength;
	unsigned int enter;
	unsigned int kick;	
	runner(unsigned long s,int e):strength(s),enter(e),kick(0){}
};
int main()
{	int m,i,j,count;
	unsigned long p,A=0;
	bool T;
	cin>>m>>p>>T;
	int mode;
	unsigned long x,s,l,r,y;
	vector<runner> vec;
	for(i=1;i<=m;i++)
	{	cin>>mode;
		switch(mode)
		{	case 1:
			{	cin>>x;
				if(T)
					x^=A;
				if(x)
					vec.push_back(runner(x,i));
				else
					vec.back().kick=i;	
			}
			break;
			case 2:
			{	cin>>s>>l>>r>>y;
				if(T)
					y^=A;
				for(j=0,count=0;j<vec.size();j++)
				{	if(s>=vec[j].enter&&(vec[j].kick==0||s<=vec[j].kick))
					{
							count++;
					if(count>=l&&count<=r)
						vec[j].strength*=y;
					else if(count>r)
						break;
					}
				}
			}
			break;
			case 3:
			{	cin>>s>>l>>r;
				A=0;
				for(j=0,count=0;j<vec.size();j++)
				{	if(s>=vec[j].enter&&(vec[j].kick==0||s<=vec[j].kick))
					{
							count++;
					if(count>=l&&count<=r)
					{
							A+=(vec[j].strength%p);
							A%=p;
					}
					else if(count>r)
						break;
					}
				}
				cout<<A<<"\n";
			}
			break;
		}
		//for(x=0;x<vec.size();x++)
			//cout<<vec[x].strength<<" "<<vec[x].enter<<" "<<vec[x].kick<<endl;
	}
	return 0;
}