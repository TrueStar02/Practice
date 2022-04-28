#include<vector>
#include<stack> 
#include<string>
#include<vector>
#include<iostream>
using namespace std;
const int inf=1024*1024*1024;
class IPQ
{	private:
		vector<int>	index;
		vector<int> heap;
		vector<int> ele;
		void Sink(int beg,int end);
		void Swim(int beg,int end);
	public:
		IPQ(){heap.push_back(0);index.resize(100,0);ele.resize(100,inf);}
		void change(int s,int i);
		bool empty(void){return heap.size()==1;} 
		int size(void) const{return heap.size()-1;}
		bool push(const int & s,int i);
		int pop(int & index);
		bool contains(int i){return ele[i]!=inf;}
		void Debug()
		{	int x;
			for(x=1;x<heap.size();x++)
				cout<<heap[x]<<" "<<index[heap[x]]<<" "<<ele[heap[x]]<<endl;
		}	
};
void IPQ::Sink(int beg,int end)
{	int x;
	heap[0]=heap[beg];
	for(x=beg*2;x<=end;x*=2)
	{	if(x<end&&ele[heap[x]]>ele[heap[x+1]])
			x++;
		if(ele[heap[0]]<=ele[heap[x]])
			break;
		heap[beg]=heap[x];
		index[heap[x]]=beg;
		beg=x;
	}
	heap[beg]=heap[0];
	index[heap[beg]]=beg;
}
void IPQ::Swim(int beg,int end)
{	int x;
	heap[0]=heap[end];
	for(x=end/2;x>=1;x/=2)
	{	if(ele[heap[0]]>=ele[heap[x]])
			break;
		heap[end]=heap[x];
		index[heap[x]]=end;
		end=x;
	}
	heap[end]=heap[0];
	index[heap[end]]=end;
}
void IPQ::change(int s,int i)
{	ele[i]=s;
	if(index[i]>1&&ele[i]<ele[heap[index[i]/2]])
		Swim(1,index[i]);
	else
		Sink(index[i],heap.size()-1);
}
bool IPQ::push(const int & s,int i)
{	if(index[i])
		return 0;
	heap.push_back(i);
	if(i>index.size()-1)
	{	index.resize(i+1,0);
		ele.resize(i+1,inf);
	}
	index[i]=heap.size()-1;
	ele[i]=s;
	Swim(1,heap.size()-1);
	return 1;
}
int IPQ::pop(int & i)
{	if(heap.size()==1)
		return inf;
	i=heap[1];
	int s=ele[heap[1]];
	index[heap[1]]=0;
	ele[heap[1]]=inf;
	heap[1]=heap[heap.size()-1];
	if(heap.size()!=2)
		index[heap[1]]=1;
	heap.erase(heap.end()-1);
	if(heap.size()!=1)
		Sink(1,heap.size()-1);
	return s;
}
class Graph
{   private:
        int **edge;
        bool *label;
        int *adjvex;
        int *dist;
        int v;
        IPQ idx_pri_q;
        vector<pair<int,int> > mst;
        bool RelaxEdge(int a,int b);
        void RelaxVertex(int ver);
    public:
        Graph(int v);
        bool AddEdge(int a,int b,int weight=1);
        void PrintMatrix(void);
        vector<pair<int,int> > Dijkstra(int start);
};
bool Graph::RelaxEdge(int a,int b)
{   if(dist[b]>edge[a][b]+dist[a])
    {   dist[b]=edge[a][b]+dist[a];
        adjvex[b]=a;
        if(idx_pri_q.contains(b))
            idx_pri_q.change(dist[b],b);
        else
            idx_pri_q.push(dist[b],b);
        return 1;
    }
    return 0;
}

void Graph::RelaxVertex(int ver)
{   int x;
    for(x=0;x<v;x++)
        if(!label[x]&&edge[ver][x]!=inf)
            RelaxEdge(ver,x);
}

Graph::Graph(int ver):v(ver)
{   edge=new int*[v];
	int x,y;
	for(x=0;x<v;x++)
		edge[x]=new int[v];
	label=new bool[v];
	dist=new int[v];
	adjvex=new int[v];
    for(x=0;x<v;x++)
    for(y=0;y<v;y++)
    {   if(x==y)
            edge[x][y]=0;
        else
            edge[x][y]=inf;
    }
}
bool Graph::AddEdge(int a,int b,int weight)
{   if(a<0||a>=v||b<0||b>=v||a==b||edge[a][b]!=inf)
        return 0;
    edge[a][b]=weight;
    return 1;
}
void Graph::PrintMatrix(void)
{   int x,y;
    for(x=0;x<v;x++)
    {   for(y=0;y<v;y++)
        {   if(edge[x][y]==inf)
                cout<<"X ";
            else
                cout<<edge[x][y]<<" ";
        }
        cout<<endl;
    }
}
vector<pair<int,int> > Graph::Dijkstra(int start)
{   int x,y,index;
    mst.clear();
    for(x=0;x<v;x++)
    {   dist[x]=edge[start][x];
        label[x]=0;
        adjvex[x]=start;   
        if(x!=start&&edge[start][x]!=inf)
            idx_pri_q.push(edge[start][x],x);
    }
    label[start]=1;
    adjvex[start]=-1;       
    while(idx_pri_q.size())
    {   idx_pri_q.pop(index);
        label[index]=1;
        RelaxVertex(index);
    }
    for(x=0;x<v;x++)
        mst.push_back(pair<int,int>(adjvex[x],dist[x]));
    return mst;
}
int main()
{   int tasks,start;
	cin>>tasks;
    int x,y,z,v,e,a,b,w;
    for(z=0;z<tasks;z++)
    {	cin>>v>>e;
    	Graph g(v);
    	for(x=0;x<e;x++)
    	{   cin>>a>>b>>w;
   	     	g.AddEdge(a-1,b-1,w);
   		}
   		cin>>start;
    	vector<pair<int,int> > mst=g.Dijkstra(start-1);
    	for(x=0;x<mst.size();x++)
    		if(mst[x].second!=inf)
    	    	cout<<start<<"-"<<x+1<<":"<<mst[x].second<<endl; 
	}
    return 0;
}
