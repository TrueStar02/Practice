#include<iostream>
#include<vector>
#include<queue>
using namespace std;
static unsigned long Next = 1;
int t;
int myrand(void) 
{
    Next = Next * 1103515245 + 12345;
    return((unsigned)(Next/65536) % 32768);
}
struct edge
{	int next;
	double w;
	int D;
	edge(int n0,double w0,int D0):next(n0),w(w0),D(D0){}
};
struct purse
{	int time;
	double w;
	purse(int t0,double w0):time(t0),w(w0){}
};
struct comp
{
	bool operator()(const purse & p1,const purse & p2){return p1.time>p2.time;}
};
struct Node
{	double u;
	double v;
	double a;
	double b;
	double c;
	double d;
	int r;
	double dt;
	int count;
	vector<edge> adj;
	priority_queue<purse,vector<purse>,comp> plist;
	void addpurse(const purse & p){plist.push(p);}
	void update(Node * nodes)
	{	double utemp=u;
		double vtemp=v;
		v=vtemp+dt*(0.04*vtemp*vtemp+5*vtemp+140-utemp);
		u=utemp+dt*a*(b*vtemp-utemp);
		while(plist.size()&&plist.top().time==t)
		{	v+=plist.top().w;
			plist.pop();
		}
		if(v>30)
		{	int x;
			for(x=0;x<adj.size();x++)
			{	nodes[adj[x].next].addpurse(purse(t+adj[x].D,adj[x].w));
				
			}
			v=c;
			u+=d;
			count++;
		}
	}
	void outpurse(Node * nodes)
	{	int rd=myrand();
		if(rd<r)
		{	int x;
			for(x=0;x<adj.size();x++)
			{	nodes[adj[x].next].addpurse(purse(t+adj[x].D,adj[x].w));
				
			}
			count++;
		}
	}
	
};
double minv(Node * nodes,int beg,int end)
{	if(beg==end)
		return nodes[beg].v;
	int mid=(end+beg)/2;
	double left=minv(nodes,beg,mid);
	double right=minv(nodes,mid+1,end);
	return (left>right)?right:left;	
}
double maxv(Node * nodes,int beg,int end)
{	if(beg==end)
		return nodes[beg].v;
	int mid=(end+beg)/2;
	double left=maxv(nodes,beg,mid);
	double right=maxv(nodes,mid+1,end);
	return (left<right)?right:left;	
}
int minc(Node * nodes,int beg,int end)
{	if(beg==end)
		return nodes[beg].count;
	int mid=(end+beg)/2;
	int left=minc(nodes,beg,mid);
	int right=minc(nodes,mid+1,end);
	return (left>right)?right:left;	
}
int maxc(Node * nodes,int beg,int end)
{	if(beg==end)
		return nodes[beg].count;
	int mid=(end+beg)/2;
	int left=maxc(nodes,beg,mid);
	int right=maxc(nodes,mid+1,end);
	return (left<right)?right:left;	
	
}
int main()
{	int N,S,P,T;
	cin>>N>>S>>P>>T;
	Node neural[N+P];
	double dt;
	cin>>dt;
	int rn;
	double u,v,a,b,c,d;
	int x,sum=0;
	while(sum<N)
	{	cin>>rn>>v>>u>>a>>b>>c>>d;
		for(x=0;x<rn;x++)
		{	neural[sum+x].u=u;
			neural[sum+x].v=v;
			neural[sum+x].a=a;
			neural[sum+x].b=b;
			neural[sum+x].c=c;
			neural[sum+x].d=d;
			neural[sum+x].dt=dt;
			neural[sum+x].count=0;
		}	
		sum+=rn;
	}
	int r;
	for(x=N;x<N+P;x++)
	{	cin>>r;
		neural[x].r=r;
	}
	int start,end,D;
	double w;
	for(x=0;x<S;x++)
	{	cin>>start>>end>>w>>D;
		neural[start].adj.push_back(edge(end,w,D));
	}	
	for(t=1;t<=T;t++)
	{	for(x=0;x<N;x++)
			neural[x].update(neural);
		for(x=N;x<N+P;x++)
			neural[x].outpurse(neural);
		/*for(x=0;x<N;x++)
		{	cout<<neural[x].v<<" "<<neural[x].count<<endl;
	
		}*/
		
	}
	cout.setf(ios_base::fixed,ios_base::floatfield);
	cout.precision(3);
	cout<<minv(neural,0,N-1)<<" "<<maxv(neural,0,N-1)<<"\n";
	cout.unsetf(ios_base::floatfield);
	cout<<minc(neural,0,N-1)<<" "<<maxc(neural,0,N-1)<<"\n";
	return 0;
}