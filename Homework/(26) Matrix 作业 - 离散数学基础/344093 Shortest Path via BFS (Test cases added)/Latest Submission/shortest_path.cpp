#include<iostream>
#include<queue>
using namespace std;
const int inf=1024*1024*024;
class Graph
{   private:
        int v;
        int ** edge;
        bool * label;
        int count;
        int * dist;
    public:
        Graph(int v0):v(v0)
        {   int x,y;
            edge=new int*[v];
            for(x=0;x<v;x++)
            edge[x]=new int[v];
            for(x=0;x<v;x++)
            for(y=0;y<v;y++)
                if(x==y)
                    edge[x][y]=0;
                else
                    edge[x][y]=inf;
            label=new bool[v];
            dist=new int[v];
        }
        void AddEdge(int a,int b){edge[a][b]=1;}
        const int * BFS(int start)
        {   queue<int> q;
            count=0;
            int x,temp;
            for(x=0;x<v;x++)
            {	dist[x]=inf;
				label[x]=0;
			}
            label[start]=1;
            q.push(start);
            dist[start]=0;
            while(q.size())
            {   temp=q.front();
                q.pop();
                for(x=0;x<v;x++)
                    if(!label[x]&&edge[temp][x]!=inf)
                    {   q.push(x);
                        label[x]=1;
                        dist[x]=dist[temp]+1;
                    }
            }
            return dist;
        }
};
int main()
{   int tasks,x,y,v,e,a,b,start;
    cin>>tasks;
    for(x=0;x<tasks;x++)
    {   cin>>v>>e;
        Graph g(v);
        for(y=0;y<e;y++)
        {   cin>>a>>b;
            g.AddEdge(a-1,b-1);
        }
        cin>>start;
        const int * dist=g.BFS(start-1);
        for(y=0;y<v;y++)
        	if(dist[y]!=inf)
            cout<<start<<'-'<<y+1<<":"<<dist[y]<<endl;
    }
	return 0;
}