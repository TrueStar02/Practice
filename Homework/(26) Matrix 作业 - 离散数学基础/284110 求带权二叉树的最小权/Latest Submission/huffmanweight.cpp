#include<iostream>
#include<queue>
using namespace std;
int main()
{   priority_queue<int,vector<int>,greater<int> > pri_q;
    int n,m,w,x,sum,y,p,q;
    cin>>n;
    char v1,v2,v3;
    for(x=0;x<n;x++)
    {   cin>>m;
    	sum=0;
    	for(y=0;y<m;y++)
    	{	cin>>v1>>v2>>w;
			pri_q.push(w);    		
		}
		while(pri_q.size()!=1)
		{	p=pri_q.top();
			pri_q.pop(); 
			q=pri_q.top();
			pri_q.pop();
			pri_q.push(p+q);  
			sum+=p+q;	
		}
        cout<<sum<<endl;
        pri_q.pop();
    }
	return 0;

}