#include<iostream>
#include<queue>
using namespace std;
const int inf=1024*1024*024;
class Graph
{   private:
        int v;
        int e;
        int ** edge;
        bool * label;
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
            e=0;
        }
        void AddEdge(int a,int b)
        {   edge[a][b]=edge[b][a]=1;
            e++;
        }
        bool isTree(void)
        {   if(e!=v-1)return 0;
            queue<int> q;
            int x,temp;
            for(x=0;x<v;x++)
				label[x]=0;
            label[0]=1;
            q.push(0);
            while(q.size())
            {   temp=q.front();
                q.pop();
                for(x=0;x<v;x++)
                    if(!label[x]&&edge[temp][x]!=inf)
                    {   q.push(x);
                        label[x]=1;
                    }
            }
            for(x=0;x<v;x++)
                if(!label[x])
                    return 0;
            return 1;
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
        if(g.isTree())
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
	return 0;
}