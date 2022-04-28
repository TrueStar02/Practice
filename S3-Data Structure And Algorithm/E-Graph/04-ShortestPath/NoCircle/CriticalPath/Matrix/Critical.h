#ifndef CRITICAL_H_
#define CRITICAL_H_
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
const int inf=256*1024*1024;
class Graph
{   private:
        int **edge;
        int *adjvex;
        int *dist;
        bool *label;
        bool *onStack;
        int v;
        stack<int> rev_post_order;
        vector<int> topo_order;
        vector<pair<int,int>> mst;
        bool cyclefunc(int ver);
        void orderfunc(int ver);
        bool RelaxEdge(int a,int b);
        void RelaxVertex(int ver);
    public:
        Graph(int ver);
        Graph(const Graph & g)=delete;
        Graph(Graph && g)=delete;
        Graph & operator=(const Graph & g)=delete;
        Graph & operator=(Graph && g)=delete;
        ~Graph();
        bool AddEdge(int a,int b,int weight=1);
        void PrintMatrix(void);
        bool hasCycle(void);
        vector<pair<int,int>> Critical();
};
bool Graph::cyclefunc(int ver)
{   onStack[ver]=1;
    label[ver]=1;
    int x;
    for(x=0;x<v;x++)
        if(x!=ver&&edge[ver][x]!=-inf)
            if(onStack[x]||!label[x]&&cyclefunc(x))
                return 1;
    onStack[ver]=0;
    return 0;
}
void Graph::orderfunc(int ver)
{   label[ver]=1;
    int x;
    for(x=0;x<v;x++)
        if(!label[x]&&edge[ver][x]!=-inf)
            orderfunc(x);
    rev_post_order.push(ver);
}
bool Graph::RelaxEdge(int a,int b)
{   if(dist[b]<dist[a]+edge[a][b])
    {   dist[b]=dist[a]+edge[a][b];
        adjvex[b]=a;
        return 1;
    }
    return 0;
}
void Graph::RelaxVertex(int ver)
{   int x;
    for(x=0;x<v;x++)
        if(ver!=x&&edge[ver][x]!=-inf)
            RelaxEdge(ver,x);
}
Graph::Graph(int ver):v(ver)
{   edge=new int*[v];
    adjvex=new int[v];
    dist=new int[v];
    label=new bool[v];
    onStack=new bool[v];
    int x,y;
    for(x=0;x<v;x++)
    {   edge[x]=new int[v];
        for(y=0;y<v;y++)
            if(x==y)
                edge[x][y]=0;
            else
                edge[x][y]=-inf;
    }
}
Graph::~Graph()
{   int x;
    for(x=0;x<v;x++)
        delete [] edge[x];
    delete [] edge;
    delete [] adjvex;
    delete [] dist;
    delete [] label;
    delete [] onStack;
}
bool Graph::AddEdge(int a,int b,int weight)
{   if(a<0||a>=v||b<0||b>=v||a==b||edge[a][b]!=-inf)
        return 0;
    edge[a][b]=weight;
    return 1;
}
void Graph::PrintMatrix(void)
{   int x,y;
    for(x=0;x<v;x++)
    {   for(y=0;y<v;y++)
        {   if(edge[x][y]==-inf)
                cout<<"X ";
            else
                cout<<edge[x][y]<<" ";
        }
        cout<<endl;
    }

}
bool Graph::hasCycle(void)
{   int x;
    for(x=0;x<v;x++)
    {   onStack[x]=0;
        label[x]=0;
    }
    for(x=0;x<v;x++)
        if(!label[x]&&cyclefunc(x))
            return 1;
    return 0;
}
vector<pair<int,int>> Graph::Critical()
{   int x,y;
    int tasks=v/2-1;
    topo_order.clear();
    rev_post_order=stack<int>();
    mst.clear();
    for(x=0;x<v;x++)
    {   label[x]=0;
        dist[x]=-inf;
        adjvex[x]=2*tasks;
    }
    for(x=0;x<v;x++)
            if(!label[x])
                orderfunc(x);
    if(!hasCycle())
    {   while(rev_post_order.size())
        {   topo_order.push_back(rev_post_order.top());
            rev_post_order.pop();
        }
        dist[tasks*2]=0;
        adjvex[tasks*2]=-1;
        for(x=0;x<v;x++)
            RelaxVertex(topo_order[x]);
        for(x=0;x<v;x++)
            mst.push_back(pair<int,int>(adjvex[x],dist[x]));
    }
    return mst;
}
#endif